#pragma once

#include <QWidget>
#include "ui_Binarization.h"
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
class Binarization : public QWidget
{
	Q_OBJECT

public:
	Binarization(QWidget *parent = Q_NULLPTR);
	void creatBinarization();
	void Binarizationdic(QString fileName);
	double _WindowWidth;//Ä¬ÈÏ´°¿í
	double _WindowLevel;//Ä¬ÈÏ´°Î»
	QVTKWidget* qvtkWidget;
	vtkSmartPointer<vtkImageViewer2> imgViewer;
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor;
private:
	Ui::Binarization ui;
};
