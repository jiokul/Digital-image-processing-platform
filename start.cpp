#include "start.h"

start::start(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

start::~start()
{
}

void start::OpenImg(QString OpenFile)
{
    QImage image;
    if (OpenFile != "")
    {
        if (image.load(OpenFile))
        {
            //仅仅只是导入之后的图片仍然是原来的大小，这个时候我们需要缩放
            ui.Sview->clear();
            ui.Sview->OnSelectImage(image);
            ui.Sview->resize(QSize(image.width(), image.height()));
        }
    }
}
