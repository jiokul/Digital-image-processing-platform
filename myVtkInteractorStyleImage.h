#pragma once
#include <vtkSmartPointer.h>
#include <vtkObjectFactory.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkActor.h>
#include <vtkImageViewer2.h>
#include <vtkDICOMImageReader.h>
#include <vtkInteractorStyleImage.h>
#include <vtkActor2D.h>
#include <vtkTextProperty.h>
#include <vtkTextMapper.h>
#include <sstream>
#include <vtkTextProperty.h>
#include <vtkTextMapper.h>
using namespace std;

class StatusMessage {
public:
	static string Format(int slice, int maxSlice);
};

class StatusMessageWindow {
public:
	static string Format(double WW, double WL);
};


/*
自定义交互操作
vtkImageViewer2默认有鼠标左键调节窗宽窗位，右键调节图片大小
*/
class myVtkInteractorStyleImage : public vtkInteractorStyleImage
{
public:
	static myVtkInteractorStyleImage* New();
	vtkTypeMacro(myVtkInteractorStyleImage, vtkInteractorStyleImage);

protected:
	vtkImageViewer2* _ImageViewer;
	vtkTextMapper* _StatusMapper;
	vtkTextMapper* _StatusMapperWindow;
	int _Slice;//切片
	int _MinSlice;
	int _MaxSlice;
	int _NowSlice;

	bool LeftFlag = false;//左键按下标志
	int _x = -10000;//鼠标移动位置
	int _y = -10000;

public:
	void SetImageViewer(vtkImageViewer2* imageViewer);
	void SetStatusMapper(vtkTextMapper* statusMapper);
	void SetStatusMapperWindow(vtkTextMapper* statusMapperWindow);

protected:
	void MoveSliceForward();
	void MoveSliceBackward();
	//重载鼠标滚轮事件
	virtual void OnMouseWheelForward();
	virtual void OnMouseWheelBackward();
	//重载左键的按下和抬起
	virtual void OnLeftButtonDown() override;
	virtual void OnLeftButtonUp() override;
	//重载鼠标移动事件
	virtual void OnMouseMove() override;

};

vtkStandardNewMacro(myVtkInteractorStyleImage);
