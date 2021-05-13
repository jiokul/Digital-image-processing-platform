#include "screenShotClass.h"
#include <QtWidgets/QFileDialog>
#include <QtCore/QSettings>
#include <QDebug>

#pragma execution_character_set("utf-8")//显示中文

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
	QSettings setting("SaveFolder", "screenShotClass"); //为了记住上一次的路径
	fileDir = setting.value("OPEN_FOLDER", ".").toString(); //不存在的话为当前应用程序路径	
	fileDir = QFileDialog::getExistingDirectory(this, "请选择文件夹", "/");
	if (fileDir.isEmpty())
	{
		return;
	}
	ui.lineEditFileDir->setText(fileDir);
}