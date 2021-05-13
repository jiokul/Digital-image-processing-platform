#pragma once

#include <QWidget>
#include "ui_DoubleThreshold.h"
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
#include "DoubleSubmit.h"
using namespace std;
class DoubleThreshold : public QWidget
{
	Q_OBJECT

public:
	DoubleThreshold(QWidget *parent = Q_NULLPTR);
	~DoubleThreshold();
public:
	void process(QImage* img);
	QImage Doubleimg(QString fileName, int a);
	void OpenImg(QImage* img);
	QImage* _img;
	QImage* img_final;
	QImage* img_gray;
	int high;
	int low;
	int judgement;
	QImage* getcgray();
private:
	Ui::DoubleThreshold ui;
};
