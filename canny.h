#pragma once

#include <QWidget>
#include "ui_canny.h"
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
class canny : public QWidget
{
	Q_OBJECT

public:
	canny(QWidget *parent = Q_NULLPTR);
	~canny();
public:
	QImage cannyimg(QString fileName, int a);
	QImage* _img;
	QString LocalFileName;  //Í¼Æ¬Ãû
	void grayScaleImg();
	void OpenImg(QImage* img);
	void Smooth();
	void calculate();
	void nms();
	void bt();
	void st();
	double** gradx;
	double** grady;
	double** grad;
	double** gradcp;
	double** dir;
	QImage* img_gray;
	QImage* img_guass;
	QImage* img_nms;
	QImage* img_dt;
	QImage* img_st;
	double highthresh;
	double lowthresh;
	QRgb edge;
	QRgb notedge;
private:
	Ui::canny ui;
};
