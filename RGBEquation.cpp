#include "RGBEquation.h"
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
RGBEquation::RGBEquation(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(save()));
}

RGBEquation::~RGBEquation()
{
}

void RGBEquation::OpenImg(QImage* img)
{
    QImage image = *img;
    ui.RGBlabel->clear();
    ui.RGBlabel->OnSelectImage(img);
    ui.RGBlabel->resize(QSize(image.width(), image.height()));
}

void  RGBEquation::Equaliationr(vector<float> hist)
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
    float chance[256] = { 0 };
    float chancesum[256] = { 0 };
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
        newrhist[i] = int((max - min) * chancesum[i] + 0.5);
    }
    qDebug() << newrhist[0];
}

void RGBEquation::save()
{
    Qsave* Qimg = new Qsave();
    Qimg->final = imgE;
    Qimg->show();
}

void RGBEquation::Equaliationg(vector<float> hist)
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
    float chance[256] = { 0 };
    float chancesum[256] = { 0 };
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
        newghist[i] = int((max - min) * chancesum[i] + 0.5);
    }
    qDebug() << newghist[0];
}

void RGBEquation::Equaliationb(vector<float> hist)
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
    float chance[256] = { 0 };
    float chancesum[256] = { 0 };
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
        newbhist[i] = int((max - min) * chancesum[i] + 0.5);
    }
    qDebug() << newbhist[0];
}

void RGBEquation::final()
{
    int nWidth = _img->width();
    int nHeight = _img->height();
    QImage* EImg = new QImage(nWidth, nHeight, QImage::Format_RGB32);
    QRgb rgbVal = 0;
    int r = 0;
    int g = 0;
    int b = 0;
    int rnewe = 0;
    int gnewe = 0;
    int bnewe = 0;
    for (int x = 0; x < nWidth; ++x)
    {
        for (int y = 0; y < nHeight; ++y)
        {
            rgbVal = _img->pixel(x, y);
            r = qRed(rgbVal);
            g = qGreen(rgbVal);
            b = qBlue(rgbVal);
            rnewe = newrhist[r];
            gnewe = newghist[g];
            bnewe = newbhist[b];
            EImg->setPixel(x, y, QColor(rnewe, gnewe, bnewe).rgb());
        }
    }
    imgE = EImg;
}

QImage RGBEquation::RGBEimg(QString fileName, int a)
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

void RGBEquation::Histogram()
{
    int nWidth = _img->width();
    int nHeight = _img->height();
    QColor c;
    QRgb d;
    vector<float> rhist1(256, 0);
    vector<float> ghist1(256, 0);
    vector<float> bhist1(256, 0);
    for (int i = 0; i != _img->width(); ++i)
    {
        for (int j = 0; j != _img->height(); ++j)
        {
            d = _img->pixel(i, j);
            rhist1[qRed(d)] += 1;
            ghist1[qGreen(d)] += 1;
            bhist1[qBlue(d)] += 1;
        }
    }
    rhist = rhist1;
    ghist = ghist1;
    bhist = bhist1;
}
