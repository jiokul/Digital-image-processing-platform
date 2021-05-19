#include "Invert_colour.h"
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
Invert_colour::Invert_colour(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

Invert_colour::~Invert_colour()
{
}

void Invert_colour::OpenImg(QImage* img)
{
	QImage image = *img;
	ui.label->clear();
	ui.label->OnSelectImage(img);
	ui.label->resize(QSize(image.width(), image.height()));
}
void Invert_colour::save()
{
    Qsave* Qimg = new Qsave();
    Qimg->final = newimg;
    Qimg->show();
}

void Invert_colour::handling(QImage* img)
{
    int height = img->height();
    int weight = img->width();
    QRgb rgbVal;
    QImage* EImg = new QImage(weight, height, QImage::Format_ARGB32);
    for (int i = 0; i < weight; i++)
    {
        for (int j = 0; j < height; j++)
        {
            rgbVal = img->pixel(i, j);
            int newr = 255 - qRed(rgbVal);
            int newg = 255 - qGreen(rgbVal);
            int newb = 255 - qBlue(rgbVal);
            EImg->setPixel(i, j, QColor(newr, newg, newb).rgb());
        }
    }
    newimg = EImg;
}


QImage Invert_colour::colour(QString fileName, int a)
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
