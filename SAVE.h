#pragma once

#include <QWidget>
#include "ui_SAVE.h"

class SAVE : public QWidget
{
	Q_OBJECT

public:
	SAVE(QWidget *parent = Q_NULLPTR);
	~SAVE();
public slots:
	void getimgway();
	void gettype1();
	void gettype2();
	void getname();
	void setimgway();
	void settype1();
	void settype2();
	void setname();
	void saveimg();
public:
	QString svaefile;
	QString name;
	QString openfile;
	QString type;
	int type1;
	int type2;
	int type3;
	QImage image;
	void getgray();
	void getEgary();
	void getbinarize();
	void gectcanny();
	void getblur();
	//void getqualization();
	//void gpicture();
	void getrgbequantion();
	void getsharpen();
	void getsmooth();
private:
	Ui::SAVE ui;
};
