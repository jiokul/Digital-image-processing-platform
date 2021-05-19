#pragma once

#include <QWidget>
#include "ui_Egary.h"
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
class Egary : public QWidget
{
	Q_OBJECT

public:
	Egary(QWidget *parent = Q_NULLPTR);
	~Egary();
public slots:
	void save();
public:
	void OpenImg(QImage* img);
	void Equaliation();
	QImage Egaryimg(QString fileName, int a);
	QImage* grayScaleImg();
	QImage* _img;
	QString LocalFileName;  //Í¼Æ¬Ãû
	vector<float> Histogram(QImage* img);
	vector<float> hist = {0};
	QImage* imgE;
private:
	Ui::Egary ui;
};
