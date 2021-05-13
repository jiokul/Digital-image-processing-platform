#pragma once

#include <QWidget>
#include "ui_Gpicture.h"
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
class Gpicture : public QWidget
{
	Q_OBJECT

public:
	Gpicture(QWidget *parent = Q_NULLPTR);
	~Gpicture();
public:
	void OpenImg(QImage* img);
	QImage gary(QString fileName, int a);
	QImage* grayScaleImg();
	QImage* _img;
	QString LocalFileName;  //Í¼Æ¬Ãû
	vector<int> Histogram(QImage* img);
	void showHistogram(QImage* img);
private:
	Ui::Gpicture ui;
};
