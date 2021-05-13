#include "ShowAllTag.h"
#include <QtWidgets/QFileDialog>
#include <qtablewidget.h>
#include <QDebug>

#pragma execution_character_set("utf-8")//��ʾ����

ShowAllTag::ShowAllTag(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("Tag��Ϣ");
	this->setWindowState(Qt::WindowMaximized);
	connect(ui.pushButton, &QPushButton::clicked, this, &ShowAllTag::onSearch);

	ui.tableWidget->setColumnCount(3);
	ui.tableWidget->setRowCount(tagNum);
	QStringList sListHeader;
	sListHeader << "Tag ID" << "Description" << "Value";
	ui.tableWidget->setHorizontalHeaderLabels(sListHeader);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	for (int i = 0; i < tagNum; i++) {
		ui.tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(tagIdStr[i])));
		ui.tableWidget->setItem(i, 1, new QTableWidgetItem(tagDescriptionStr[i]));
	}
	ui.tableWidget->repaint();
}

ShowAllTag::~ShowAllTag()
{
}

void ShowAllTag::getDir(QString currentDir)
{
	dir = currentDir;
	
}

void ShowAllTag::showTag() 
{
	QFileInfo fi(dir);
	if (fi.isFile()) {
		readDicomFile();
	}
	else if (fi.isDir()) {
		readDicomFolder();
	}
}

string GetValues(itk::GDCMImageIO::Pointer dicomIO, const string& entryId)//��ȡ��ǩ��ֵ
{
	using Dictionary = itk::MetaDataDictionary;
	using MetaDataStringType = itk::MetaDataObject<string>;
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


void ShowAllTag::readDicomFile() 
{
	//ITK��ȡ����DICOM
	using PixelType = signed short;
	constexpr unsigned int Dimension = 2;
	using ImageType = itk::Image<PixelType, Dimension>;
	using ReaderFileType = itk::ImageFileReader<ImageType>;
	ReaderFileType::Pointer DICOMReader = ReaderFileType::New();
	DICOMReader->SetFileName(dir.toLocal8Bit().data());

	using ImageIOType = itk::GDCMImageIO;
	ImageIOType::Pointer gdcmImageIO = ImageIOType::New();
	DICOMReader->SetImageIO(gdcmImageIO);
	DICOMReader->Update();

	
	//��ȡTagֵ
	string valueStr;
	for (int i = 0; i < tagNum; i++) 
	{
		 valueStr = GetValues(gdcmImageIO, tagIdStr[i]);
		 
		 tagValueStr[i] =valueStr;
		 ui.tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(tagValueStr[i])));
	}
	ui.tableWidget->repaint();
	
}

void ShowAllTag::readDicomFolder()
{
	//ITK��ȡ
	using PixelType = signed short;
	constexpr unsigned int Dimension = 3;
	using ImageType = itk::Image<PixelType, Dimension>;
	using ImageIOType = itk::GDCMImageIO;
	ImageIOType::Pointer gdcmImageIO = ImageIOType::New();

	using NamesGeneratorType = itk::GDCMSeriesFileNames;
	NamesGeneratorType::Pointer nameGenarator = NamesGeneratorType::New();
	nameGenarator->SetDirectory(dir.toLocal8Bit().data());

	using FilenamesContainer = vector<string>;
	FilenamesContainer filenames = nameGenarator->GetInputFileNames();

	using ReaderSeriesType = itk::ImageSeriesReader<ImageType>;
	ReaderSeriesType::Pointer DICOMReader = ReaderSeriesType::New();
	DICOMReader->SetImageIO(gdcmImageIO);
	DICOMReader->SetFileNames(filenames);
	DICOMReader->SetReverseOrder(true);
	DICOMReader->Update();


	//��ȡTagֵ
	string valueStr;
	for (int i = 0; i < tagNum; i++)
	{
		valueStr = GetValues(gdcmImageIO, tagIdStr[i]);

		tagValueStr[i] = valueStr;
		ui.tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(tagValueStr[i])));
	}
	ui.tableWidget->repaint();
}

void ShowAllTag::ScreenInfo(QString& text) 
{
	int rC = ui.tableWidget->rowCount();//�������    
	if ("" == text) //�ж������Ƿ�Ϊ��  
	{      
		for (int i = 0; i < rC; i++) 
		{            
			ui.tableWidget->setRowHidden(i, false);//��ʾ������        
		}    
	} 
	else 
	{        
		//��ȡ����������cell����        
		QList <QTableWidgetItem *> item = ui.tableWidget->findItems(text, Qt::MatchContains);
		for (int i = 0; i < rC; i++) 
		{            
			ui.tableWidget->setRowHidden(i, true);//����������        
		}                
		if (!item.isEmpty()) 
		{ 
			//��Ϊ��            
			for (int i = 0; i < item.count(); i++) 
			{                
				ui.tableWidget->setRowHidden(item.at(i)->row(),false);//item.at(i).row()����к�           
			}        
		}    
	}
}

void ShowAllTag::onSearch() 
{
	QString text = ui.lineEdit->text();
	ScreenInfo(text);
}