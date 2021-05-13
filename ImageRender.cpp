#include "ImageRender.h"
#include "myVtkInteractorStyleImage.h"
#include <QDebug>
#include "vtkCallbackCommand.h"
#include <string.h>
using namespace std;

ImageRender::ImageRender(QVTKWidget* w): qvtkWidget(w)
{
	//init
	imgViewer = vtkSmartPointer<vtkImageViewer2>::New();
	imgViewer->SetRenderWindow(qvtkWidget->GetRenderWindow());
	renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	/*显示切片信息*/
	sliceTextProp = vtkSmartPointer<vtkTextProperty>::New();
	sliceTextMapper = vtkSmartPointer<vtkTextMapper>::New();
	sliceTextActor = vtkSmartPointer<vtkActor2D>::New();
	/*显示一些Tag信息*/
	tagTextProp = vtkSmartPointer<vtkTextProperty>::New();
	tagTextMapper = vtkSmartPointer<vtkTextMapper>::New();
	tagTextActor = vtkSmartPointer<vtkActor2D>::New();
	/*显示窗宽窗位信息*/
	WindowTextProp = vtkSmartPointer<vtkTextProperty>::New();
	WindowTextMapper = vtkSmartPointer<vtkTextMapper>::New();
	WindowTextActor = vtkSmartPointer<vtkActor2D>::New();
	imgViewer->GetRenderer()->SetBackground(0.0, 0.0, 0.0);
	imgViewer->SetupInteractor(renderWindowInteractor);
	renderWindowInteractor->Initialize();
}

ImageRender::~ImageRender()
{
	imgViewer->Delete();
	renderWindowInteractor->Delete();
	//if (DICOMReader)DICOMReader->Delete();
	/*切片显示*/
	if (sliceTextProp)sliceTextProp->Delete();
	if (sliceTextMapper)sliceTextMapper->Delete();
	if (sliceTextActor)sliceTextActor->Delete();

	/*一些tag显示*/
	if (tagTextProp)tagTextProp->Delete();
	if (tagTextMapper)tagTextMapper->Delete();
	if (tagTextActor)tagTextActor->Delete();

	/*窗宽窗位显示*/
	if (WindowTextProp)WindowTextProp->Delete();
	if (WindowTextMapper)WindowTextMapper->Delete();
	if (WindowTextActor)WindowTextActor->Delete();
}

inline std::string GetValuesByTag(itk::GDCMImageIO::Pointer dicomIO, const std::string& entryId)//获取标签的值
{
	using Dictionary = itk::MetaDataDictionary;
	using MetaDataStringType = itk::MetaDataObject<std::string>;
	const Dictionary& dic = dicomIO->GetMetaDataDictionary();
	auto itr = dic.Begin();    auto end = dic.End();
	//std::string entryId = "0010|0010";    
	auto tagItr = dic.Find(entryId);
	string tagvalue("");
	if (tagItr != end)
	{
		MetaDataStringType::ConstPointer entryvalue =
			dynamic_cast<const MetaDataStringType*> (tagItr->second.GetPointer());
		if (entryvalue)
		{
			tagvalue = entryvalue->GetMetaDataObjectValue();
		}
	}
	return tagvalue;
}

