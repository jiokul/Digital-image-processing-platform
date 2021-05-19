#include "Binariza_turn.h"
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
#include "Qsave.h"
Binariza_turn::Binariza_turn(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(save()));
}

Binariza_turn::~Binariza_turn()
{
}

void Binariza_turn::OpenImg(QImage* img)
{
	QImage image = *img;
	ui.label->clear();
	ui.label->OnSelectImage(img);
	ui.label->resize(QSize(image.width(), image.height()));
}
void Binariza_turn::save()
{
    Qsave* Qimg = new Qsave();
    Qimg->final = img_fianl;
    Qimg->show();
}

QImage Binariza_turn::binary(QString fileName, int a)
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

QImage* Binariza_turn::grayScaleImg()
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

int Binariza_turn::Otsu(QImage* img)
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
        sum += i * histogram[i];//�ۼӾ�ֵm
    double sumB = 0.0;//P1ȫ�־�ֵmG
    double wB = 0.0;//P1����
    double wF = 0.0;//P2����
    double mB = 0.0;//��ֵm1
    double mF = 0.0;//��ֵm2
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

QImage* Binariza_turn::process(QImage* img)
{
    if (NULL == img)
    {
        return NULL;
    }
    int width = img->width();
    int height = img->height();
    int bytePerLine = img->bytesPerLine();    // ÿһ�е��ֽ���
    unsigned char* data = img->bits();
    unsigned char* binarydata = new unsigned char[bytePerLine * height];

    unsigned char g = 0;
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            g = *(data + i * bytePerLine + j);
            if (int(g) >= threshold)
            {
                binarydata[i * bytePerLine + j] = 0;
            }
            else
            {
                binarydata[i * bytePerLine + j] = 255;
            }
        }
    }
    QImage* ret = new QImage(binarydata, width, height, bytePerLine, QImage::Format_Grayscale8);
    return ret;
}

vector<int> Binariza_turn::Histogram(QImage* img)
{
    unsigned char* graydata = img->bits();//ͼƬ������λ��ַ
    vector<int> hist(256, 0);    // 256ɫ����ֵ0
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
