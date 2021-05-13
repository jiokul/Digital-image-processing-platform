#pragma once
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

class ImageRender
{
public:
	ImageRender(QVTKWidget*);
	~ImageRender();
	void renderDicomFile(const std::string& file);
	void renderDicomFolder(const std::string& folder);
	void SetWindow(int style,double width,double center);
	void ChangeSliceOrientationXY();
	void ChangeSliceOrientationXZ();
	void ChangeSliceOrientationYZ();

private:
	QVTKWidget* qvtkWidget;
	vtkSmartPointer<vtkImageViewer2> imgViewer;
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor;
	//vtkSmartPointer<vtkDICOMImageReader> DICOMReader;
	/*显示切片*/
	vtkSmartPointer<vtkTextProperty> sliceTextProp;
	vtkSmartPointer<vtkTextMapper> sliceTextMapper;
	vtkSmartPointer<vtkActor2D> sliceTextActor;
	/*显示一些Tag信息*/
	vtkSmartPointer<vtkTextProperty> tagTextProp;
	vtkSmartPointer<vtkTextMapper> tagTextMapper;
	vtkSmartPointer<vtkActor2D> tagTextActor;
	/*显示窗宽窗位*/
	vtkSmartPointer<vtkTextProperty> WindowTextProp;
	vtkSmartPointer<vtkTextMapper> WindowTextMapper;
	vtkSmartPointer<vtkActor2D> WindowTextActor;

public:
	double _WindowWidth;//默认窗宽
	double _WindowLevel;//默认窗位
	string TagShow;//屏幕显示的Tag信息
};
