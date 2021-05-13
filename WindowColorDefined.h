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
	void SonWindowEvent(double,double);//子窗口的信号

protected slots:
	void on_pushButton_clicked();//子窗口调用父窗口的槽函数

private:
	Ui::WindowColorDefined ui;
};
