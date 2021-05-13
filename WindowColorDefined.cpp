#include "WindowColorDefined.h"
#include <qlineedit.h>

WindowColorDefined::WindowColorDefined(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

WindowColorDefined::~WindowColorDefined()
{
}

void WindowColorDefined::on_pushButton_clicked()
{
	WW = ui.lineEdit_WW->text().toDouble();
	WL = ui.lineEdit_WL->text().toDouble();
	emit SonWindowEvent(WW,WL);
	this->close();
}