#include "blur.h"
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
blur::blur(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(save()));
}

blur::~blur()
{
}

QImage blur::blurimg(QString imgPath, int a)
{
    if (a == 1)
    {
        QImage  image;
        image.load(imgPath);
        return image;
    }
    else {
        using PixelType = signed short;
        constexpr unsigned int Dimension = 2;
        using ImageType = itk::Image<PixelType, Dimension>;
        using PixelType1 = unsigned char;
        using ImageType1 = itk::Image<PixelType1, Dimension>;
        string file = imgPath.toLocal8Bit().data();
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

QImage* blur::getblurimg(QImage* image)
{
    int kernel[5][5] = { {0,0,1,0,0},
                        {0,1,3,1,0},
                        {1,3,7,3,1},
                        {0,1,3,1,0},
                        {0,0,1,0,0} };
    int k = 5;
    int sumKernel = 27;
    QColor color;
    QImage* t_img = new QImage(image->width() + k - 1, image->height() + k - 1, QImage::Format_ARGB32);
    QImage* newImage = new QImage(image->width(), image->height(), QImage::Format_ARGB32);

    //lefttop
    for (int i = 0; i < k / 2; ++i) {
        for (int j = 0; j < k / 2; ++j) {
            t_img->setPixel(i, j, image->pixel(0, 0));
        }
    }
    //righttop
    for (int i = 0; i < k / 2; ++i) {
        for (int j = 0; j < k / 2; ++j) {
            t_img->setPixel(i, j, image->pixel(image->width() - 1, 0));
        }
    }
    //rightbottom
    for (int i = image->width() + k / 2; i < t_img->width(); ++i) {
        for (int j = 0; j < k / 2; ++j) {
            t_img->setPixel(i, j, image->pixel(image->width() - 1, image->height() - 1));
        }
    }
    //leftbottom
    for (int i = 0; i < k / 2; ++i) {
        for (int j = image->height() + k / 2; j < t_img->height(); ++j) {
            t_img->setPixel(i, j, image->pixel(0, image->height() - 1));
        }
    }
    //top
    for (int i = 0; i < image->width(); ++i) {
        for (int j = 0; j < k / 2; ++j) {
            t_img->setPixel(i + k / 2, j, image->pixel(i, 0));
        }
    }
    //right
    for (int i = t_img->width() - k / 2; i < t_img->width(); ++i) {
        for (int j = 0; j < image->height(); ++j) {
            t_img->setPixel(i, j + k / 2, image->pixel(image->width() - 1, j));
        }
    }
    //bottom
    for (int i = 0; i < image->width(); ++i) {
        for (int j = t_img->height() - k / 2; j < t_img->height(); ++j) {
            t_img->setPixel(i + k / 2, j, image->pixel(i, image->height() - 1));
        }
    }
    //left
    for (int i = 0; i < k / 2; ++i) {
        for (int j = 0; j < image->height(); ++j) {
            t_img->setPixel(i, j + k / 2, image->pixel(0, j));
        }
    }
    for (int i = 0; i < image->width(); ++i) {
        for (int j = 0; j < image->height(); ++j) {
            t_img->setPixel(i + k / 2, j + k / 2, image->pixel(i, j));
        }
    }
    for (int x = k / 2; x < image->width() - k / 2; x++)
    {
        for (int y = k / 2; y < image->height() - k / 2; y++)
        {
            int r = 0;
            int g = 0;
            int b = 0;
            for (int i = -k / 2; i <= k / 2; i++)
            {
                for (int j = -k / 2; j <= k / 2; j++)
                {
                    color = QColor(t_img->pixel(x + i, y + j));
                    r += color.red() * kernel[k / 2 + i][k / 2 + j];
                    g += color.green() * kernel[k / 2 + i][k / 2 + j];
                    b += color.blue() * kernel[k / 2 + i][k / 2 + j];
                }
            }
            r = qBound(0, r / sumKernel, 255);
            g = qBound(0, g / sumKernel, 255);
            b = qBound(0, b / sumKernel, 255);
            newImage->setPixel(x, y, qRgb(r, g, b));
        }
    }
    return newImage;
}

void blur::OpenImg(QImage* img)
{
    QImage image = *img;
    ui.label->clear();
    ui.label->OnSelectImage(img);;
    ui.label->resize(QSize(image.width(), image.height()));
}
void blur::save()
{
    Qsave* Qimg = new Qsave();
    Qimg->final = img_final;
    Qimg->show();
}
