#include "Equalization.h"
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
Equalization::Equalization(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

Equalization::~Equalization()
{
}

vector<int> Equalization::Histogram(QImage* img)
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

void Equalization::OpenImg(QImage* img)
{
    QImage image = *img;
    ui.Eview->clear();
    ui.Eview->OnSelectImage(img);
    ui.Eview->resize(QSize(image.width(), image.height()));
}

void Equalization::separate(QImage* img)
{
    int width1 = img->width();
    int height1 = img->height();
    int channels = 3;
    int image_size = width1 * height1 * channels; //ͼ��Ŀ�/��/ͨ��������ȥ��Aͨ����
    std::vector<float> image_data = std::vector<float>(image_size);
    ptr_image_r = image_data.data();
    const uchar* pData = img->constBits(); // ��ȡͼ��ԭʼ����
    ptr_image_g = image_data.data() + image_size / 3;
    ptr_image_b = image_data.data() + image_size / 3 * 2;
    for (int i = 0; i < height1; i++) {
        int lineNum_32 = i * width1 * 4;
        for (int k = 0; k < width1; k++) {
            if (1 < channels) {
                // ����4��ԭ����QImage���ĸ�ͨ���洢�ģ�BGRA������ÿ�����ض�ռ��4���ֽڡ�
                *ptr_image_r++ = static_cast<float> (pData[lineNum_32 + k * 4 + 2]);
                *ptr_image_g++ = static_cast<float> (pData[lineNum_32 + k * 4 + 1]);
            }
            *ptr_image_b++ = static_cast<float> (pData[lineNum_32 + k * 4]);
        }
    }

}

QImage Equalization::Equalizationimg(QString fileName, int a)
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

