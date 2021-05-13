#pragma once

#include <QWidget>
#include "ui_screenShotClass.h"

#pragma execution_character_set("utf-8")//��ʾ����

class screenShotClass : public QWidget
{
	Q_OBJECT

public:
	screenShotClass(QWidget *parent = Q_NULLPTR);
	~screenShotClass();

signals:
	void SonWindowEvent(QString, QString, QString);//�Ӵ��ڵ��ź�

protected slots:
	void on_pushButton_clicked();//�Ӵ��ڵ��ø����ڵĲۺ���
	void on_getDirBtn_clicked();//��ȡ�ļ���·��

public:
	QString fileDir;//�洢·��
	QString fileName;//�ļ�����
	QString styleStr;//�ļ���ʽ

private:
	Ui::screenShotClass ui;
};
