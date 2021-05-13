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
            //����ֻ�ǵ���֮���ͼƬ��Ȼ��ԭ���Ĵ�С�����ʱ��������Ҫ����
            ui.Sview->clear();
            ui.Sview->OnSelectImage(image);
            ui.Sview->resize(QSize(image.width(), image.height()));
        }
    }
}
