#pragma once

#include <QWidget>
#include "ui_Maximumentropy.h"
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
class Maximumentropy : public QWidget
{
	Q_OBJECT

public:
	Maximumentropy(QWidget *parent = Q_NULLPTR);
	~Maximumentropy();
public:
	QImage maximgae(QString fileName, int a);
	QImage* grayScaleImg();
	int maxcalculate(QImage* img);
	QImage* process(QImage* img);
	QImage* _img;
	QImage* img_final;
	int threshold;
	void OpenImg(QImage* img);
private:
	Ui::Maximumentropy ui;
};
