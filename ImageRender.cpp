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
	/*��ʾ��Ƭ��Ϣ*/
	sliceTextProp = vtkSmartPointer<vtkTextProperty>::New();
	sliceTextMapper = vtkSmartPointer<vtkTextMapper>::New();
	sliceTextActor = vtkSmartPointer<vtkActor2D>::New();
	/*��ʾһЩTag��Ϣ*/
	tagTextProp = vtkSmartPointer<vtkTextProperty>::New();
	tagTextMapper = vtkSmartPointer<vtkTextMapper>::New();
	tagTextActor = vtkSmartPointer<vtkActor2D>::New();
	/*��ʾ����λ��Ϣ*/
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
	/*��Ƭ��ʾ*/
	if (sliceTextProp)sliceTextProp->Delete();
	if (sliceTextMapper)sliceTextMapper->Delete();
	if (sliceTextActor)sliceTextActor->Delete();

	/*һЩtag��ʾ*/
	if (tagTextProp)tagTextProp->Delete();
	if (tagTextMapper)tagTextMapper->Delete();
	if (tagTextActor)tagTextActor->Delete();

	/*����λ��ʾ*/
	if (WindowTextProp)WindowTextProp->Delete();
	if (WindowTextMapper)WindowTextMapper->Delete();
	if (WindowTextActor)WindowTextActor->Delete();
}

