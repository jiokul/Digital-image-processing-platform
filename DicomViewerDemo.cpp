#include "DicomViewerDemo.h"
#include <vtkSmartPointer.h>
#include <vtkImageViewer2.h>
#include <vtkDICOMImageReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkTextProperty.h>
#include <vtkTextMapper.h>
#include <vtkCommand.h>
#include <vtkImageMapper.h>
#include <vtkInteractorStyleImage.h>
#include <QtWidgets/QFileDialog>
#include <QtCore/QSettings>
#include <QPushButton>
#include <QStandardItemModel>
#include <ui_DicomViewerDemo.h>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QMessageBox>
#include <QDebug>
#include <string>
#include <QScreen>
#include <QPixmap>
#include <QWidget>
#include "Binarization.h"
#include "Binariza.h"
#include "grayview.h"
#include "start.h"
#include "SmoothGauss.h"
#include "canny.h"
#include "Egary.h"
#include "RGBEquation.h"
#include "Gpicture.h"
#include "start2.h"
#include "sharpen.h"
#include "SAVE.h"
#include "Binariza_turn.h"
#include "Invert_colour.h"
#include "blur.h".
#include "Prewitt.h"
#include "HSIEquation.h"
#include "DoubleThreshold.h"
#include "DoubleSubmit.h"
#include "HSVEquation.h"
using namespace std;
QString openfile;
QString filepath;
int  judgement = 1;
#pragma execution_character_set("utf-8")//��ʾ����
DicomViewerDemo::DicomViewerDemo(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("����ͼ����ƽ̨");
	connect(ui.actionOTSU, SIGNAL(triggered()), this, SLOT(openB()));
	connect(ui.actionGray, SIGNAL(triggered()), this, SLOT(openG()));
	connect(ui.actionopen, SIGNAL(triggered()), this, SLOT(open()));
	connect(ui.actionSmoothGauss, SIGNAL(triggered()), this, SLOT(openS()));
	connect(ui.actionCanny, SIGNAL(triggered()), this, SLOT(openC()));
	connect(ui.actionEgray, SIGNAL(triggered()), this, SLOT(openE()));
	connect(ui.RGBEaction, SIGNAL(triggered()), this, SLOT(openRGBE()));
	connect(ui.actionGRAYPICTURE, SIGNAL(triggered()), this, SLOT(openGP()));
	connect(ui.actionOpenFile, SIGNAL(triggered()), this, SLOT(open2()));
	connect(ui.actionQuit_2, SIGNAL(triggered()), this, SLOT(on_actionQuit_2_triggered()));
	connect(ui.actionsharpen, SIGNAL(triggered()), this, SLOT(openSH()));
	connect(ui.actionSAVE, SIGNAL(triggered()), this, SLOT(save()));
	connect(ui.actionFANOTSU, SIGNAL(triggered()), this, SLOT(openBT()));
	connect(ui.actionANTICHROMIC, SIGNAL(triggered()), this, SLOT(openI()));
	connect(ui.actionblur, SIGNAL(triggered()), this, SLOT(openblur()));
	connect(ui.actionPrewieet, SIGNAL(triggered()), this, SLOT(openprewitt()));
	connect(ui.actionHSI, SIGNAL(triggered()), this, SLOT(openHSIequation()));
	connect(ui.actiondouble, SIGNAL(triggered()), this, SLOT(opendoubletchreshold()));
	connect(ui.actionHSV, SIGNAL(triggered()), this, SLOT(openHSVequation()));
}

DicomViewerDemo::~DicomViewerDemo()
{
}

void DicomViewerDemo::on_actionQuit_2_triggered() //�ر����
{
	qApp->quit();
}

void DicomViewerDemo::save()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "���ȴ��ļ�");
		return;
	}
	SAVE* save = new SAVE();
	save->openfile = openfile;
	save->type3 = judgement;
	save->show();
}

void DicomViewerDemo::openI()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "���ȴ��ļ�");
		return;
	}
	qDebug() << filepath;
	qDebug() << judgement;
	Invert_colour* Iimg = new Invert_colour();
	QPalette pal(Iimg->palette());
	//���ñ�����ɫ
	pal.setColor(QPalette::Background, Qt::black);
	Iimg->setAutoFillBackground(true);
	Iimg->setPalette(pal);
	Iimg->setAttribute(Qt::WA_DeleteOnClose);
	Iimg->show();
	QImage img2 = Iimg->colour(openfile, judgement);
	Iimg->_img = &img2;
	Iimg->handling(Iimg->_img);
	Iimg->OpenImg(Iimg->newimg);

}

