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
�Զ��彻������
vtkImageViewer2Ĭ�������������ڴ���λ���Ҽ�����ͼƬ��С
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
	int _Slice;//��Ƭ
	int _MinSlice;
	int _MaxSlice;
	int _NowSlice;

	bool LeftFlag = false;//������±�־
	int _x = -10000;//����ƶ�λ��
	int _y = -10000;

public:
	void SetImageViewer(vtkImageViewer2* imageViewer);
	void SetStatusMapper(vtkTextMapper* statusMapper);
	void SetStatusMapperWindow(vtkTextMapper* statusMapperWindow);

protected:
	void MoveSliceForward();
	void MoveSliceBackward();
	//�����������¼�
	virtual void OnMouseWheelForward();
	virtual void OnMouseWheelBackward();
	//��������İ��º�̧��
	virtual void OnLeftButtonDown() override;
	virtual void OnLeftButtonUp() override;
	//��������ƶ��¼�
	virtual void OnMouseMove() override;

};

vtkStandardNewMacro(myVtkInteractorStyleImage);
