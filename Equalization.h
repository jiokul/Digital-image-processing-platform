#pragma once
#include <QWidget>
#include "ui_Equalization.h"
#include <QVTKWidget.h>
#include <vtkDICOMImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkSmartPointer.h>
#include <vtkTextMapper.h>
#include <vtkTextProperty.h>
#include <vtkRenderer.h>
#include <vtkActor2D.h>
#include <sstream>
#include <itkImage.h>
#include <itkImageFileReader.h>
#include <itkImageToVTKImageFilter.h>
#include <itkGDCMImageIO.h>
#include <itkMetaDataDictionary.h>
#include <itkMetaDataObject.h>
#include <itkImageSeriesReader.h>
#include <itkGDCMSeriesFileNames.h>
#include <vtkImageFlip.h>
using namespace std;
class Equalization : public QWidget
{
	Q_OBJECT

public:
	Equalization(QWidget *parent = Q_NULLPTR);
	~Equalization();
public:
	vector<int> Histogram(QImage* img);
	QImage* _img;
	QString LocalFileName;  //Í¼Æ¬Ãû
	QImage Equalizationimg(QString fileName, int a);
	void OpenImg(QImage* img);
	void separate(QImage* img);
	float* ptr_image_r;
	float* ptr_image_g;
	float* ptr_image_b;

private:
	Ui::Equalization ui;
};
