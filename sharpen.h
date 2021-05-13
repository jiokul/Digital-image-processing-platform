#pragma once

#include <QWidget>
#include "ui_sharpen.h"
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
class sharpen : public QWidget
{
	Q_OBJECT

public:
	sharpen(QWidget *parent = Q_NULLPTR);
	~sharpen();
public:
	QImage sharpenimg(QString imgPath, int a);
	QImage* getsharpenimg(QImage* image);
	void OpenImg(QImage* img);
	QImage* _img;
private:
	Ui::sharpen ui;
};
