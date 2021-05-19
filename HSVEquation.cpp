#include "HSVEquation.h"
#include <string.h>
#include <QDebug>
#include "vtkCallbackCommand.h"
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageToVTKImageFilter.h"
#include "vtkImageViewer.h"
#include "vtkWin32RenderWindowInteractor.h"
#include "itkResampleImageFilter.h"//采样
#include "itkBinaryThresholdImageFilter.h"//二值化
#include "itkThresholdImageFilter.h"//阈值分割
#include "itkBinaryBallStructuringElement.h"
#include "itkBinaryMorphologicalOpeningImageFilter.h"//开运算
#include "itkMultiplyImageFilter.h"//乘法
#include "itkAndImageFilter.h"//与
#include "itkImageFileWriter.h"
#include "itkCastImageFilter.h"
#include <iostream>
#include <string>
#include "itkRescaleIntensityImageFilter.h"
#include "itkConnectedComponentImageFilter.h"//连通域
#include "itkLabelToRGBImageFilter.h"//彩色
#include "itkConnectedThresholdImageFilter.h"
#include "vtkImageShiftScale.h"
#include "change.h"
#include "Qsave.h"
using namespace std;
typedef struct HSV {
	float h;
	float s;
	float v;
}hsv;
HSVEquation::HSVEquation(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(save()));
}

HSVEquation::~HSVEquation()
{
}

void HSVEquation::RGBtoHSV(float r, float g, float b, float* h, float* s, float* v)
{
	float max, min;
	if (r > g)
	{
		max = r;
		min = g;
	}
	else
	{
		max = g;
		min = r;
	}
	if (max < b)
	{
		max = b;
	}
	if (min > b)
	{
		min = b;
	}
	if (max == r)
	{
		*h = (g - b) / (max - min);
	}
	if (max == g)
	{
		*h = 2 + (b - r) / (max - min);
	}
	if (max == b)
	{
		*h = 4 + (r - g) / (max - min);
	}
	*h = (*h) * 60;
	if (*h < 0)
		*h = *h + 360;
	*v = max;
	*s = (max - min) / max;
}

void HSVEquation::HSVtoRGB(float h, float s, float v, float* r, float* g, float* b)
{
	if (s == 0)
	{
		*r = v;
		*g = v;
		*b = v;
	}
	else
	{
		h /= 60;
		int i = (int)h;
		float f = h - i;
		float a = v * (1 - s);
		float d = v * (1 - s * f);
		float c = v * (1 - s * (1 - f));
		switch (i)
		{
			case 0: *r = v; *g = c; *b = a; break;
			case 1: *r = d; *g = v; *b = a; break;
			case 2: *r = a; *g = v; *b = c; break;
			case 3: *r = a; *g = d; *b = v; break;
			case 4: *r = c; *g = a; *b = v; break;
			case 5: *r = v; *g = a; *b = d; break;
		}
	}
}

QImage HSVEquation::HSVEimg(QString fileName, int a)
{
	if (a == 1)
	{
		QImage  image;
		image.load(fileName);
		return image;
	}
	else {
		using PixelType = signed short;
		constexpr unsigned int Dimension = 2;
		using ImageType = itk::Image<PixelType, Dimension>;
		using PixelType1 = unsigned char;
		using ImageType1 = itk::Image<PixelType1, Dimension>;
		string file = fileName.toLocal8Bit().data();
		typedef signed short InputPixelType;
		const unsigned int   InputDimension = 2;
		typedef itk::Image< InputPixelType, InputDimension > InputImageType;
		typedef itk::ImageFileReader< InputImageType > ReaderType;
		ReaderType::Pointer reader = ReaderType::New();
		reader->SetFileName(file);
		typedef itk::GDCMImageIO           ImageIOType;
		ImageIOType::Pointer gdcmImageIO = ImageIOType::New();
		reader->SetImageIO(gdcmImageIO);
		reader->Update();
		typedef unsigned char WritePixelType;
		typedef itk::Image< WritePixelType, 2 > WriteImageType;
		typedef itk::RescaleIntensityImageFilter<
			InputImageType, WriteImageType > RescaleFilterType;
		RescaleFilterType::Pointer rescaler = RescaleFilterType::New();
		rescaler->SetOutputMinimum(0);
		rescaler->SetOutputMaximum(255);
		rescaler->SetInput(reader->GetOutput());
		rescaler->Update();
		using ImageConnector = itk::ImageToVTKImageFilter<ImageType1>;
		ImageConnector::Pointer VTKImage = ImageConnector::New();
		VTKImage->SetInput(rescaler->GetOutput());
		VTKImage->Update();
		QImage  image = getqimage(VTKImage->GetOutput());
		return image;
	}
}

void HSVEquation::OpenImg(QImage* img)
{
	QImage image = *img;
	ui.label->clear();
	ui.label->OnSelectImage(img);
	ui.label->resize(QSize(image.width(), image.height()));
}

