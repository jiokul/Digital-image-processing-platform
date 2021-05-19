#include "Egary.h"
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
Egary::Egary(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(save()));
}

Egary::~Egary()
{
}

void Egary::OpenImg(QImage* img)
{
	QImage image = *img;
	ui.label->clear();
	ui.label->OnSelectImage(img);
	ui.label->resize(QSize(image.width(), image.height()));
}

void Egary::Equaliation()
{
    float max = -1;
    float min = 300;
    float total = 0;
    int sum = 256;
    sum = hist.size();
    for (int i = 0; i != sum; ++i)
    {
        total += hist[i];
        if (hist[i] != 0)
        {
            if (i > max)
            {
                max = i;
            }
            if (i < min)
            {
                min = i;
            }
        }
    }
    qDebug() << max;
    qDebug() << min;
    qDebug() << total;
    float chance[256] = { 0 };
    float chancesum[256] = { 0 };
    int  newxs[256] = { 0 };
    for (unsigned int i = 0; i != sum; ++i)
    {
        chance[i] = hist[i] / total;
    }
    for (unsigned int i = 0; i != sum; ++i)
    {
        for (unsigned int j = 0; j <= i; j++)
        {
            chancesum[i] += chance[j];
        }
    }
    for (unsigned int i = 0; i != sum; ++i)
    {
        newxs[i] = int((max - min) * chancesum[i] + 0.5);
    }
    int nWidth = _img->width();
    int nHeight = _img->height();

    // 使用了QImage::Format_Grayscale8格式的图片，这种图片每个像素只用了8bit存储灰度颜色值
    QImage* EImg = new QImage(nWidth, nHeight, QImage::Format_Grayscale8);
    QRgb rgbVal = 0;
    int grayVal = 0;
    int newe = 0;
    for (int x = 0; x < nWidth; ++x)
    {
        for (int y = 0; y < nHeight; ++y)
        {
            rgbVal = _img->pixel(x, y);
            grayVal = qGray(rgbVal);    // 这里调用Qt的函数，使用(R * 11 + G * 16 + B * 5)/32的方法计算
            newe = newxs[grayVal];
            EImg->setPixel(x, y, QColor(newe, newe, newe).rgb());
        }
    }
    imgE = EImg;
    qDebug() << newxs[0];
}
void Egary::save()
{
    Qsave* Qimg = new Qsave();
    Qimg->final = imgE;
    Qimg->show();
}
QImage Egary::Egaryimg(QString fileName, int a)
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

QImage* Egary::grayScaleImg()
{
    if (NULL == _img)
    {
        return NULL;
    }
    int nWidth = _img->width();
    int nHeight = _img->height();

    // 使用了QImage::Format_Grayscale8格式的图片，这种图片每个像素只用了8bit存储灰度颜色值
    QImage* grayImg = new QImage(nWidth, nHeight, QImage::Format_Grayscale8);
    QRgb rgbVal = 0;
    int grayVal = 0;

    for (int x = 0; x < nWidth; ++x)
    {
        for (int y = 0; y < nHeight; ++y)
        {
            rgbVal = _img->pixel(x, y);

            grayVal = qGray(rgbVal);    // 这里调用Qt的函数，使用(R * 11 + G * 16 + B * 5)/32的方法计算

            grayImg->setPixel(x, y, QColor(grayVal, grayVal, grayVal).rgb());
        }
    }
    return grayImg;
}

vector<float> Egary::Histogram(QImage* img)
{
    unsigned char* graydata = img->bits();//图片像素首位地址
    vector<float> hist(256, 0);    // 256色，初值0
    for (int i = 0; i != img->width(); ++i)
    {
        for (int j = 0; j != img->height(); ++j)
        {
            int index = int(*graydata);
            hist[index] += 1;
            graydata += 1;    // step
        }
    }
    graydata = NULL;
    return hist;
}

