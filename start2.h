#pragma once

#include <QWidget>
#include "ui_start2.h"
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
class start2 : public QWidget
{
	Q_OBJECT

public:
	start2(QWidget *parent = Q_NULLPTR);
	~start2();
public:
	void OpenImg(QImage* img);
	QImage startimg2(QString fileName, int a);
	QImage* _img;
private:
	Ui::start2 ui;
};
