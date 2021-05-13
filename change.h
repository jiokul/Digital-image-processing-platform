

// �����������ֵ��Χ
template<class F>
inline F TP_LimitNum(F x, F xmin, F xmax)
{
	x = (x > xmin ? x : xmin);
	x = (x < xmax ? x : xmax);
	return x;
}

//======================================
// inPtr ��������ָ�룬unsigned char����
// outPtr �������ָ�룬unsigned char���ͣ�component sizeΪ4
// ncols ͼ����������
// nrows ͼ���������ߣ�
// numComp ��������component sizeֵ���������Ϊͨ������R/G/B/A��
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
	int ncols = imageData->GetDimensions()[0]; // ͼ����������
	int nrows = imageData->GetDimensions()[1]; // ͼ���������ߣ�
	// ��ȡԭͼ�����ݵĻҶ�ֵ��Χ
	double range[2];
	imageData->GetScalarRange(range);
	// ��ԭͼ��Ҷ�ֵ���ڵ�0~255��Χ�ڣ����Ϊunsigned char��0~255���������ݣ������ڴ���λ��
	vtkImageShiftScale* shifter = vtkImageShiftScale::New();
	shifter->SetShift(-1.0 * range[0]); //��ȥ��Сֵ
	shifter->SetScale(255.0 / (range[1] - range[0])); //��������ֵ���ڱ������ҶȻ��㹫ʽ��255*X/(range[1]-range[0])
	shifter->SetOutputScalarTypeToUnsignedChar();
	shifter->SetInputData(imageData);
	shifter->Update();
	// ��ȡԭͼ��component sizeֵ����ͨ����
	int numComp = shifter->GetOutput()->GetScalarSize();
	// �����ڴ�
	unsigned char* inPtr = static_cast<unsigned char*>(shifter->GetOutput()->GetScalarPointer()); // ���룬��ͼ���л�ȡ����ָ��
	unsigned char* outPtr = new unsigned char[nrows * ncols * 4]; // �����RGBA��4ͨ�������������4
	ConvertVtkImageToRGBA(inPtr, outPtr, ncols, nrows, numComp);
	// ����QImage�������Ͽ�����outPtr����������������ͼ��
	QImage image = QImage(outPtr, ncols, nrows, QImage::Format_RGB32);
	return image;
}
#pragma once