void DicomViewerDemo::openblur()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "���ȴ��ļ�");
		return;
	}
	blur* Simg = new blur();
	QPalette pal(Simg->palette());
	//���ñ�����ɫ
	pal.setColor(QPalette::Background, Qt::black);
	Simg->setAutoFillBackground(true);
	Simg->setPalette(pal);
	Simg->setAttribute(Qt::WA_DeleteOnClose);
	Simg->show();
	QImage img2 = Simg->blurimg(openfile, judgement);
	Simg->_img = &img2;
	QImage* SmoothGaussImg1 = Simg->_img;
	Simg->img_final = Simg->getblurimg(SmoothGaussImg1);
	Simg->OpenImg(Simg->img_final);
}

void DicomViewerDemo::openprewitt()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "���ȴ��ļ�");
		return;
	}
	Prewitt* pimg = new Prewitt();
	QPalette pal(pimg->palette());
	//���ñ�����ɫ
	pal.setColor(QPalette::Background, Qt::black);
	pimg->setAutoFillBackground(true);
	pimg->setPalette(pal);
	pimg->setAttribute(Qt::WA_DeleteOnClose);
	pimg->show();
	QImage img2 = pimg->preimg(openfile, judgement);
	pimg->_img = &img2;
	pimg->grayScaleImg();
	pimg->three = pimg->Otsu(pimg->img_gray);
	qDebug() << pimg->three;
	pimg->calculate();
	//QImage* img = pimg->process(pimg->img_calulate);
	pimg->OpenImg(pimg->img_final);
}

void DicomViewerDemo::openHSIequation()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "���ȴ��ļ�");
		return;
	}
	HSIEquation* HSIimg = new HSIEquation();
	QPalette pal(HSIimg->palette());
	//���ñ�����ɫ
	pal.setColor(QPalette::Background, Qt::black);
	HSIimg->setAutoFillBackground(true);
	HSIimg->setPalette(pal);
	HSIimg->setAttribute(Qt::WA_DeleteOnClose);
	HSIimg->show();
	QImage img2 = HSIimg->HSIEimg(openfile, judgement);
	HSIimg->_img = &img2;
	HSIimg->changeimg();
	HSIimg->OpenImg(HSIimg->img_final);
}
void DicomViewerDemo::openHSVequation()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "���ȴ��ļ�");
		return;
	}
	HSVEquation* HSIimg = new HSVEquation();
	QPalette pal(HSIimg->palette());
	//���ñ�����ɫ
	pal.setColor(QPalette::Background, Qt::black);
	HSIimg->setAutoFillBackground(true);
	HSIimg->setPalette(pal);
	HSIimg->setAttribute(Qt::WA_DeleteOnClose);
	HSIimg->show();
	QImage img2 = HSIimg->HSVEimg(openfile, judgement);
	HSIimg->_img = &img2;
	HSIimg->changeimg();
	HSIimg->changeimg2();
	HSIimg->OpenImg(HSIimg->img_final1);
}
void DicomViewerDemo::opendoubletchreshold()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "���ȴ��ļ�");
		return;
	}
	DoubleSubmit* Simg = new DoubleSubmit();
	Simg->move(150, 200);
	Simg->fileName = openfile;
	Simg->type = judgement;
	Simg->show();
	/*Dimg->high = Simg->high;
	Dimg->low = Simg->low;
	QPalette pal(Dimg->palette());
	//���ñ�����ɫ
	pal.setColor(QPalette::Background, Qt::black);
	Dimg->setAutoFillBackground(true);
	Dimg->setPalette(pal);
	Dimg->setAttribute(Qt::WA_DeleteOnClose);
	Dimg->show();
	QImage img2 = Dimg->Doubleimg(openfile, judgement);
	Dimg->_img = &img2;
	Dimg->img_gray = Dimg->getcgray();
	Dimg->judgement = Simg->jud;
	Dimg->process(Dimg->img_gray);
	Dimg->OpenImg(Dimg->img_final);*/
}


