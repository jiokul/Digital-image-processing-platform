#include "canny.h"
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
canny::canny(QWidget *parent)
	: QWidget(parent)
{
    this->highthresh = 1.5;
    this->lowthresh = 0.4;
    this->notedge = qRgb(0, 0, 0);//非边缘颜色
    this->edge = qRgb(255, 255, 255);//边缘颜色
    this->resize(600, 800);
	ui.setupUi(this);
}

canny::~canny()
{
}

void generic_guess(double kernel[10][10], int size, double thelt) {
    double pi = acos(-1);
    double sum = 0;
    int mk = size / 2;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            kernel[i][j] = exp(-sqrt(pow(i - mk, 2) + pow(j - mk, 2)) / (2 * thelt * thelt));
            kernel[i][j] /= 2 * pi * thelt * thelt;
            sum += kernel[i][j];
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            kernel[i][j] /= sum;
        }
    }
}

void canny::grayScaleImg()
{
    QImage *img = _img;
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

void canny::OpenImg(QImage* img)
{
    QImage image = *img;
    ui.Cview->clear();
    ui.Cview->OnSelectImage(img);
    ui.Cview->resize(QSize(image.width(), image.height()));
}

void canny::Smooth()
{
    int k = 5;//高斯滤波器规模
    double kernel[10][10];
    generic_guess(kernel, k, 1.4);
    QImage* t_img = new QImage(img_gray->width() + k - 1, img_gray->height() + k - 1, QImage::Format_ARGB32);
     img_guass = new QImage(img_gray->width(), img_gray->height(), QImage::Format_ARGB32);

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

    for (int i = k / 2; i < t_img->width() - k / 2; ++i) {
        for (int j = k / 2; j < t_img->height() - k / 2; ++j) {
            double temp = 0;
            for (int ti = 0; ti < k; ++ti) {
                for (int tj = 0; tj < k; ++tj) {
                    temp += kernel[ti][tj] * qRed(t_img->pixel(i - k / 2 + ti, j - k / 2 + tj));
                }
            }
            img_guass->setPixel(i - k / 2, j - k / 2, qRgb(temp, temp, temp));
        }
    }

}

void canny::calculate()
{
    gradx = new double* [_img->width()];
    for (int i = 0; i < _img->width(); ++i)
        gradx[i] = new double[_img->height()];
    grady = new double* [_img->width()];
    for (int i = 0; i < _img->width(); ++i)
        grady[i] = new double[_img->height()];
    grad = new double* [_img->width()];
    for (int i = 0; i < _img->width(); ++i)
        grad[i] = new double[_img->height()];
    dir = new double* [_img->width()];
    for (int i = 0; i < _img->width(); ++i)
        dir[i] = new double[_img->height()];
    int k = 3;//sobel算子规模
    double kernelx[3][3] = { -1,0,1,-2,0,2,-1,0,1 };
    double kernely[3][3] = { 1,2,1,0,0,0,-1,-2,-1 };

    QImage* t_img = new QImage(img_gray->width() + k - 1, img_gray->height() + k - 1, QImage::Format_ARGB32);
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
    for (int i = k / 2; i < t_img->width() - k / 2; ++i) {
        for (int j = k / 2; j < t_img->height() - k / 2; ++j) {
            double tempx = 0;
            double tempy = 0;
            for (int ti = 0; ti < k; ++ti) {
                for (int tj = 0; tj < k; ++tj) {
                    tempx += kernelx[ti][tj] * qRed(t_img->pixel(i - k / 2 + ti, j - k / 2 + tj));
                    tempy += kernely[ti][tj] * qRed(t_img->pixel(i - k / 2 + ti, j - k / 2 + tj));
                }
            }
            gradx[i - k / 2][j - k / 2] = tempx;
            grady[i - k / 2][j - k / 2] = tempy;
            grad[i - k / 2][j - k / 2] = sqrt(pow(tempx, 2) + pow(tempy, 2));
            double theta = atan(tempy / tempx) + 90;//反正切函数
            if (theta >= 0 && theta < 45)
                dir[i - k / 2][j - k / 2] = 2;
            else if (theta >= 45 && theta < 90)
                dir[i - k / 2][j - k / 2] = 3;
            else if (theta >= 90 && theta < 135)
                dir[i - k / 2][j - k / 2] = 0;
            else
                dir[i - k / 2][j - k / 2] = 1;
        }
    }
    //calcu = true;
}

void canny::nms()
{
    img_nms = new QImage(img_guass->width(), img_guass->height(), QImage::Format_ARGB32);

    double temp = 0;
    for (int i = 0; i < img_nms->width(); ++i) {
        for (int j = 0; j < img_nms->height(); ++j) {
            temp += grad[i][j];
        }
    }
    temp /= img_nms->width() * img_nms->height();
    highthresh *= temp;
    lowthresh *= highthresh;

    double N, NE, E, SW, W, SE, S, NW;
    double grad1 = 0, grad2 = 0, tantheta = 0;
    for (int i = 1; i < img_nms->width() - 1; ++i) {
        for (int j = 1; j < img_nms->height(); ++j) {
            N = grad[i][j - 1];
            NE = grad[i + 1][j - 1];
            E = grad[i + 1][j];
            SW = grad[i - 1][j + 1];
            W = grad[i - 1][j];
            SE = grad[i + 1][j + 1];
            S = grad[i][j + 1];
            NW = grad[i - 1][j - 1];
            if (dir[i][j] == 0) {
                tantheta = abs(grady[i][j] / gradx[i][j]);
                grad1 = E * (1 - tantheta) + NE * tantheta;
                grad2 = W * (1 - tantheta) + SW * tantheta;
            }
            else if (dir[i][j] == 1) {
                tantheta = abs(gradx[i][j] / grady[i][j]);
                grad1 = N * (1 - tantheta) + NE * tantheta;
                grad2 = S * (1 - tantheta) + SW * tantheta;
            }
            else if (dir[i][j] == 2) {
                tantheta = abs(gradx[i][j] / grady[i][j]);
                grad1 = N * (1 - tantheta) + NW * tantheta;
                grad2 = S * (1 - tantheta) + SE * tantheta;
            }
            else if (dir[i][j] == 3) {
                tantheta = abs(grady[i][j] / gradx[i][j]);
                grad1 = W * (1 - tantheta) + NW * tantheta;
                grad2 = E * (1 - tantheta) + SE * tantheta;
            }
            else {
                grad1 = highthresh;
                grad2 = highthresh;
            }
            if (grad[i][j] > grad1 && grad[i][j] > grad2) {
                img_nms->setPixel(i, j, edge);//边缘
//                gradcp[i][j]=highthresh;
            }
            else {
                img_nms->setPixel(i, j, notedge);//非边缘
                grad[i][j] = 0;
            }
        }
    }
}

void canny::bt()
{
    img_dt = new QImage(img_nms->width(), img_nms->height(), QImage::Format_ARGB32);
    gradcp = new double* [_img->width()];
    for (int i = 0; i < _img->width(); ++i)
        gradcp[i] = new double[_img->height()];


    for (int i = 0; i < img_dt->width(); ++i) {
        for (int j = 0; j < img_dt->height(); ++j) {
            if (grad[i][j] > highthresh) {//强边缘
                gradcp[i][j] = highthresh;
                img_dt->setPixel(i, j, edge);
            }
            else if (grad[i][j] > lowthresh) {//弱边缘
                gradcp[i][j] = lowthresh;
                img_dt->setPixel(i, j, edge);
            }
            else {//非边缘
                gradcp[i][j] = 0;
                img_dt->setPixel(i, j, notedge);//抑制
            }
        }
    }
}

void canny::st()
{
    img_st = new QImage(img_dt->width(), img_dt->height(), QImage::Format_ARGB32);
    int frac[8][2] = { {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };
    for (int i = 1; i < img_st->width() - 1; ++i) {
        for (int j = 1; j < img_st->height() - 1; ++j) {
            if (gradcp[i][j] == highthresh) {//强边缘
                img_st->setPixel(i, j, edge);
            }
            else if (gradcp[i][j] == lowthresh) {//弱边缘
                for (int p = 0; p < 8; ++p) {
                    if (gradcp[i + frac[p][0]][j + frac[p][1]] == highthresh) {
                        img_st->setPixel(i, j, edge);//边缘
                        break;
                    }
                    img_st->setPixel(i, j, notedge);//非边缘
                }
            }
            else//非边缘
                img_st->setPixel(i, j, notedge);
        }
    }
}

QImage canny::cannyimg(QString fileName, int a)
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



