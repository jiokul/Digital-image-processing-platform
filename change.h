

// 限制输出像素值范围
template<class F>
inline F TP_LimitNum(F x, F xmin, F xmax)
{
	x = (x > xmin ? x : xmin);
	x = (x < xmax ? x : xmax);
	return x;
}

//======================================
// inPtr 输入数据指针，unsigned char类型
// outPtr 输出数据指针，unsigned char类型，component size为4
// ncols 图像列数（宽）
// nrows 图像行数（高）
// numComp 输入数据component size值，可以理解为通道数（R/G/B/A）
//======================================
inline void ConvertVtkImageToRGBA(const unsigned char* inPtr,unsigned char* outPtr,int ncols,int nrows,int numComp)
{
	const int vmin = 0;
	const int vmax = 255;
	unsigned char alpha = 255;

	int inIncX = numComp;

	// loop through the data and copy it for the texture
	if (numComp == 1)
	{
		for (int idy = 0; idy < nrows; idy++)
		{
			for (int idx = 0; idx < ncols; idx++)
			{
				// Pixel operation
				int val = inPtr[0];
				val = TP_LimitNum(val, vmin, vmax);
				unsigned char cval = static_cast<unsigned char>(val + 0.5);
				outPtr[0] = cval;
				outPtr[1] = cval;
				outPtr[2] = cval;
				outPtr[3] = alpha;
				outPtr += 4;
				inPtr += inIncX;
			}
		}
	}
	else if (numComp == 2)
	{
		for (int idy = 0; idy < nrows; idy++)
		{
			for (int idx = 0; idx < ncols; idx++)
			{
				// Pixel operation
				int val = inPtr[0];
				val = TP_LimitNum(val, vmin, vmax);
				unsigned char cval = static_cast<unsigned char>(val + 0.5);
				val = inPtr[1];
				val = TP_LimitNum(val, vmin, vmax);
				unsigned char aval = static_cast<unsigned char>(val + 0.5);
				outPtr[0] = cval;
				outPtr[1] = cval;
				outPtr[2] = cval;
				outPtr[3] = aval;
				outPtr += 4;
				inPtr += inIncX;
			}
		}
	}
	else if (numComp == 3)
	{
		for (int idy = 0; idy < nrows; idy++)
		{
			for (int idx = 0; idx < ncols; idx++)
			{
				// Pixel operation
				int r = inPtr[0];
				int g = inPtr[1];
				int b = inPtr[2];
				r = TP_LimitNum(r, vmin, vmax);
				g = TP_LimitNum(g, vmin, vmax);
				b = TP_LimitNum(b, vmin, vmax);
				outPtr[0] = static_cast<unsigned char>(r + 0.5);
				outPtr[1] = static_cast<unsigned char>(g + 0.5);
				outPtr[2] = static_cast<unsigned char>(b + 0.5);
				outPtr[3] = alpha;
				outPtr += 4;
				inPtr += inIncX;
			}
		}
	}
	else // if (numComp == 4)
	{
		for (int idy = 0; idy < nrows; idy++)
		{
			for (int idx = 0; idx < ncols; idx++)
			{
				// Pixel operation
				int r = inPtr[0];
				int g = inPtr[1];
				int b = inPtr[2];
				int a = inPtr[3];
				r = TP_LimitNum(r, vmin, vmax);
				g = TP_LimitNum(g, vmin, vmax);
				b = TP_LimitNum(b, vmin, vmax);
				a = TP_LimitNum(a, vmin, vmax);
				outPtr[0] = static_cast<unsigned char>(r + 0.5);
				outPtr[1] = static_cast<unsigned char>(g + 0.5);
				outPtr[2] = static_cast<unsigned char>(b + 0.5);
				outPtr[3] = static_cast<unsigned char>(a + 0.5);
				outPtr += 4;
				inPtr += inIncX;
			}
		}
	}
}

inline QImage getqimage(vtkImageData* imageData)
{
	int ncols = imageData->GetDimensions()[0]; // 图像列数（宽）
	int nrows = imageData->GetDimensions()[1]; // 图像行数（高）
	// 获取原图像数据的灰度值范围
	double range[2];
	imageData->GetScalarRange(range);
	// 将原图像灰度值调节到0~255范围内，输出为unsigned char（0~255）类型数据（即调节窗宽窗位）
	vtkImageShiftScale* shifter = vtkImageShiftScale::New();
	shifter->SetShift(-1.0 * range[0]); //减去最小值
	shifter->SetScale(255.0 / (range[1] - range[0])); //设置缩放值调节比例，灰度换算公式：255*X/(range[1]-range[0])
	shifter->SetOutputScalarTypeToUnsignedChar();
	shifter->SetInputData(imageData);
	shifter->Update();
	// 获取原图像component size值，即通道数
	int numComp = shifter->GetOutput()->GetScalarSize();
	// 申请内存
	unsigned char* inPtr = static_cast<unsigned char*>(shifter->GetOutput()->GetScalarPointer()); // 输入，从图像中获取数据指针
	unsigned char* outPtr = new unsigned char[nrows * ncols * 4]; // 输出，RGBA共4通道，所以这里乘4
	ConvertVtkImageToRGBA(inPtr, outPtr, ncols, nrows, numComp);
	// 创建QImage，理论上可以用outPtr创建任意其它类型图像
	QImage image = QImage(outPtr, ncols, nrows, QImage::Format_RGB32);
	return image;
}
#pragma once
