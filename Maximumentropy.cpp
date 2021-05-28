#include "Maximumentropy.h"
#include <string.h>
#include <QDebug>
#include "vtkCallbackCommand.h"
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageToVTKImageFilter.h"
#include "vtkImageViewer.h"
#include "vtkWin32RenderWindowInteractor.h"
#include "itkImageFileWriter.h"
#include "itkCastImageFilter.h"
#include <iostream>
#include <string>
#include "itkRescaleIntensityImageFilter.h"
#include "vtkImageShiftScale.h"
#include "change.h"
#include "Qsave.h"

using namespace std;

using namespace std;
Maximumentropy::Maximumentropy(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

Maximumentropy::~Maximumentropy()
{
}

QImage Maximumentropy::maximgae(QString fileName, int a)
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

QImage* Maximumentropy::grayScaleImg()
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
    qDebug() << nWidth;
    qDebug() << nHeight;
    return grayImg;
}

vector<int> Histogram(QImage* img)//直方图分布
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

int Maximumentropy::maxcalculate(QImage* img)
{
    if (NULL == img)
    {
        return NULL;
    }
    int wight = img->width();
    int height = img->height();
    int sum = 0;
    vector<int> histogram = Histogram(img);
    for (int i = 0; i != histogram.size(); i++)
    {
        sum += histogram[i];
    }
    qDebug() << histogram[0];
    float max = -100;
    int maxnumber = 0;
    float between = 0;
    float p1,p2;
    for (int i = 0; i != 256; i++)
    {
        float h1 = 0;
        float h2 = 0;
        int frontpix = 0;
        for (int j = 0; j < i; j++)
        {
            frontpix += histogram[j];
        }
        for (int j = 0; j < i; j++)
        {
            if (histogram[j] != 0)
            {
                p1 = (float)histogram[j] / frontpix;
                h1 = h1 + p1 * log(1 / p1);
            }
        }
        for (int k = i + 1; k < 256; k++)
        {
            if (histogram[k] != 0)
            {
                p2 = (float)histogram[k] / (sum - frontpix);
                h2 = h2 + p2 * log(1 / p2);
            }
        }
        between = h1 + h2;
        if (max < between)
        {
            max = between;
            maxnumber = i;
        }
    }
    return maxnumber;
}

QImage* Maximumentropy::process(QImage* img)
{
    if (NULL == img)
    {
        return NULL;
    }
    int width = img->width();
    int height = img->height();
    int bytePerLine = img->bytesPerLine();    // 每一行的字节数
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
                binarydata[i * bytePerLine + j] = 255;
            }
            else
            {
                binarydata[i * bytePerLine + j] = 0;
            }
        }
    }
    QImage* ret = new QImage(binarydata, width, height, bytePerLine, QImage::Format_Grayscale8);
    return ret;
}

void Maximumentropy::OpenImg(QImage* img)
{
    QImage image = *img;
    ui.label->clear();
    ui.label->OnSelectImage(img);
    ui.label->resize(QSize(image.width(), image.height()));
}
