#include "ShowAllTag.h"
#include <QtWidgets/QFileDialog>
#include <qtablewidget.h>
#include <QDebug>

#pragma execution_character_set("utf-8")//显示中文

ShowAllTag::ShowAllTag(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("Tag信息");
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

string GetValues(itk::GDCMImageIO::Pointer dicomIO, const string& entryId)//获取标签的值
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
	//ITK读取单张DICOM
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

	
	//获取Tag值
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
	//ITK读取
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


	//获取Tag值
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
	int rC = ui.tableWidget->rowCount();//获得行数    
	if ("" == text) //判断输入是否为空  
	{      
		for (int i = 0; i < rC; i++) 
		{            
			ui.tableWidget->setRowHidden(i, false);//显示所有行        
		}    
	} 
	else 
	{        
		//获取符合条件的cell索引        
		QList <QTableWidgetItem *> item = ui.tableWidget->findItems(text, Qt::MatchContains);
		for (int i = 0; i < rC; i++) 
		{            
			ui.tableWidget->setRowHidden(i, true);//隐藏所有行        
		}                
		if (!item.isEmpty()) 
		{ 
			//不为空            
			for (int i = 0; i < item.count(); i++) 
			{                
				ui.tableWidget->setRowHidden(item.at(i)->row(),false);//item.at(i).row()输出行号           
			}        
		}    
	}
}

void ShowAllTag::onSearch() 
{
	QString text = ui.lineEdit->text();
	ScreenInfo(text);
}