void ImageRender::renderDicomFile(const string& file)
{
	qvtkWidget->show();
	//ITK读取单张DICOM
	using PixelType = signed short;
	constexpr unsigned int Dimension = 2;
	using ImageType = itk::Image<PixelType, Dimension>;
	using ReaderFileType = itk::ImageFileReader<ImageType>;
	ReaderFileType::Pointer DICOMReader = ReaderFileType::New();
	DICOMReader->SetFileName(file);

	using ImageIOType = itk::GDCMImageIO;
	ImageIOType::Pointer gdcmImageIO = ImageIOType::New();
	DICOMReader->SetImageIO(gdcmImageIO);
	DICOMReader->Update();


	//获取窗宽窗位
	//(0028, 1050)   
	string tagWindowCenter = "0028|1050";//
	string valueWindowCenter = GetValuesByTag(gdcmImageIO, tagWindowCenter);
	if (valueWindowCenter == "0") {
		valueWindowCenter = "127.5";//默认127.5
	}
	//(0028, 1051)
	string tagWindowWidth = "0028|1051";
	string valueWindowWidth = GetValuesByTag(gdcmImageIO, tagWindowWidth);
	if (valueWindowWidth == "0") {
		valueWindowWidth = "255";//默认255
	}
	//获取机构名称 Institution Name (0008, 0080)
	string tagInstitutionName = "0008|0080";
	string valueInstitutionName = GetValuesByTag(gdcmImageIO, tagInstitutionName);
	if (valueInstitutionName == "") {
		valueInstitutionName = "NULL";//默认
	}
	//获取患者ID Patient ID	(0010,0020)
	string tagPatientID = "0010|0020";
	string valuePatientID = GetValuesByTag(gdcmImageIO, tagPatientID);
	if (valuePatientID == "") {
		valuePatientID = "NULL";//默认
	}
	//获取患者姓名 Patient’s Name（0010，0010）
	string tagPatientName = "0010|0010";
	string valuePatientName = GetValuesByTag(gdcmImageIO, tagPatientName);
	if (valuePatientName == "") {
		valuePatientName = "NULL";//默认
	}
	//获取患者性别 Patient’s Sex（0010，0040）
	string tagPatientSex = "0010|0040";
	string valuePatientSex = GetValuesByTag(gdcmImageIO, tagPatientSex);
	if (valuePatientSex == "") {
		valuePatientSex = "NULL";//默认
	}
	//获取患者拍片子时年龄 Patient’s Age（0010，1010）
	string tagPatientAge = "0010|1010";
	string valuePatientAge = GetValuesByTag(gdcmImageIO, tagPatientAge);
	if (valuePatientAge == "") {
		valuePatientAge = "NULL";//默认
	}
	//获取序列描述 Series Description (0008,103e)
	string tagSeriesDescription = "0008|103e";
	string valueSeriesDescription = GetValuesByTag(gdcmImageIO, tagSeriesDescription);
	if (valueSeriesDescription == "") {
		valueSeriesDescription = "NULL";//默认
	}
	//获取序列日期 Series Date (0008, 0021)
	string tagSeriesDate = "0008|0021";
	string valueSeriesDate = GetValuesByTag(gdcmImageIO, tagSeriesDate);
	if (valueSeriesDate == "") {
		valueSeriesDate = "NULL";//默认
	}else {
		//修改日期字符串,加入分割
		string del = ".";
		valueSeriesDate.insert(4, del);
		valueSeriesDate.insert(7, del);
	}
	//合并Tag信息
	//string TagShow;
	string NextLine = "\n";
	string SpaceStr = " ";
	TagShow = valueInstitutionName;
	TagShow += NextLine;
	TagShow += valuePatientID;
	TagShow += NextLine;
	TagShow += valuePatientName;
	TagShow += NextLine;
	TagShow += valuePatientSex;
	TagShow += SpaceStr;
	TagShow += valuePatientAge;
	TagShow += NextLine;
	TagShow += valueSeriesDescription;
	TagShow += NextLine;
	TagShow += valueSeriesDate;

	// ITK转VTK
	using ImageConnector = itk::ImageToVTKImageFilter<ImageType>;
	ImageConnector::Pointer VTKImage = ImageConnector::New();
	VTKImage->SetInput(DICOMReader->GetOutput());
	VTKImage->Update();         

	//由于vtk、itk显示图像时y轴相反，此处做一次翻转 
	vtkImageFlip* FLIPImage = vtkImageFlip::New();
	FLIPImage->SetInputData(VTKImage->GetOutput());
	FLIPImage->SetFilteredAxis(1);
	FLIPImage->Update();

	_WindowWidth = atoi(valueWindowWidth.c_str());
	_WindowLevel = atoi(valueWindowCenter.c_str());


	imgViewer->SetInputConnection(FLIPImage->GetOutputPort());
	imgViewer->SetColorWindow(_WindowWidth);//设置窗宽
	imgViewer->SetColorLevel(_WindowLevel);//设置窗位
	imgViewer->SetSliceOrientationToXY();//设置切片方向为XY

	//设置文字显示，显示当前切片
	sliceTextProp->SetFontFamilyToCourier();
	sliceTextProp->SetFontSize(20);
	sliceTextProp->SetVerticalJustificationToBottom();
	sliceTextProp->SetJustificationToLeft();

	std::string msg = StatusMessage::Format(imgViewer->GetSliceMin(), imgViewer->GetSliceMax());
	sliceTextMapper->SetInput(msg.c_str());
	sliceTextMapper->SetTextProperty(sliceTextProp);

	sliceTextActor->SetMapper(sliceTextMapper);
	sliceTextActor->SetPosition(15, 5);

	//显示其他标签  
	tagTextProp->SetFontFamilyToCourier();    
	tagTextProp->SetFontSize(20);    
	tagTextProp->SetVerticalJustificationToBottom();    
	tagTextProp->SetJustificationToLeft();     
 
	tagTextMapper->SetInput(TagShow.c_str());   
	tagTextMapper->SetTextProperty(tagTextProp);     
 
	tagTextActor->SetMapper(tagTextMapper);    
	tagTextActor->GetPositionCoordinate()->SetCoordinateSystemToNormalizedDisplay();    
	tagTextActor->GetPositionCoordinate()->SetValue(0.005, 0.85);

	//设置文字显示，显示窗宽窗位
	WindowTextProp->SetFontFamilyToCourier();
	WindowTextProp->SetFontSize(20);
	WindowTextProp->SetVerticalJustificationToBottom();
	WindowTextProp->SetJustificationToLeft();

	string msgWindow = StatusMessageWindow::Format(imgViewer->GetColorWindow(),imgViewer->GetColorLevel());
	WindowTextMapper->SetInput(msgWindow.c_str());
	WindowTextMapper->SetTextProperty(WindowTextProp);

	WindowTextActor->SetMapper(WindowTextMapper);
	WindowTextActor->SetPosition(15, 25);


	vtkSmartPointer<myVtkInteractorStyleImage> myInteractorStyle = vtkSmartPointer<myVtkInteractorStyleImage>::New();
	myInteractorStyle->SetImageViewer(imgViewer); //设置保存图片参数
	myInteractorStyle->SetStatusMapper(sliceTextMapper); //设置切片数文字显示
	myInteractorStyle->SetStatusMapperWindow(WindowTextMapper); //设置窗宽窗位显示

	imgViewer->SetupInteractor(renderWindowInteractor);
	renderWindowInteractor->SetInteractorStyle(myInteractorStyle);

	//文字显示
	imgViewer->GetRenderer()->AddActor2D(sliceTextActor);//显示切片数
	string FirstMsg = StatusMessage::Format(imgViewer->GetSliceMax() * 0.5, imgViewer->GetSliceMax());
	sliceTextMapper->SetInput(FirstMsg.c_str());
	imgViewer->GetRenderer()->AddActor2D(tagTextActor);//显示标签信息
	imgViewer->GetRenderer()->AddActor2D(WindowTextActor);//显示窗宽窗位

	imgViewer->Render();
	imgViewer->GetRenderer()->ResetCamera();
	imgViewer->Render();
}

