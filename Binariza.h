#pragma once

#include <QWidget>
#include "ui_Binariza.h"
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
class Binariza : public QWidget
{
	Q_OBJECT

public:
	Binariza(QWidget *parent = Q_NULLPTR);
	~Binariza();
public slots:
	void save();
public:
	void OpenImg(QImage *img);
	QImage binary(QString fileName,int a);
	QImage* grayScaleImg();
	int Otsu(QImage* img);
	QImage* process(QImage* img);
	int     threshold;
	QImage* _img;
	QImage* img_final;
	QString LocalFileName;  //ͼƬ��
	vector<int> Histogram(QImage* img);
	QString svaefile;
	QString name;
	QString type;
	int type1;
	int type2;
	int type3;
private:
	Ui::Binariza ui;
};