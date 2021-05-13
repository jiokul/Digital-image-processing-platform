#pragma once

#include <QWidget>
#include "ui_screenShotClass.h"

#pragma execution_character_set("utf-8")//显示中文

class screenShotClass : public QWidget
{
	Q_OBJECT

public:
	screenShotClass(QWidget *parent = Q_NULLPTR);
	~screenShotClass();

signals:
	void SonWindowEvent(QString, QString, QString);//子窗口的信号

protected slots:
	void on_pushButton_clicked();//子窗口调用父窗口的槽函数
	void on_getDirBtn_clicked();//获取文件夹路径

public:
	QString fileDir;//存储路径
	QString fileName;//文件命名
	QString styleStr;//文件格式

private:
	Ui::screenShotClass ui;
};