void ImageRender::renderDicomFolder(const string& folder)
{
	qvtkWidget->show();

	//ITK读取
	using PixelType = signed short;
	constexpr unsigned int Dimension = 3;
	using ImageType = itk::Image<PixelType, Dimension>;
	using ImageIOType = itk::GDCMImageIO;
	ImageIOType::Pointer gdcmImageIO = ImageIOType::New();

	using NamesGeneratorType = itk::GDCMSeriesFileNames;
	NamesGeneratorType::Pointer nameGenarator = NamesGeneratorType::New();
	nameGenarator->SetDirectory(folder);

	using FilenamesContainer = vector<string>;
	FilenamesContainer filenames = nameGenarator->GetInputFileNames();

	using ReaderSeriesType = itk::ImageSeriesReader<ImageType>;
	ReaderSeriesType::Pointer DICOMReader = ReaderSeriesType::New();
	DICOMReader->SetImageIO(gdcmImageIO);
	DICOMReader->SetFileNames(filenames);
	DICOMReader->SetReverseOrder(true);
	DICOMReader->Update();

	//获取窗宽窗位
	//Tag：(0028, 1050)
	string tagWindowCenter = "0028|1050";
	string valueWindowCenter = GetValuesByTag(gdcmImageIO, tagWindowCenter);
	if (valueWindowCenter == "0") {
		valueWindowCenter = "127.5";//默认127.5
	}
	//Tag：(0028, 1051)
	string tagWindowWidth = "0028|1051";
	string valueWindowWidth = GetValuesByTag(gdcmImageIO, tagWindowWidth);
	if (valueWindowWidth == "0") {
		valueWindowWidth = "255";//默认255
	}
	//获取机构名称 Institution Name (0008, 0080)
	string tagInstitutionName = "0008|0080";
	string valueInstitutionName = GetValuesByTag(gdcmImageIO, tagInstitutionName);
	if (valueInstitutionName == "") {
		valueInstitutionName = "NULL";//默认
	}
	//获取患者ID Patient ID	(0010,0020)
	string tagPatientID = "0010|0020";
	string valuePatientID = GetValuesByTag(gdcmImageIO, tagPatientID);
	if (valuePatientID == "") {
		valuePatientID = "NULL";//默认
	}
	//获取患者姓名 Patient’s Name（0010，0010）
	string tagPatientName = "0010|0010";
	string valuePatientName = GetValuesByTag(gdcmImageIO, tagPatientName);
	if (valuePatientName == "") {
		valuePatientName = "NULL";//默认
	}
	//获取患者性别 Patient’s Sex（0010，0040）
	string tagPatientSex = "0010|0040";
	string valuePatientSex = GetValuesByTag(gdcmImageIO, tagPatientSex);
	if (valuePatientSex == "") {
		valuePatientSex = "NULL";//默认
	}
	//获取患者拍片子时年龄 Patient’s Age（0010，1010）
	string tagPatientAge = "0010|1010";
	string valuePatientAge = GetValuesByTag(gdcmImageIO, tagPatientAge);
	if (valuePatientAge == "") {
		valuePatientAge = "NULL";//默认
	}
	//获取序列描述 Series Description (0008,103e)
	string tagSeriesDescription = "0008|103e";
	string valueSeriesDescription = GetValuesByTag(gdcmImageIO, tagSeriesDescription);
	if (valueSeriesDescription == "") {
		valueSeriesDescription = "NULL";//默认
	}
	//获取序列日期 Series Date (0008, 0021)
	string tagSeriesDate = "0008|0021";
	string valueSeriesDate = GetValuesByTag(gdcmImageIO, tagSeriesDate);
	if (valueSeriesDate == "") {
		valueSeriesDate = "NULL";//默认
	}
	else {
		//修改日期字符串,加入分割
		string del = ".";
		valueSeriesDate.insert(4, del);
		valueSeriesDate.insert(7, del);
	}
	//合并Tag信息
	//string TagShow;
	string NextLine = "\n";
	string SpaceStr = " ";
	TagShow = valueInstitutionName;
	TagShow += NextLine;
	TagShow += valuePatientID;
	TagShow += NextLine;
	TagShow += valuePatientName;
	TagShow += NextLine;
	TagShow += valuePatientSex;
	TagShow += SpaceStr;
	TagShow += valuePatientAge;
	TagShow += NextLine;
	TagShow += valueSeriesDescription;
	TagShow += NextLine;
	TagShow += valueSeriesDate;

	
	//ITK转VTK
	using ImageConnector = itk::ImageToVTKImageFilter<ImageType>;
	ImageConnector::Pointer VTKImage = ImageConnector::New();
	VTKImage->SetInput(DICOMReader->GetOutput());
	VTKImage->Update();

	//由于vtk、itk显示图像时y轴相反，此处做一次翻转 
	vtkImageFlip* FLIPImage = vtkImageFlip::New();
	FLIPImage->SetInputData(VTKImage->GetOutput());
	FLIPImage->SetFilteredAxis(1);//y轴为1，x轴为0，z轴为2；
	FLIPImage->Update();

	imgViewer->SetInputConnection(FLIPImage->GetOutputPort()); //将读取的对象显示出来
	imgViewer->SetColorWindow(atoi(valueWindowWidth.c_str()));//设置窗宽
	imgViewer->SetColorLevel(atoi(valueWindowCenter.c_str()));//设置窗位
	_WindowWidth = imgViewer->GetColorWindow();
	_WindowLevel = imgViewer->GetColorLevel();
	imgViewer->SetSliceOrientationToXY(); //设置切片方向为XY
	imgViewer->SetSlice((int)imgViewer->GetSliceMax() * 0.5); //将图片定位到中间切片

	if (!sliceTextProp)sliceTextProp = vtkSmartPointer<vtkTextProperty>::New();
	if (!sliceTextMapper)sliceTextMapper = vtkSmartPointer<vtkTextMapper>::New();
	if (!sliceTextActor)sliceTextActor = vtkSmartPointer<vtkActor2D>::New();

	//设置文字显示，显示当前切片
	sliceTextProp->SetFontFamilyToCourier();
	sliceTextProp->SetFontSize(20);
	sliceTextProp->SetVerticalJustificationToBottom();
	sliceTextProp->SetJustificationToLeft();

	string msg = StatusMessage::Format(imgViewer->GetSliceMin(), imgViewer->GetSliceMax());
	sliceTextMapper->SetInput(msg.c_str());
	sliceTextMapper->SetTextProperty(sliceTextProp);

	sliceTextActor->SetMapper(sliceTextMapper);
	sliceTextActor->SetPosition(15, 10);

	//显示其他标签  
	tagTextProp->SetFontFamilyToCourier();
	tagTextProp->SetFontSize(20);
	tagTextProp->SetVerticalJustificationToBottom();
	tagTextProp->SetJustificationToLeft();

	tagTextMapper->SetInput(TagShow.c_str());
	tagTextMapper->SetTextProperty(tagTextProp);

	tagTextActor->SetMapper(tagTextMapper);
	tagTextActor->GetPositionCoordinate()->SetCoordinateSystemToNormalizedDisplay();
	tagTextActor->GetPositionCoordinate()->SetValue(0.005, 0.85);

	//设置文字显示，显示窗宽窗位
	WindowTextProp->SetFontFamilyToCourier();
	WindowTextProp->SetFontSize(20);
	WindowTextProp->SetVerticalJustificationToBottom();
	WindowTextProp->SetJustificationToLeft();

	string msgWindow = StatusMessageWindow::Format(imgViewer->GetColorWindow(), imgViewer->GetColorLevel());
	WindowTextMapper->SetInput(msgWindow.c_str());
	WindowTextMapper->SetTextProperty(WindowTextProp);

	WindowTextActor->SetMapper(WindowTextMapper);
	WindowTextActor->SetPosition(15, 25);


	vtkSmartPointer<myVtkInteractorStyleImage> myInteractorStyle = vtkSmartPointer<myVtkInteractorStyleImage>::New();
	myInteractorStyle->SetImageViewer(imgViewer); //设置保存图片参数
	myInteractorStyle->SetStatusMapper(sliceTextMapper); //设置文字显示
	myInteractorStyle->SetStatusMapperWindow(WindowTextMapper); //设置窗宽窗位显示

	//设置交互属性
	imgViewer->SetupInteractor(renderWindowInteractor);
	renderWindowInteractor->SetInteractorStyle(myInteractorStyle);

	//文字显示
	imgViewer->GetRenderer()->AddActor2D(sliceTextActor);//显示切片数
	string FirstMsg = StatusMessage::Format(imgViewer->GetSliceMax() * 0.5, imgViewer->GetSliceMax());
	sliceTextMapper->SetInput(FirstMsg.c_str());
	imgViewer->GetRenderer()->AddActor2D(tagTextActor);//显示标签信息
	imgViewer->GetRenderer()->AddActor2D(WindowTextActor);//显示窗宽窗位

	imgViewer->GetRenderer()->SetBackground(0.0, 0.0, 0.0); //背景
	imgViewer->Render();
	imgViewer->GetRenderer()->ResetCamera();
	imgViewer->Render();
}