/*
void DicomViewerDemo::beginScreenShot() 
{
	screenShot = new screenShotClass();
	screenShot->show();
	connect(screenShot, SIGNAL(SonWindowEvent(QString, QString, QString)), this, SLOT(saveImage(QString, QString, QString)));//�����Ӵ��ڵ��źź͸����ڵĲ�
}

void DicomViewerDemo::showTag()//��Tag����
{
	showAllTag->getDir(currentDir);
	showAllTag->showTag();
	showAllTag->show();
}


void DicomViewerDemo::on_actionXY_triggered() 
{
	imageRender->ChangeSliceOrientationXY();
}
void DicomViewerDemo::on_actionXZ_triggered()
{
	imageRender->ChangeSliceOrientationYZ();
}
void DicomViewerDemo::on_actionYZ_triggered()
{
	imageRender->ChangeSliceOrientationXZ();
}

//����λԤ�����
void DicomViewerDemo::on_actionDefault_triggered() //Ĭ��
{
	imageRender->SetWindow(0,0,0);
}
void DicomViewerDemo::on_actionLungs_triggered() //��
{
	imageRender->SetWindow(1, 1500, -400);
}
void DicomViewerDemo::on_actionBrain_triggered() //ͷ/��
{
	imageRender->SetWindow(1, 80, 40);
}
void DicomViewerDemo::on_actionAbdomen_triggered() //����
{
	imageRender->SetWindow(1, 400, 60);
}
void DicomViewerDemo::on_actionAngio_triggered() //Ѫ��
{
	imageRender->SetWindow(1, 600, 300);
}
void DicomViewerDemo::on_actionChest_triggered() //��
{
	imageRender->SetWindow(1, 400, 40);
}
void DicomViewerDemo::on_actionBone_triggered() //��
{
	imageRender->SetWindow(1, 1500, 300);
}
void DicomViewerDemo::on_actionMediastinum_triggered() //����
{
	imageRender->SetWindow(1, 400, 60);
}
void DicomViewerDemo::ChangeWindowColorByUserDefined(double WW,double WL) 
{
	imageRender->SetWindow(1, WW, WL);
}
void DicomViewerDemo::on_actionDefined_triggered() //�Զ���
{
	userDefined = new WindowColorDefined();
	userDefined->show();
	connect(userDefined, SIGNAL(SonWindowEvent(double, double)), this, SLOT(ChangeWindowColorByUserDefined(double, double)));//�����Ӵ��ڵ��źź͸����ڵĲ�
}

void DicomViewerDemo::createTreeView() 
{
	strDir[orderDir] = currentDir;
	QString s = "DICOMͼ��";
	s += to_string(orderDir).c_str();
	model->setItem(orderDir, 0, new QStandardItem(s));
	//model->setItem(orderDir, 0, new QStandardItem("��һ"));
	orderDir++;

	ui.treeView->setEditTriggers(false);
	
	//��QTreeView��Ӧ�����湹���model
	ui.treeView->setHeaderHidden(true);		//�������ر�ͷ
	ui.treeView->setModel(model);
	ui.treeView->expandAll();//չ�����нڵ�
	QObject::connect(ui.treeView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onTreeViewDobuleClicked()));
}

void DicomViewerDemo::onTreeViewDobuleClicked()
{
	//QModelIndex index = ui.treeView->currentIndex();
	int rowNum = ui.treeView->currentIndex().row();
	ui.treeView->SelectItems;//����Ϊ��ѡ��״̬
	QString qs;
	//s = index.data().toString().toStdString().substr();//ǰ����˫����
	qs = strDir[rowNum];
	QFileInfo fi(qs);
	qDebug() << qs;
	if (fi.isFile()) 
	{
		currentDir = qs;
		imageRender->renderDicomFile(qs.toLocal8Bit().data());
	}
	else if (fi.isDir()) 
	{
		currentDir = qs;
		imageRender->renderDicomFolder(qs.toLocal8Bit().data());
	}
}
*/
void DicomViewerDemo::open2()
{
	openfile = QFileDialog::getOpenFileName(this, "��ѡ���ļ�", "/", "*.dcm"); //��ȡ·��
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "���ȴ��ļ�");
		return;
	}
	qDebug() << openfile;
	start2* simg = new start2();
	judgement = 2;
	simg->setAttribute(Qt::WA_DeleteOnClose);
	simg->show();
	QPalette pal(simg->palette());
	//���ñ�����ɫ
	pal.setColor(QPalette::Background, Qt::black);
	simg->setAutoFillBackground(true);
	simg->setPalette(pal);
	QImage img = simg->startimg2(openfile, judgement);
	simg->_img = &img;
	simg->OpenImg(simg->_img);
}
void DicomViewerDemo::open()
{
	openfile = QFileDialog::getOpenFileName(this,
		"please choose an image file",
		"",
		"Image Files(*.jpg *.png *.bmp *.pgm *.pbm);;All(*.*)");
	//��ʾ��ʾͼƬ��·��
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "���ȴ��ļ�");
		return;
	}
	start* simg = new start();
	judgement = 1;
	simg->setAttribute(Qt::WA_DeleteOnClose);
	simg->show();
	QPalette pal(simg->palette());
	//���ñ�����ɫ
	pal.setColor(QPalette::Background, Qt::black);
	simg->setAutoFillBackground(true);
	simg->setPalette(pal);
	simg->OpenImg(openfile);
	//simg->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
}
void DicomViewerDemo::openG()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "���ȴ��ļ�");
		return;
	}
	qDebug() << filepath;
	qDebug() << judgement;
	grayview* gimg = new grayview();
	QPalette pal(gimg->palette());
	//���ñ�����ɫ
	pal.setColor(QPalette::Background, Qt::black);
	gimg->setAutoFillBackground(true);
	gimg->setPalette(pal);
	gimg->show();
	QImage img2 = gimg->gary(openfile,judgement);
	gimg->_img = &img2;
	gimg->img_final = gimg->grayScaleImg();
	gimg->OpenImg(gimg->img_final);
}


