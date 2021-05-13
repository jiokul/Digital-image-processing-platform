#include "Gpicture.h"
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
using namespace std;
Gpicture::Gpicture(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

Gpicture::~Gpicture()
{
}

void Gpicture::OpenImg(QImage* img)
{
    QImage image = *img;
    ui.Glabel->clear();
    ui.Glabel->OnSelectImage(img);
    ui.Glabel->resize(QSize(image.width(), image.height()));
}

QImage Gpicture::gary(QString fileName, int a)
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

QImage* Gpicture::grayScaleImg()
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

vector<int> Gpicture::Histogram(QImage* img)
{
    unsigned char* graydata = img->bits();//图片像素首位地址
    vector<int> hist(256, 0);    // 256色，初值0
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

void Gpicture::showHistogram(QImage* img)
{
    double yrange = 0;
    QVector<double> datax;
    QVector<double> datay;
    ui.Gwidget->clearGraphs();
    datay.resize(256);
    for (double i = 0; i < 256; i = i + 1)
        datax.append(i);
    QImage  grayimg = img->copy();
    unsigned char* data = grayimg.bits();
    //  对直方图进行数据处理
    int width = img->width();
    int hight = img->height();
    for (int i = 0; i < hight; i++)  
    {
        for (int j = 0; j < width; j++)
        {
            datay.replace(data[i * hight + j], datay.at(data[i * hight + j]) + 1);
        }
    }
    QVector<double>::iterator it;
    for (it = datay.begin(); it != datay.end(); it++)
    {
        if (*it > yrange)
            yrange = *it;
    }
    ui.Gwidget->xAxis->setRange(0, 256);  //x轴范围
    ui.Gwidget->yAxis->setRange(0, (int)yrange);  //y轴范围
    QCPBars* bars = new QCPBars(ui.Gwidget->xAxis, ui.Gwidget->yAxis);
    bars->setData(datax, datay);
    bars->setPen(QColor(0, 0, 0));
    bars->setWidth(0.05);
    ui.Gwidget->setVisible(true);
    ui.Gwidget->replot();
}


