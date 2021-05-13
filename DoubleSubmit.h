#pragma once

#include <QWidget>
#include "ui_DoubleSubmit.h"
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
class DoubleSubmit : public QWidget
{
	Q_OBJECT

public:
	DoubleSubmit(QWidget *parent = Q_NULLPTR);
	~DoubleSubmit();
public slots:
	void getlow();
	void gethigh();
	void run();
public:
	int low;
	int high;
	int jud = 0;
	QString fileName;
	int type;
private:
	Ui::DoubleSubmit ui;
};
