#pragma once

#include <QWidget>
#include "ui_RGBEquation.h"
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
class RGBEquation : public QWidget
{
	Q_OBJECT

public:
	RGBEquation(QWidget* parent = Q_NULLPTR);
	~RGBEquation();
public slots:
	void save();
public:
	void OpenImg(QImage* img);
	void Equaliationr(vector<float> hist);
	void Equaliationg(vector<float> hist);
	void Equaliationb(vector<float> hist);
	void final();
	QImage RGBEimg(QString fileName, int a);
	//QImage* grayScaleImg();
	QImage* _img;
	QString LocalFileName;  //Í¼Æ¬Ãû
	void Histogram();
	vector<float> rhist;
	vector<float> ghist;
	vector<float> bhist;
	int newrhist[256] = {0};
	int newghist[256] = { 0 };
	int newbhist[256] = { 0 };
	QImage* imgE;
private:
	Ui::RGBEquation ui;
};
