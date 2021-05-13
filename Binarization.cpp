#include "Binarization.h"
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

using namespace std;
Binarization::Binarization(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

inline std::string GetValuesByTag(itk::GDCMImageIO::Pointer dicomIO, const std::string& entryId)//��ȡ��ǩ��ֵ
{
    using Dictionary = itk::MetaDataDictionary;
    using MetaDataStringType = itk::MetaDataObject<std::string>;
    const Dictionary& dic = dicomIO->GetMetaDataDictionary();
    auto itr = dic.Begin();    auto end = dic.End();
    //std::string entryId = "0010|0010";    
    auto tagItr = dic.Find(entryId);
    string tagvalue("");
    if (tagItr != end)
    {
        MetaDataStringType::ConstPointer entryvalue =
            dynamic_cast<const MetaDataStringType*> (tagItr->second.GetPointer());
        if (entryvalue)
        {
            tagvalue = entryvalue->GetMetaDataObjectValue();
        }
    }
    return tagvalue;
}

void Binarization::creatBinarization()
{
    qvtkWidget = ui.Bview;
    imgViewer = vtkSmartPointer<vtkImageViewer2>::New();
    imgViewer->SetRenderWindow(qvtkWidget->GetRenderWindow());
    renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
}

void Binarization::Binarizationdic(QString fileName)
{
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
    string tagWindowCenter = "0028|1050";//
    string valueWindowCenter = GetValuesByTag(gdcmImageIO, tagWindowCenter);
    if (valueWindowCenter == "0") {
        valueWindowCenter = "127.5";//Ĭ��127.5
    }
    //(0028, 1051)
    string tagWindowWidth = "0028|1051";
    string valueWindowWidth = GetValuesByTag(gdcmImageIO, tagWindowWidth);
    if (valueWindowWidth == "0") {
        valueWindowWidth = "255";//Ĭ��255
    }
    using ImageConnector = itk::ImageToVTKImageFilter<ImageType1>;
    ImageConnector::Pointer VTKImage = ImageConnector::New();
    VTKImage->SetInput(rescaler->GetOutput());
    VTKImage->Update();
    vtkImageData *imageData = VTKImage->GetOutput();
    vtkImageFlip* FLIPImage = vtkImageFlip::New();
    FLIPImage->SetInputData(VTKImage->GetOutput());
    FLIPImage->SetFilteredAxis(1);//y��Ϊ1��x��Ϊ0��z��Ϊ2��
    FLIPImage->Update();
    qvtkWidget->show();
    imgViewer->SetInputConnection(FLIPImage->GetOutputPort()); //����ȡ�Ķ�����ʾ����
    imgViewer->SetColorWindow(atoi(valueWindowWidth.c_str()));//���ô���
    imgViewer->SetColorLevel(atoi(valueWindowCenter.c_str()));//���ô�λ
    imgViewer->SetSliceOrientationToXY(); //������Ƭ����ΪXY
    imgViewer->SetSlice((int)imgViewer->GetSliceMax() * 0.5); //��ͼƬ��λ���м���Ƭ
    imgViewer->GetRenderer()->SetBackground(128, 128, 128); //����
    imgViewer->Render();
    imgViewer->GetRenderer()->ResetCamera();
    imgViewer->Render();


}