void DicomViewerDemo::openB()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "���ȴ��ļ�");
		return;
	}
	Binariza* Bimg = new Binariza();
	QPalette pal(Bimg->palette());
	//���ñ�����ɫ
	pal.setColor(QPalette::Background, Qt::black);
	Bimg->setAutoFillBackground(true);
	Bimg->setPalette(pal);
	Bimg->setAttribute(Qt::WA_DeleteOnClose);
	Bimg->show();
	QImage img = Bimg->binary(openfile,judgement);
	Bimg->_img = &img;
	QImage* grayImage = Bimg->grayScaleImg();
	int threshold = Bimg->Otsu(grayImage);    // ���������ֵ
	Bimg->threshold = threshold;
	qDebug() << Bimg->threshold;
	Bimg->img_final = Bimg->process(grayImage);
	Bimg->OpenImg(Bimg->img_final);
}

void DicomViewerDemo::openS()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "���ȴ��ļ�");
		return;
	}
	SmoothGauss* Simg = new SmoothGauss();
	QPalette pal(Simg->palette());
	//���ñ�����ɫ
	pal.setColor(QPalette::Background, Qt::black);
	Simg->setAutoFillBackground(true);
	Simg->setPalette(pal);
	Simg->setAttribute(Qt::WA_DeleteOnClose);
	Simg->show();
	QImage img2 = Simg->Smooth(openfile, judgement);
	Simg->_img = &img2;
	QImage* SmoothGaussImg1 = Simg->_img;
	Simg->img_final = Simg->getSmooth(SmoothGaussImg1);
	Simg->OpenImg(Simg->img_final);
}
void DicomViewerDemo::openC()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "���ȴ��ļ�");
		return;
	}
	canny* Cimg = new canny();
	QPalette pal(Cimg->palette());
	//���ñ�����ɫ
	pal.setColor(QPalette::Background, Qt::black);
	Cimg->setAutoFillBackground(true);
	Cimg->setAttribute(Qt::WA_DeleteOnClose);
	Cimg->setPalette(pal);
	Cimg->show();
	QImage img1 = Cimg->cannyimg(openfile, judgement);
	Cimg->_img = &img1;
	Cimg->grayScaleImg();
	Cimg->Smooth();
	Cimg->calculate();
	Cimg->nms();
	Cimg->bt();
	Cimg->st();
	Cimg->OpenImg(Cimg->img_st);
}
void DicomViewerDemo::openE()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "���ȴ��ļ�");
		return;
	}
	Egary* Eimg = new Egary();
	QPalette pal(Eimg->palette());
	//���ñ�����ɫ
	pal.setColor(QPalette::Background, Qt::black);
	Eimg->setAutoFillBackground(true);
	Eimg->setPalette(pal);
	Eimg->setAttribute(Qt::WA_DeleteOnClose);
	Eimg->show();
	qDebug() << 1;
	QImage img1 = Eimg->Egaryimg(openfile, judgement);
	qDebug() << 2;
	Eimg->_img = &img1;
	qDebug() << 3;
	QImage* img2 = Eimg->grayScaleImg();
	qDebug() << 4;
	Eimg->hist = Eimg->Histogram(img2);
	qDebug() << 5;
	qDebug() << Eimg->hist;
	qDebug() << 6;
	Eimg->Equaliation();
	qDebug() << 7;
	Eimg->OpenImg(Eimg->imgE);
	qDebug() << 8;
}