void ImageRender::ChangeSliceOrientationXY() 
{
	imgViewer->SetSliceOrientationToXY();
	imgViewer->SetSlice((int)imgViewer->GetSliceMax() * 0.5);

	/////
	vtkSmartPointer<myVtkInteractorStyleImage> myInteractorStyle = vtkSmartPointer<myVtkInteractorStyleImage>::New();
	myInteractorStyle->SetImageViewer(imgViewer); //设置保存图片参数
	myInteractorStyle->SetStatusMapper(sliceTextMapper); //设置文字显示
	myInteractorStyle->SetStatusMapperWindow(WindowTextMapper); //设置窗宽窗位显示

	//设置交互属性
	imgViewer->SetupInteractor(renderWindowInteractor);
	renderWindowInteractor->SetInteractorStyle(myInteractorStyle);

	imgViewer->GetRenderer()->AddActor2D(sliceTextActor);//显示切片数
	string FirstMsg = StatusMessage::Format(imgViewer->GetSliceMax() * 0.5, imgViewer->GetSliceMax());
	sliceTextMapper->SetInput(FirstMsg.c_str());
	/////

	imgViewer->GetRenderer()->SetBackground(0.0, 0.0, 0.0); //背景
	imgViewer->Render();
	imgViewer->GetRenderer()->ResetCamera();
	imgViewer->Render();
}
void ImageRender::ChangeSliceOrientationYZ()
{
	imgViewer->SetSliceOrientationToYZ();
	imgViewer->SetSlice((int)imgViewer->GetSliceMax() * 0.5);

	/////
	vtkSmartPointer<myVtkInteractorStyleImage> myInteractorStyle = vtkSmartPointer<myVtkInteractorStyleImage>::New();
	myInteractorStyle->SetImageViewer(imgViewer); //设置保存图片参数
	myInteractorStyle->SetStatusMapper(sliceTextMapper); //设置文字显示
	myInteractorStyle->SetStatusMapperWindow(WindowTextMapper); //设置窗宽窗位显示

	//设置交互属性
	imgViewer->SetupInteractor(renderWindowInteractor);
	renderWindowInteractor->SetInteractorStyle(myInteractorStyle);

	imgViewer->GetRenderer()->AddActor2D(sliceTextActor);//显示切片数
	string FirstMsg = StatusMessage::Format(imgViewer->GetSliceMax() * 0.5, imgViewer->GetSliceMax());
	sliceTextMapper->SetInput(FirstMsg.c_str());
	/////

	imgViewer->GetRenderer()->SetBackground(0.0, 0.0, 0.0); //背景
	imgViewer->Render();
	imgViewer->GetRenderer()->ResetCamera();
	imgViewer->Render();
}
void ImageRender::ChangeSliceOrientationXZ()
{
	imgViewer->SetSliceOrientationToXZ();
	imgViewer->SetSlice((int)imgViewer->GetSliceMax() * 0.5);

	/////
	vtkSmartPointer<myVtkInteractorStyleImage> myInteractorStyle = vtkSmartPointer<myVtkInteractorStyleImage>::New();
	myInteractorStyle->SetImageViewer(imgViewer); //设置保存图片参数
	myInteractorStyle->SetStatusMapper(sliceTextMapper); //设置文字显示
	myInteractorStyle->SetStatusMapperWindow(WindowTextMapper); //设置窗宽窗位显示

	//设置交互属性
	imgViewer->SetupInteractor(renderWindowInteractor);
	renderWindowInteractor->SetInteractorStyle(myInteractorStyle);

	imgViewer->GetRenderer()->AddActor2D(sliceTextActor);//显示切片数
	string FirstMsg = StatusMessage::Format(imgViewer->GetSliceMax() * 0.5, imgViewer->GetSliceMax());
	sliceTextMapper->SetInput(FirstMsg.c_str());
	/////

	imgViewer->GetRenderer()->SetBackground(0.0, 0.0, 0.0); //背景
	imgViewer->Render();
	imgViewer->GetRenderer()->ResetCamera();
	imgViewer->Render();
}


