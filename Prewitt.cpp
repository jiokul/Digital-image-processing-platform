#include "Prewitt.h"
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
Prewitt::Prewitt(QWidget *parent)
	: QWidget(parent)
{
    this->notedge = qRgb(0, 0, 0);//非边缘颜色
    this->edge = qRgb(255, 255, 255);//边缘颜色
	ui.setupUi(this);
}

Prewitt::~Prewitt()
{
}

QImage Prewitt::preimg(QString fileName, int a)
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

void Prewitt::calculate()
{
    int k = 3;
    double temp = 0;
    double kernelx[3][3] = { -1,0,1,-1,0,1,-1,0,1 };
    double kernely[3][3] = { 1,1,1,0,0,0,-1,-1,-1 };

    QImage* t_img = new QImage(img_gray->width() + k - 1, img_gray->height() + k - 1, QImage::Format_ARGB32);
    img_calulate = new QImage(img_gray->width(), img_gray->height(), QImage::Format_ARGB32);
    //lefttop
    for (int i = 0; i < k / 2; ++i) {
        for (int j = 0; j < k / 2; ++j) {
            t_img->setPixel(i, j, img_gray->pixel(0, 0));
        }
    }
    //righttop
    for (int i = 0; i < k / 2; ++i) {
        for (int j = 0; j < k / 2; ++j) {
            t_img->setPixel(i, j, img_gray->pixel(img_gray->width() - 1, 0));
        }
    }
    //rightbottom
    for (int i = img_gray->width() + k / 2; i < t_img->width(); ++i) {
        for (int j = 0; j < k / 2; ++j) {
            t_img->setPixel(i, j, img_gray->pixel(img_gray->width() - 1, img_gray->height() - 1));
        }
    }
    //leftbottom
    for (int i = 0; i < k / 2; ++i) {
        for (int j = img_gray->height() + k / 2; j < t_img->height(); ++j) {
            t_img->setPixel(i, j, img_gray->pixel(0, img_gray->height() - 1));
        }
    }
    //top
    for (int i = 0; i < img_gray->width(); ++i) {
        for (int j = 0; j < k / 2; ++j) {
            t_img->setPixel(i + k / 2, j, img_gray->pixel(i, 0));
        }
    }
    //right
    for (int i = t_img->width() - k / 2; i < t_img->width(); ++i) {
        for (int j = 0; j < img_gray->height(); ++j) {
            t_img->setPixel(i, j + k / 2, img_gray->pixel(img_gray->width() - 1, j));
        }
    }
    //bottom
    for (int i = 0; i < img_gray->width(); ++i) {
        for (int j = t_img->height() - k / 2; j < t_img->height(); ++j) {
            t_img->setPixel(i + k / 2, j, img_gray->pixel(i, img_gray->height() - 1));
        }
    }
    //left
    for (int i = 0; i < k / 2; ++i) {
        for (int j = 0; j < img_gray->height(); ++j) {
            t_img->setPixel(i, j + k / 2, img_gray->pixel(0, j));
        }
    }
    for (int i = 0; i < img_gray->width(); ++i) {
        for (int j = 0; j < img_gray->height(); ++j) {
            t_img->setPixel(i + k / 2, j + k / 2, img_gray->pixel(i, j));
        }
    }
    int x, y;
    for (int i = k / 2,  x = 0; i < t_img->width() - k / 2; ++i,++x) {
        for (int j = k / 2,  y = 0; j < t_img->height() - k / 2; ++j,++y) {
            double tempx = 0;
            double tempy = 0;
            for (int ti = 0; ti < k; ++ti) {
                for (int tj = 0; tj < k; ++tj) {
                    tempx += kernelx[ti][tj] * qRed(t_img->pixel(i - k / 2 + ti, j - k / 2 + tj));
                    tempy += kernely[ti][tj] * qRed(t_img->pixel(i - k / 2 + ti, j - k / 2 + tj));
                }
            }
            temp = sqrt(pow(tempx, 2) + pow(tempy, 2));
            if (temp > 255)
            {
                temp = 255;
            }
            if (temp < 0)
            {
                temp = 0;
            }
            img_calulate->setPixel(x, y, QColor(temp, temp, temp).rgb());
        }
    }
    QColor rgbVal;
    int average;
    img_final = new QImage(img_gray->width(), img_gray->height(), QImage::Format_ARGB32);
    for (int x = 0; x < img_calulate->width(); ++x)
    {
        for (int y = 0; y < img_calulate->height(); ++y)
        {
            rgbVal = img_calulate->pixel(x, y);
            average = (rgbVal.red() + rgbVal.green() + rgbVal.blue()) / 3;
            if (average > three)
            {
                img_final->setPixel(x, y, QColor(255, 255, 255).rgb());
            }
            else
            {
                img_final->setPixel(x, y, QColor(0, 0, 0).rgb());
            }
        }
    }
}

void Prewitt::grayScaleImg()
{
    QImage* img = _img;
    img_gray = new QImage(img->width(), img->height(), QImage::Format_ARGB32);
    QColor old_color;
    int average;
    for (int i = 0; i < img_gray->width(); ++i) {
        for (int j = 0; j < img_gray->height(); ++j) {
            old_color = img->pixel(i, j);
            average = (old_color.red() + old_color.green() + old_color.blue()) / 3;
            img_gray->setPixel(i, j, qRgb(average, average, average));
        }
    }
}

vector<int> Prewitt::Histogram(QImage* img)
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

int Prewitt::Otsu(QImage* img)
{
    if (NULL == img)
    {
        return -1;
    }
    vector<int> histogram = Histogram(img);
    int total = 0;
    for (int i = 0; i != histogram.size(); ++i)
    {
        total += histogram[i];
    }

    double sum = 0.0;
    for (unsigned int i = 1; i < histogram.size(); ++i)
        sum += i * histogram[i];//累加均值m
    double sumB = 0.0;//P1全局均值mG
    double wB = 0.0;//P1个数
    double wF = 0.0;//P2个数
    double mB = 0.0;//均值m1
    double mF = 0.0;//均值m2
    double max = 0.0;
    double between = 0.0;
    double threshold = 0.0;
    for (int i = 0; i != 256; ++i)
    {
        wB += histogram[i];
        if (wB == 0)
            continue;
        wF = total - wB;
        if (wF == 0)
            break;
        sumB += i * histogram[i];
        mB = sumB / wB;//m1=(1/p1)*mg
        mF = (sum - sumB) / wF;//(1/p2)*(sum-mg)
        between = wB * wF * (mB - mF) * (mB - mF);
        if (between > max)
        {
            threshold = i;
            max = between;
        }
    }
    return threshold;
}


void Prewitt::OpenImg(QImage* img)
{
    QImage image = *img;
    ui.Pview->clear();
    ui.Pview->OnSelectImage(img);
    ui.Pview->resize(QSize(image.width(), image.height()));
}
