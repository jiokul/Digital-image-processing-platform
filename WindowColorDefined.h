#pragma once

#include <QWidget>
#include "ui_WindowColorDefined.h"

class WindowColorDefined : public QWidget
{
	Q_OBJECT

public:
	WindowColorDefined(QWidget *parent = Q_NULLPTR);
	~WindowColorDefined();

public:
	double WW = 0;
	double WL = 0;

signals:
	void SonWindowEvent(double,double);//�Ӵ��ڵ��ź�

protected slots:
	void on_pushButton_clicked();//�Ӵ��ڵ��ø����ڵĲۺ���

private:
	Ui::WindowColorDefined ui;
};