void ImageRender::SetWindow(int style, double width, double center)
{
	double WW, WL;
	if (style == 0) {
		WW = _WindowWidth;
		WL = _WindowLevel;
	}
	else {
		WW = width;
		WL = center;
	}
	imgViewer->SetColorWindow(WW);
	imgViewer->SetColorLevel(WL);
	string msg = StatusMessageWindow::Format(imgViewer->GetColorWindow(), imgViewer->GetColorLevel());
	WindowTextMapper->SetInput(msg.c_str());//显示窗宽窗位
	imgViewer->Render();
}

void myVtkInteractorStyleImage::SetImageViewer(vtkImageViewer2* imageViewer)
{
	//定位图片位置
	_ImageViewer = imageViewer;
	//切片
	_MinSlice = imageViewer->GetSliceMin();
	_MaxSlice = imageViewer->GetSliceMax();
	_NowSlice = imageViewer->GetSlice();
	_Slice = _NowSlice;
}

void myVtkInteractorStyleImage::SetStatusMapper(vtkTextMapper* statusMapper)
{
	_StatusMapper = statusMapper;
}

void myVtkInteractorStyleImage::SetStatusMapperWindow(vtkTextMapper* statusMapperWindow)
{
	_StatusMapperWindow = statusMapperWindow;
}

