#include "HSIEquation.h"
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
typedef struct HSI {
    float h;
    float s;
    float i;
}hsi;
HSIEquation::HSIEquation(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}
HSIEquation::~HSIEquation()
{
}
void HSIEquation::RGBtoHSI(float r, float g, float b, float* h, float* s, float* i)
{
    float pi = 3.1415926;
    float temp = sqrt((r - g) * (r - g) + (r - b) * (g - b));
     temp = temp > 0 ? temp : 0.01;
     if (b <= g)
     * h = acos(((r - g + r - b) / 2.0) / temp);
     else
     * h = 2 * pi - acos(((r - g + r - b) / 2.0) / temp);
     temp = r + g + b > 0 ? r + g + b : 0.01;
     float x;
     if (r > g)
     {
         x = g;
     }
     else
     {
         x = r;
     }
     if (x > b)
     {
         x = b;
     }
     * s = 1.0 - (3.0 / temp) * x;
     * i = (r + g + b) / 3.0;
}

void HSIEquation::HSItoRGB(float h, float s, float i, float* r, float* g, float* b)
{
    float pi = 3.1415926;
    float otz = 2 * pi / 3;
    if (h >= 0 && h < otz)
     {
         * b = i * (1.0 - s);
         * r = i * (1.0 + (s * cos(h)) / (cos(pi / 3.0 - h)));
         * g = 3.0 * i - (*b + *r);
     }
     else if (h >= otz && h < 2 * otz)
     {
         * r = i * (1 - s);
         * g = i * (1 + (s * cos(h - otz)) / (cos(pi - h)));
         * b = 3 * i - (*g + *r);
     }
     else
     {
         * g = i * (1 - s);
         * b = i * (1 + (s * cos(h - otz * 2)) / (cos(5 * pi / 6 - h)));
         * r = 3 * i - (*g + *b);
     }
}
void HSIEquation::changeimg()
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
    hsi** p = new hsi * [x];
    hsi** q = new hsi * [x];
    for (int i = 0; i < width; i++)
        p[i] = new hsi[x];
    for (int i = 0; i < width; i++)
        q[i] = new hsi[x];
    float max = 0;
    for (int i = 0; i < width; i++)
      {
        for (int j = 0; j < height; j++)
            {
              QRgb rgb = _img->pixel(i, j);
              RGBtoHSI(qRed(rgb), qGreen(rgb), qBlue(rgb), &p[i][j].h, &p[i][j].s, &p[i][j].i);
              //qDebug() << i;
              max = max > p[i][j].i ? max : p[i][j].i;
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
               II[(int)(p[i][j].i + 0.5)]++;
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
             p[i][j].i = IIJun[(int)(p[i][j].i + 0.5)];
             float r, g, b;
             HSItoRGB(p[i][j].h, p[i][j].s, p[i][j].i, &r, &g, &b);
             r = r > 255 ? 255 : (int)(r + 0.5);
             g = g > 255 ? 255 : (int)(g + 0.5);
             b = b > 255 ? 255 : (int)(b + 0.5);
             img_final->setPixel(i, j, qRgb(r, g, b));
          }
      }
    qDebug() <<3;
    
}

//void HSIEquation::changeimg2()
//{
//    int height = _img->height();
//    int width = _img->width();
//    qDebug() << height;
//    qDebug() << width;
//    int x;
//    if (height > width)
//    {
//        x = height;
//    }
//    else
//    {
//        x = width;
//    }
//    img_final = new QImage(width, height, QImage::Format_RGB32);
//    hsi** p = new hsi * [x];
//    hsi** q = new hsi * [x];
//    for (int i = 0; i < width; i++)
//        p[i] = new hsi[x];
//    for (int i = 0; i < width; i++)
//        q[i] = new hsi[x];
//    float max = 0;
//    for (int i = 0; i < width; i++)
//    {
//        for (int j = 0; j < height; j++)
//        {
//            QRgb rgb = _img->pixel(i, j);
//            RGBtoHSI(qRed(rgb), qGreen(rgb), qBlue(rgb), &p[i][j].h, &p[i][j].s, &p[i][j].i);
//            //qDebug() << i;
//            max = max > p[i][j].s ? max : p[i][j].s;
//        }
//    }
//    qDebug() << max;
//    //int n = (int)(max + 0.5);
//    ////对分量I进行直方图均衡
//    //int* II = new int[n + 1];
//    //float* IIPro = new float[n + 1];
//    //float* IITemp = new float[n + 1];
//    //float* IIJun = new float[n + 1];
//    //for (int i = 0; i <= n; i++)
//    //    II[i] = 0;
//    ////计算频率，即nk
//    //for (int i = 0; i < width; i++)
//    //{
//    //    for (int j = 0; j < height; j++)
//    //    {
//    //        II[(int)(p[i][j].s + 0.5)]++;
//    //    }
//    //}
//    ////计算每个数量级出现的概率
//    //for (int i = 0; i <= n; i++)
//    //{
//    //    IIPro[i] = (II[i] * 1.0) / (width * height);
//    //}
//    ////概率累加并计算均值
//    //IITemp[0] = IIPro[0];
//    //for (int i = 1; i <= n; i++)
//    //{
//    //    IITemp[i] = IITemp[i - 1] + IIPro[i];
//    //    IIJun[i] = n * IITemp[i];
//    //}
//    for (int i = 0; i < width; i++)
//    {
//        for (int j = 0; j < height; j++)
//        {
//            q[i][j].s = p[i][j].s * 6 - (p[i][j].s * p[i][j].s);
//            q[i][j].i = p[i][j].i;
//            q[i][j].h = p[i][j].h;
//        }
//    }
//    qDebug() << max;
//    for (int i = 0; i < width; i++)
//    {
//
//        for (int j = 0; j < height; j++)
//        {
//            //p[i][j].s = IIJun[(int)(p[i][j].s + 0.5)];
//            float r, g, b;
//            HSItoRGB(q[i][j].h, q[i][j].s, q[i][j].i, &r, &g, &b);
//            r = r > 255 ? 255 : (int)(r + 0.5);
//            g = g > 255 ? 255 : (int)(g + 0.5);
//            b = b > 255 ? 255 : (int)(b + 0.5);
//            img_final->setPixel(i, j, qRgb(r, g, b));
//        }
//    }
//}

QImage HSIEquation::HSIEimg(QString fileName, int a)
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

void HSIEquation::OpenImg(QImage* img)
{
    QImage image = *img;
    ui.HSIview->clear();
    ui.HSIview->OnSelectImage(img);
    ui.HSIview->resize(QSize(image.width(), image.height()));
}