void DicomViewerDemo::openRGBE()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "���ȴ��ļ�");
		return;
	}
	RGBEquation* RGBimg = new RGBEquation();
	QPalette pal(RGBimg->palette());
	//���ñ�����ɫ
	pal.setColor(QPalette::Background, Qt::black);
	RGBimg->setAutoFillBackground(true);
	RGBimg->setPalette(pal);
	RGBimg->setAttribute(Qt::WA_DeleteOnClose);
	RGBimg->show();
	QImage img1 = RGBimg->RGBEimg(openfile, judgement);
	RGBimg->_img = &img1;
	RGBimg->Histogram();
	RGBimg->Equaliationr(RGBimg->rhist);
	RGBimg->Equaliationg(RGBimg->ghist);
	RGBimg->Equaliationb(RGBimg->bhist);
	RGBimg->final();
	qDebug() << RGBimg->newrhist[0];
	qDebug() << RGBimg->newghist[0];
	qDebug() << RGBimg->newbhist[0];
	RGBimg->OpenImg(RGBimg->imgE);
}

void DicomViewerDemo::openGP()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "���ȴ��ļ�");
		return;
	}
	Gpicture* gimg = new Gpicture();
	QPalette pal(gimg->palette());
	//���ñ�����ɫ
	pal.setColor(QPalette::Background, Qt::black);
	gimg->setAutoFillBackground(true);
	gimg->setPalette(pal);
	gimg->setAttribute(Qt::WA_DeleteOnClose);
	gimg->show();
	QImage img2 = gimg->gary(openfile, judgement);
	gimg->_img = &img2;
	QImage* grayImage = gimg->grayScaleImg();
	gimg->OpenImg(grayImage);
	gimg->showHistogram(grayImage);
}
void DicomViewerDemo::openSH()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "���ȴ��ļ�");
		return;
	}
	sharpen* Simg = new sharpen();
	QPalette pal(Simg->palette());
	//���ñ�����ɫ
	pal.setColor(QPalette::Background, Qt::black);
	Simg->setAutoFillBackground(true);
	Simg->setPalette(pal);
	Simg->setAttribute(Qt::WA_DeleteOnClose);
	Simg->show();
	QImage img2 = Simg->sharpenimg(openfile, judgement);
	Simg->_img = &img2;
	QImage* SmoothGaussImg1 = Simg->_img;
	Simg->img_final = Simg->getsharpenimg(SmoothGaussImg1);
	Simg->OpenImg(Simg->img_final);
}
void DicomViewerDemo::openBT()
{
	if (openfile.isEmpty())
	{
		QMessageBox::information(NULL, "error", "���ȴ��ļ�");
		return;
	}
	Binariza_turn* Bimg = new Binariza_turn();
	QPalette pal(Bimg->palette());
	//���ñ�����ɫ
	pal.setColor(QPalette::Background, Qt::black);
	Bimg->setAutoFillBackground(true);
	Bimg->setPalette(pal);
	Bimg->setAttribute(Qt::WA_DeleteOnClose);
	Bimg->show();
	QImage img = Bimg->binary(openfile, judgement);
	Bimg->_img = &img;
	QImage* grayImage = Bimg->grayScaleImg();
	int threshold = Bimg->Otsu(grayImage);    // ���������ֵ
	Bimg->threshold = threshold;
	qDebug() << Bimg->threshold;
	Bimg->img_fianl = Bimg->process(grayImage);
	Bimg->OpenImg(Bimg->img_fianl);
}