void myVtkInteractorStyleImage::MoveSliceForward()
{
	//切换显示下一张切片
	if (_Slice < _MaxSlice)
	{
		_Slice += 1;
		_ImageViewer->SetSlice(_Slice);

		string msg = StatusMessage::Format(_Slice, _MaxSlice);
		_StatusMapper->SetInput(msg.c_str());

		_ImageViewer->Render();
	}
}

void myVtkInteractorStyleImage::MoveSliceBackward()
{
	//切换显示上一张切片
	if (_Slice >= _MinSlice)
	{
		_Slice -= 1;
		_ImageViewer->SetSlice(_Slice);

		string msg = StatusMessage::Format(_Slice, _MaxSlice);
		_StatusMapper->SetInput(msg.c_str());

		_ImageViewer->Render();
	}
}

void myVtkInteractorStyleImage::OnMouseWheelForward()
{
	//鼠标滚轮前移，切换下一张
	MoveSliceForward();
}

void myVtkInteractorStyleImage::OnMouseWheelBackward()
{
	//鼠标滚轮后移，切换上一张
	if (_Slice > _MinSlice)
	{
		MoveSliceBackward();
	}
}

string StatusMessage::Format(int slice, int maxSlice)
{
	stringstream tmp;
	tmp << "Slice Number  " << slice + 1 << "/" << maxSlice + 1;
	return tmp.str();
}

