#include "screenShotClass.h"
#include <QtWidgets/QFileDialog>
#include <QtCore/QSettings>
#include <QDebug>

#pragma execution_character_set("utf-8")//��ʾ����

screenShotClass::screenShotClass(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

screenShotClass::~screenShotClass()
{
}

void screenShotClass::on_pushButton_clicked()
{
	fileName = ui.lineEditFileName->text();
	styleStr = ui.comboBox->currentText();
	emit SonWindowEvent(fileDir, fileName, styleStr);
	this->close();
}

void screenShotClass::on_getDirBtn_clicked() 
{
	QSettings setting("SaveFolder", "screenShotClass"); //Ϊ�˼�ס��һ�ε�·��
	fileDir = setting.value("OPEN_FOLDER", ".").toString(); //�����ڵĻ�Ϊ��ǰӦ�ó���·��	
	fileDir = QFileDialog::getExistingDirectory(this, "��ѡ���ļ���", "/");
	if (fileDir.isEmpty())
	{
		return;
	}
	ui.lineEditFileDir->setText(fileDir);
}