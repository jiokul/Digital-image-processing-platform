#pragma once

#include <QWidget>
#include "ui_Qsave.h"

class Qsave : public QWidget
{
	Q_OBJECT

public:
	Qsave(QWidget *parent = Q_NULLPTR);
	~Qsave();
public slots:
	void getimgway();
	void gettype2();
	void getname();
	void setimgway();
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
	QImage* final;
private:
	Ui::Qsave ui;
};