void HSVEquation::changeimg()
{
	int height = _img->height();
	int width = _img->width();
	qDebug() << height;
	qDebug() << width;
	int x;
	if (height > width)
	{
		x = height;
	}
	else
	{
		x = width;
	}
	img_final = new QImage(width, height, QImage::Format_RGB32);
	hsv** p = new hsv * [x];
	hsv** q = new hsv * [x];
	for (int i = 0; i < width; i++)
		p[i] = new hsv[x];
	for (int i = 0; i < width; i++)
		q[i] = new hsv[x];
	float max = 0;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			QRgb rgb = _img->pixel(i, j);
			RGBtoHSV(qRed(rgb), qGreen(rgb), qBlue(rgb), &p[i][j].h, &p[i][j].s, &p[i][j].v);
			//qDebug() << i;
			max = max > p[i][j].v ? max : p[i][j].v;
		}
	}
	qDebug() << max;
	int n = (int)(max + 0.5);
	//对分量I进行直方图均衡
	int* II = new int[n + 1];
	float* IIPro = new float[n + 1];
	float* IITemp = new float[n + 1];
	float* IIJun = new float[n + 1];
	for (int i = 0; i <= n; i++)
		II[i] = 0;
	//计算频率，即nk
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			II[(int)(p[i][j].v + 0.5)]++;
		}
	}
	//计算每个数量级出现的概率
	for (int i = 0; i <= n; i++)
	{
		IIPro[i] = (II[i] * 1.0) / (width * height);
	}
	//概率累加并计算均值
	IITemp[0] = IIPro[0];
	for (int i = 1; i <= n; i++)
	{
		IITemp[i] = IITemp[i - 1] + IIPro[i];
		IIJun[i] = n * IITemp[i];
	}
	for (int i = 0; i < width; i++)
	{

		for (int j = 0; j < height; j++)
		{
			p[i][j].v = IIJun[(int)(p[i][j].v + 0.5)];
			float r, g, b;
			HSVtoRGB(p[i][j].h, p[i][j].s, p[i][j].v, &r, &g, &b);
			r = r > 255 ? 255 : (int)(r + 0.5);
			g = g > 255 ? 255 : (int)(g + 0.5);
			b = b > 255 ? 255 : (int)(b + 0.5);
			img_final->setPixel(i, j, qRgb(r, g, b));
		}
	}
}
void HSVEquation::save()
{
	Qsave* Qimg = new Qsave();
	Qimg->final = img_final1;
	Qimg->show();
}
void HSVEquation::changeimg2()
{
	int height = _img->height();
	int width = _img->width();
	qDebug() << height;
	qDebug() << width;
	int x;
	if (height > width)
	{
		x = height;
	}
	else
	{
		x = width;
	}
	img_final1 = new QImage(width, height, QImage::Format_RGB32);
	hsv** p = new hsv * [x];
	hsv** q = new hsv * [x];
	for (int i = 0; i < width; i++)
		p[i] = new hsv[x];
	for (int i = 0; i < width; i++)
		q[i] = new hsv[x];
	float max = 0;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			QRgb rgb = img_final->pixel(i, j);
			RGBtoHSV(qRed(rgb), qGreen(rgb), qBlue(rgb), &p[i][j].h, &p[i][j].s, &p[i][j].v);
			//qDebug() << i;
			max = max > p[i][j].v ? max : p[i][j].v;
		}
	}
	qDebug() << max;
	int n = (int)(max + 0.5);
	//对分量I进行直方图均衡
	int* II = new int[n + 1];
	float* IIPro = new float[n + 1];
	float* IITemp = new float[n + 1];
	float* IIJun = new float[n + 1];
	for (int i = 0; i <= n; i++)
		II[i] = 0;
	//计算频率，即nk
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			II[(int)(p[i][j].v + 0.5)]++;
		}
	}
	//计算每个数量级出现的概率
	for (int i = 0; i <= n; i++)
	{
		IIPro[i] = (II[i] * 1.0) / (width * height);
	}
	//概率累加并计算均值
	IITemp[0] = IIPro[0];
	for (int i = 1; i <= n; i++)
	{
		IITemp[i] = IITemp[i - 1] + IIPro[i];
		IIJun[i] = n * IITemp[i];
	}
	for (int i = 0; i < width; i++)
	{

		for (int j = 0; j < height; j++)
		{
			p[i][j].v = IIJun[(int)(p[i][j].v + 0.5)];
			float r, g, b;
			HSVtoRGB(p[i][j].h, p[i][j].s, p[i][j].v, &r, &g, &b);
			r = r > 255 ? 255 : (int)(r + 0.5);
			g = g > 255 ? 255 : (int)(g + 0.5);
			b = b > 255 ? 255 : (int)(b + 0.5);
			img_final1->setPixel(i, j, qRgb(r, g, b));
		}
	}
}
