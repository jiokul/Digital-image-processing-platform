#include "DoubleThreshold.h"
#include <string.h>
#include <QDebug>
#include "vtkCallbackCommand.h"
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageToVTKImageFilter.h"
#include "vtkImageViewer.h"
#include "vtkWin32RenderWindowInteractor.h"
#include "itkResampleImageFilter.h"//����
#include "itkBinaryThresholdImageFilter.h"//��ֵ��
#include "itkThresholdImageFilter.h"//��ֵ�ָ�
#include "itkBinaryBallStructuringElement.h"
#include "itkBinaryMorphologicalOpeningImageFilter.h"//������
#include "itkMultiplyImageFilter.h"//�˷�
#include "itkAndImageFilter.h"//��
#include "itkImageFileWriter.h"
#include "itkCastImageFilter.h"
#include <iostream>
#include <string>
#include "itkRescaleIntensityImageFilter.h"
#include "itkConnectedComponentImageFilter.h"//��ͨ��
#include "itkLabelToRGBImageFilter.h"//��ɫ
#include "itkConnectedThresholdImageFilter.h"
#include "vtkImageShiftScale.h"
#include "change.h"
#include "DoubleSubmit.h"
using namespace std;
DoubleThreshold::DoubleThreshold(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

DoubleThreshold::~DoubleThreshold()
{
}

void DoubleThreshold::process(QImage* img)
{
    qDebug() << "start";
    qDebug() << high;
    qDebug() << low;
    int height = img->height();
    int width = img->width();
    img_final = new QImage(width, height, QImage::Format_Grayscale8);
    QColor rgbVal;
    int averagr = 0;
    int newx = 0;
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
            rgbVal = img->pixel(i, j);
            averagr = (rgbVal.red() + rgbVal.green() + rgbVal.blue()) / 3;
            if (averagr > low && averagr < high)
            {
                newx = 255;
            }
            else
            {
                newx = 0;
            }
            img_final->setPixel(i, j, QColor(newx, newx, newx).rgb());
        }
    }
}

QImage DoubleThreshold::Doubleimg(QString fileName, int a)
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

void DoubleThreshold::OpenImg(QImage* img)
{
    QImage image = *img;
    ui.label->clear();
    ui.label->OnSelectImage(img);
    ui.label->resize(QSize(image.width(), image.height()));
}

QImage* DoubleThreshold::getcgray()
{
    if (NULL == _img)
    {
        return NULL;
    }
    int nWidth = _img->width();
    int nHeight = _img->height();

    // ʹ����QImage::Format_Grayscale8��ʽ��ͼƬ������ͼƬÿ������ֻ����8bit�洢�Ҷ���ɫֵ
    QImage* grayImg = new QImage(nWidth, nHeight, QImage::Format_Grayscale8);
    QRgb rgbVal = 0;
    int grayVal = 0;

    for (int x = 0; x < nWidth; ++x)
    {
        for (int y = 0; y < nHeight; ++y)
        {
            rgbVal = _img->pixel(x, y);

            grayVal = qGray(rgbVal);    // �������Qt�ĺ�����ʹ��(R * 11 + G * 16 + B * 5)/32�ķ�������

            grayImg->setPixel(x, y, QColor(grayVal, grayVal, grayVal).rgb());
        }
    }
    qDebug() << nWidth;
    qDebug() << nHeight;
    return grayImg;
}