inline std::string GetValuesByTag(itk::GDCMImageIO::Pointer dicomIO, const std::string& entryId)//��ȡ��ǩ��ֵ
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
	//ITK��ȡ����DICOM
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


	//��ȡ����λ
	//(0028, 1050)   
	string tagWindowCenter = "0028|1050";//
	string valueWindowCenter = GetValuesByTag(gdcmImageIO, tagWindowCenter);
	if (valueWindowCenter == "0") {
		valueWindowCenter = "127.5";//Ĭ��127.5
	}
	//(0028, 1051)
	string tagWindowWidth = "0028|1051";
	string valueWindowWidth = GetValuesByTag(gdcmImageIO, tagWindowWidth);
	if (valueWindowWidth == "0") {
		valueWindowWidth = "255";//Ĭ��255
	}
	//��ȡ�������� Institution Name (0008, 0080)
	string tagInstitutionName = "0008|0080";
	string valueInstitutionName = GetValuesByTag(gdcmImageIO, tagInstitutionName);
	if (valueInstitutionName == "") {
		valueInstitutionName = "NULL";//Ĭ��
	}
	//��ȡ����ID Patient ID	(0010,0020)
	string tagPatientID = "0010|0020";
	string valuePatientID = GetValuesByTag(gdcmImageIO, tagPatientID);
	if (valuePatientID == "") {
		valuePatientID = "NULL";//Ĭ��
	}
	//��ȡ�������� Patient��s Name��0010��0010��
	string tagPatientName = "0010|0010";
	string valuePatientName = GetValuesByTag(gdcmImageIO, tagPatientName);
	if (valuePatientName == "") {
		valuePatientName = "NULL";//Ĭ��
	}
	//��ȡ�����Ա� Patient��s Sex��0010��0040��
	string tagPatientSex = "0010|0040";
	string valuePatientSex = GetValuesByTag(gdcmImageIO, tagPatientSex);
	if (valuePatientSex == "") {
		valuePatientSex = "NULL";//Ĭ��
	}
	//��ȡ������Ƭ��ʱ���� Patient��s Age��0010��1010��
	string tagPatientAge = "0010|1010";
	string valuePatientAge = GetValuesByTag(gdcmImageIO, tagPatientAge);
	if (valuePatientAge == "") {
		valuePatientAge = "NULL";//Ĭ��
	}
	//��ȡ�������� Series Description (0008,103e)
	string tagSeriesDescription = "0008|103e";
	string valueSeriesDescription = GetValuesByTag(gdcmImageIO, tagSeriesDescription);
	if (valueSeriesDescription == "") {
		valueSeriesDescription = "NULL";//Ĭ��
	}
	//��ȡ�������� Series Date (0008, 0021)
	string tagSeriesDate = "0008|0021";
	string valueSeriesDate = GetValuesByTag(gdcmImageIO, tagSeriesDate);
	if (valueSeriesDate == "") {
		valueSeriesDate = "NULL";//Ĭ��
	}else {
		//�޸������ַ���,����ָ�
		string del = ".";
		valueSeriesDate.insert(4, del);
		valueSeriesDate.insert(7, del);
	}
	//�ϲ�Tag��Ϣ
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

	// ITKתVTK
	using ImageConnector = itk::ImageToVTKImageFilter<ImageType>;
	ImageConnector::Pointer VTKImage = ImageConnector::New();
	VTKImage->SetInput(DICOMReader->GetOutput());
	VTKImage->Update();         

	//����vtk��itk��ʾͼ��ʱy���෴���˴���һ�η�ת 
	vtkImageFlip* FLIPImage = vtkImageFlip::New();
	FLIPImage->SetInputData(VTKImage->GetOutput());
	FLIPImage->SetFilteredAxis(1);
	FLIPImage->Update();

	_WindowWidth = atoi(valueWindowWidth.c_str());
	_WindowLevel = atoi(valueWindowCenter.c_str());


	imgViewer->SetInputConnection(FLIPImage->GetOutputPort());
	imgViewer->SetColorWindow(_WindowWidth);//���ô���
	imgViewer->SetColorLevel(_WindowLevel);//���ô�λ
	imgViewer->SetSliceOrientationToXY();//������Ƭ����ΪXY

	//����������ʾ����ʾ��ǰ��Ƭ
	sliceTextProp->SetFontFamilyToCourier();
	sliceTextProp->SetFontSize(20);
	sliceTextProp->SetVerticalJustificationToBottom();
	sliceTextProp->SetJustificationToLeft();

	std::string msg = StatusMessage::Format(imgViewer->GetSliceMin(), imgViewer->GetSliceMax());
	sliceTextMapper->SetInput(msg.c_str());
	sliceTextMapper->SetTextProperty(sliceTextProp);

	sliceTextActor->SetMapper(sliceTextMapper);
	sliceTextActor->SetPosition(15, 5);

	//��ʾ������ǩ  
	tagTextProp->SetFontFamilyToCourier();    
	tagTextProp->SetFontSize(20);    
	tagTextProp->SetVerticalJustificationToBottom();    
	tagTextProp->SetJustificationToLeft();     
 
	tagTextMapper->SetInput(TagShow.c_str());   
	tagTextMapper->SetTextProperty(tagTextProp);     
 
	tagTextActor->SetMapper(tagTextMapper);    
	tagTextActor->GetPositionCoordinate()->SetCoordinateSystemToNormalizedDisplay();    
	tagTextActor->GetPositionCoordinate()->SetValue(0.005, 0.85);

	//����������ʾ����ʾ����λ
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
	myInteractorStyle->SetImageViewer(imgViewer); //���ñ���ͼƬ����
	myInteractorStyle->SetStatusMapper(sliceTextMapper); //������Ƭ��������ʾ
	myInteractorStyle->SetStatusMapperWindow(WindowTextMapper); //���ô���λ��ʾ

	imgViewer->SetupInteractor(renderWindowInteractor);
	renderWindowInteractor->SetInteractorStyle(myInteractorStyle);

	//������ʾ
	imgViewer->GetRenderer()->AddActor2D(sliceTextActor);//��ʾ��Ƭ��
	string FirstMsg = StatusMessage::Format(imgViewer->GetSliceMax() * 0.5, imgViewer->GetSliceMax());
	sliceTextMapper->SetInput(FirstMsg.c_str());
	imgViewer->GetRenderer()->AddActor2D(tagTextActor);//��ʾ��ǩ��Ϣ
	imgViewer->GetRenderer()->AddActor2D(WindowTextActor);//��ʾ����λ

	imgViewer->Render();
	imgViewer->GetRenderer()->ResetCamera();
	imgViewer->Render();
}

