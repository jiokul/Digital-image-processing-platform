#pragma once

#include <QWidget>
#include "ui_start.h"

class start : public QWidget
{
	Q_OBJECT

public:
	start(QWidget *parent = Q_NULLPTR);
	~start();
public:
	void OpenImg(QString OpenFile);
private:
	Ui::start ui;
};