string StatusMessageWindow::Format(double WW,double WL)
{
	stringstream tmp;
	tmp << "WW:" << WW << "  WL:" << WL;
	return tmp.str();
}

void myVtkInteractorStyleImage::OnLeftButtonDown()
{
	_x = -10000;
	_y = -10000;
	LeftFlag = true;
}

void myVtkInteractorStyleImage::OnLeftButtonUp()
{
	LeftFlag = false;
}

void myVtkInteractorStyleImage::OnMouseMove()
{
	int x = this->Interactor->GetEventPosition()[0];
	int y = this->Interactor->GetEventPosition()[1];
	if (LeftFlag == true)
	{
		if (_x == -10000 && _y == -10000) {
			_x = x;
			_y = y;
		}
		else {
			double WW = _ImageViewer->GetColorWindow();
			double WL = _ImageViewer->GetColorLevel();
			if (_x != x) {
				WW += (x - _x);
			}
			if (_y != y) {
				WL += (y - _y);
			}
			_x = x;
			_y = y;
			_ImageViewer->SetColorWindow(WW);
			_ImageViewer->SetColorLevel(WL);
			string msg = StatusMessageWindow::Format(_ImageViewer->GetColorWindow(), _ImageViewer->GetColorLevel());
			_StatusMapperWindow->SetInput(msg.c_str());
			_ImageViewer->Render();
		}
	}
	//虚函数原内容
	else
	{
		//int x = this->Interactor->GetEventPosition()[0];
		//int y = this->Interactor->GetEventPosition()[1];
		switch (this->State)
		{
			//case VTKIS_WINDOW_LEVEL:
			//	this->FindPokedRenderer(x, y);
			//	this->WindowLevel();
			//	this->InvokeEvent(vtkCommand::InteractionEvent, nullptr);
			//	break;
			
			case VTKIS_PICK:
				this->FindPokedRenderer(x, y);
				this->Pick();
				this->InvokeEvent(vtkCommand::InteractionEvent, nullptr);
				break;

			case VTKIS_SLICE:
				this->FindPokedRenderer(x, y);
				this->Slice();
				this->InvokeEvent(vtkCommand::InteractionEvent, nullptr);
				break;
			}

			// Call parent to handle all other states and perform additional work
			this->Superclass::OnMouseMove();
	}
}