void ImageRender::renderDicomFolder(const string& folder)
{
	qvtkWidget->show();

	//ITK��ȡ
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

	//��ȡ����λ
	//Tag��(0028, 1050)
	string tagWindowCenter = "0028|1050";
	string valueWindowCenter = GetValuesByTag(gdcmImageIO, tagWindowCenter);
	if (valueWindowCenter == "0") {
		valueWindowCenter = "127.5";//Ĭ��127.5
	}
	//Tag��(0028, 1051)
	string tagWindowWidth = "0028|1051";
	string valueWindowWidth = GetValuesByTag(gdcmImageIO, tagWindowWidth);
	if (valueWindowWidth == "0") {
		valueWindowWidth = "255";//Ĭ��255
	}
	//��ȡ�������� Institution Name (0008, 0080)
	string tagInstitutionName = "0008|0080";
	string valueInstitutionName = GetValuesByTag(gdcmImageIO, tagInstitutionName);
	if (valueInstitutionName == "") {
		valueInstitutionName = "NULL";//Ĭ��
	}
	//��ȡ����ID Patient ID	(0010,0020)
	string tagPatientID = "0010|0020";
	string valuePatientID = GetValuesByTag(gdcmImageIO, tagPatientID);
	if (valuePatientID == "") {
		valuePatientID = "NULL";//Ĭ��
	}
	//��ȡ�������� Patient��s Name��0010��0010��
	string tagPatientName = "0010|0010";
	string valuePatientName = GetValuesByTag(gdcmImageIO, tagPatientName);
	if (valuePatientName == "") {
		valuePatientName = "NULL";//Ĭ��
	}
	//��ȡ�����Ա� Patient��s Sex��0010��0040��
	string tagPatientSex = "0010|0040";
	string valuePatientSex = GetValuesByTag(gdcmImageIO, tagPatientSex);
	if (valuePatientSex == "") {
		valuePatientSex = "NULL";//Ĭ��
	}
	//��ȡ������Ƭ��ʱ���� Patient��s Age��0010��1010��
	string tagPatientAge = "0010|1010";
	string valuePatientAge = GetValuesByTag(gdcmImageIO, tagPatientAge);
	if (valuePatientAge == "") {
		valuePatientAge = "NULL";//Ĭ��
	}
	//��ȡ�������� Series Description (0008,103e)
	string tagSeriesDescription = "0008|103e";
	string valueSeriesDescription = GetValuesByTag(gdcmImageIO, tagSeriesDescription);
	if (valueSeriesDescription == "") {
		valueSeriesDescription = "NULL";//Ĭ��
	}
	//��ȡ�������� Series Date (0008, 0021)
	string tagSeriesDate = "0008|0021";
	string valueSeriesDate = GetValuesByTag(gdcmImageIO, tagSeriesDate);
	if (valueSeriesDate == "") {
		valueSeriesDate = "NULL";//Ĭ��
	}
	else {
		//�޸������ַ���,����ָ�
		string del = ".";
		valueSeriesDate.insert(4, del);
		valueSeriesDate.insert(7, del);
	}
	//�ϲ�Tag��Ϣ
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

	
	//ITKתVTK
	using ImageConnector = itk::ImageToVTKImageFilter<ImageType>;
	ImageConnector::Pointer VTKImage = ImageConnector::New();
	VTKImage->SetInput(DICOMReader->GetOutput());
	VTKImage->Update();

	//����vtk��itk��ʾͼ��ʱy���෴���˴���һ�η�ת 
	vtkImageFlip* FLIPImage = vtkImageFlip::New();
	FLIPImage->SetInputData(VTKImage->GetOutput());
	FLIPImage->SetFilteredAxis(1);//y��Ϊ1��x��Ϊ0��z��Ϊ2��
	FLIPImage->Update();

	imgViewer->SetInputConnection(FLIPImage->GetOutputPort()); //����ȡ�Ķ�����ʾ����
	imgViewer->SetColorWindow(atoi(valueWindowWidth.c_str()));//���ô���
	imgViewer->SetColorLevel(atoi(valueWindowCenter.c_str()));//���ô�λ
	_WindowWidth = imgViewer->GetColorWindow();
	_WindowLevel = imgViewer->GetColorLevel();
	imgViewer->SetSliceOrientationToXY(); //������Ƭ����ΪXY
	imgViewer->SetSlice((int)imgViewer->GetSliceMax() * 0.5); //��ͼƬ��λ���м���Ƭ

	if (!sliceTextProp)sliceTextProp = vtkSmartPointer<vtkTextProperty>::New();
	if (!sliceTextMapper)sliceTextMapper = vtkSmartPointer<vtkTextMapper>::New();
	if (!sliceTextActor)sliceTextActor = vtkSmartPointer<vtkActor2D>::New();

	//����������ʾ����ʾ��ǰ��Ƭ
	sliceTextProp->SetFontFamilyToCourier();
	sliceTextProp->SetFontSize(20);
	sliceTextProp->SetVerticalJustificationToBottom();
	sliceTextProp->SetJustificationToLeft();

	string msg = StatusMessage::Format(imgViewer->GetSliceMin(), imgViewer->GetSliceMax());
	sliceTextMapper->SetInput(msg.c_str());
	sliceTextMapper->SetTextProperty(sliceTextProp);

	sliceTextActor->SetMapper(sliceTextMapper);
	sliceTextActor->SetPosition(15, 10);

	//��ʾ������ǩ  
	tagTextProp->SetFontFamilyToCourier();
	tagTextProp->SetFontSize(20);
	tagTextProp->SetVerticalJustificationToBottom();
	tagTextProp->SetJustificationToLeft();

	tagTextMapper->SetInput(TagShow.c_str());
	tagTextMapper->SetTextProperty(tagTextProp);

	tagTextActor->SetMapper(tagTextMapper);
	tagTextActor->GetPositionCoordinate()->SetCoordinateSystemToNormalizedDisplay();
	tagTextActor->GetPositionCoordinate()->SetValue(0.005, 0.85);

	//����������ʾ����ʾ����λ
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
	myInteractorStyle->SetImageViewer(imgViewer); //���ñ���ͼƬ����
	myInteractorStyle->SetStatusMapper(sliceTextMapper); //����������ʾ
	myInteractorStyle->SetStatusMapperWindow(WindowTextMapper); //���ô���λ��ʾ

	//���ý�������
	imgViewer->SetupInteractor(renderWindowInteractor);
	renderWindowInteractor->SetInteractorStyle(myInteractorStyle);

	//������ʾ
	imgViewer->GetRenderer()->AddActor2D(sliceTextActor);//��ʾ��Ƭ��
	string FirstMsg = StatusMessage::Format(imgViewer->GetSliceMax() * 0.5, imgViewer->GetSliceMax());
	sliceTextMapper->SetInput(FirstMsg.c_str());
	imgViewer->GetRenderer()->AddActor2D(tagTextActor);//��ʾ��ǩ��Ϣ
	imgViewer->GetRenderer()->AddActor2D(WindowTextActor);//��ʾ����λ

	imgViewer->GetRenderer()->SetBackground(0.0, 0.0, 0.0); //����
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
	myInteractorStyle->SetImageViewer(imgViewer); //���ñ���ͼƬ����
	myInteractorStyle->SetStatusMapper(sliceTextMapper); //����������ʾ
	myInteractorStyle->SetStatusMapperWindow(WindowTextMapper); //���ô���λ��ʾ

	//���ý�������
	imgViewer->SetupInteractor(renderWindowInteractor);
	renderWindowInteractor->SetInteractorStyle(myInteractorStyle);

	imgViewer->GetRenderer()->AddActor2D(sliceTextActor);//��ʾ��Ƭ��
	string FirstMsg = StatusMessage::Format(imgViewer->GetSliceMax() * 0.5, imgViewer->GetSliceMax());
	sliceTextMapper->SetInput(FirstMsg.c_str());
	/////

	imgViewer->GetRenderer()->SetBackground(0.0, 0.0, 0.0); //����
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
	myInteractorStyle->SetImageViewer(imgViewer); //���ñ���ͼƬ����
	myInteractorStyle->SetStatusMapper(sliceTextMapper); //����������ʾ
	myInteractorStyle->SetStatusMapperWindow(WindowTextMapper); //���ô���λ��ʾ

	//���ý�������
	imgViewer->SetupInteractor(renderWindowInteractor);
	renderWindowInteractor->SetInteractorStyle(myInteractorStyle);

	imgViewer->GetRenderer()->AddActor2D(sliceTextActor);//��ʾ��Ƭ��
	string FirstMsg = StatusMessage::Format(imgViewer->GetSliceMax() * 0.5, imgViewer->GetSliceMax());
	sliceTextMapper->SetInput(FirstMsg.c_str());
	/////

	imgViewer->GetRenderer()->SetBackground(0.0, 0.0, 0.0); //����
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
	myInteractorStyle->SetImageViewer(imgViewer); //���ñ���ͼƬ����
	myInteractorStyle->SetStatusMapper(sliceTextMapper); //����������ʾ
	myInteractorStyle->SetStatusMapperWindow(WindowTextMapper); //���ô���λ��ʾ

	//���ý�������
	imgViewer->SetupInteractor(renderWindowInteractor);
	renderWindowInteractor->SetInteractorStyle(myInteractorStyle);

	imgViewer->GetRenderer()->AddActor2D(sliceTextActor);//��ʾ��Ƭ��
	string FirstMsg = StatusMessage::Format(imgViewer->GetSliceMax() * 0.5, imgViewer->GetSliceMax());
	sliceTextMapper->SetInput(FirstMsg.c_str());
	/////

	imgViewer->GetRenderer()->SetBackground(0.0, 0.0, 0.0); //����
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
	WindowTextMapper->SetInput(msg.c_str());//��ʾ����λ
	imgViewer->Render();
}

void myVtkInteractorStyleImage::SetImageViewer(vtkImageViewer2* imageViewer)
{
	//��λͼƬλ��
	_ImageViewer = imageViewer;
	//��Ƭ
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
	//�л���ʾ��һ����Ƭ
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
	//�л���ʾ��һ����Ƭ
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
	//������ǰ�ƣ��л���һ��
	MoveSliceForward();
}

void myVtkInteractorStyleImage::OnMouseWheelBackward()
{
	//�����ֺ��ƣ��л���һ��
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
	//�麯��ԭ����
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