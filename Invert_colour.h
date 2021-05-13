#pragma once

#include <QWidget>
#include "ui_Invert_colour.h"
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
class Invert_colour : public QWidget
{
	Q_OBJECT

public:
	Invert_colour(QWidget *parent = Q_NULLPTR);
	~Invert_colour();
public:
	void OpenImg(QImage* img);
	QImage* newimg; 
	void handling(QImage* img);
	QImage colour(QString fileName, int a);
	QImage* _img;
private:
	Ui::Invert_colour ui;
};
