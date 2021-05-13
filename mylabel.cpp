#include "MyLabel.h"
#include <QPainter>
#include <QDebug>
#include <QWheelEvent>
#include <QMenu>
#include <QFileDialog>

MyLabel::MyLabel(QWidget* parent) :QLabel(parent)
{

}
//QPainter��ͼ
void MyLabel::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    // ���ݴ��ڼ���Ӧ����ʾ��ͼƬ�Ĵ�С
    //int width = Image.width();
    //int height = Image.height();
   int width = qMin(Image.width(), this->width());
    int height = width * 1.0 / (Image.width() * 1.0 / Image.height());
    height = qMin(height, this->height());
    width = height * 1.0 * (Image.width() * 1.0 / Image.height());

    // ƽ��
    painter.translate(this->width() / 2 + XPtInterval, this->height() / 2 + YPtInterval);

    // ����
    painter.scale(ZoomValue, ZoomValue);

    // ����ͼ��
    QRect picRect(-width / 2, -height / 2, width, height);
    painter.drawImage(picRect, Image);
}
//�����ֹ���
void MyLabel::wheelEvent(QWheelEvent* event)
{
    int value = event->delta();
    if (value > 0)  //�Ŵ�
        OnZoomInImage();
    else            //��С
        OnZoomOutImage();

    update();
}
//�������
void MyLabel::mousePressEvent(QMouseEvent* event)
{
    OldPos = event->pos();
    Pressed = true;
}
//����ɿ�
void MyLabel::mouseMoveEvent(QMouseEvent* event)
{
    if (!Pressed)
        return QWidget::mouseMoveEvent(event);

    this->setCursor(Qt::SizeAllCursor);
    QPoint pos = event->pos();
    int xPtInterval = pos.x() - OldPos.x();
    int yPtInterval = pos.y() - OldPos.y();

    XPtInterval += xPtInterval;
    YPtInterval += yPtInterval;

    OldPos = pos;
    update();
}
//��귢���¼�
void MyLabel::mouseReleaseEvent(QMouseEvent*/*event*/)
{
    Pressed = false;
    setCursor(Qt::ArrowCursor);
}
//ѡ���ͼƬ
void MyLabel::OnSelectImage(QString OpenFile)
{
    LocalFileName = OpenFile;
    QFile file(LocalFileName);
    Image.load(LocalFileName);
    if (!file.exists())
        return;
    ZoomValue = 1.0;
    XPtInterval = 0;
    YPtInterval = 0;
    update();
}
void MyLabel::OnSelectImage(QImage* img)
{
    Image = *img;
    ZoomValue = 1.0;
    XPtInterval = 0;
    YPtInterval = 0;
    update();
}
void MyLabel::OnSelectImage(QImage img)
{
    Image = img;
    ZoomValue = 1.0;
    XPtInterval = 0;
    YPtInterval = 0;
    update();
}
//ͼƬ�Ŵ�
void MyLabel::OnZoomInImage()
{
    ZoomValue += 0.05;
    update();
}
//ͼƬ��С
void MyLabel::OnZoomOutImage()
{
    ZoomValue -= 0.05;
    if (ZoomValue <= 0)
    {
        ZoomValue = 0.05;
        return;
    }

    update();
}
//ͼƬ��ԭ
void MyLabel::OnPresetImage()
{
    ZoomValue = 1.0;
    XPtInterval = 0;
    YPtInterval = 0;
    update();
}
//�Ҽ��˵�
void MyLabel::contextMenuEvent(QContextMenuEvent* event)
{
    QPoint pos = event->pos();
    pos = this->mapToGlobal(pos);
    QMenu* menu = new QMenu(this);

    /*   QAction* loadImage = new QAction(this);
       loadImage->setText("ѡ��ͼƬ");
       connect(loadImage, &QAction::triggered, this, &MyLabel::OnSelectImage);
       menu->addAction(loadImage);
       menu->addSeparator();*/

    QAction* zoomInAction = new QAction(this);
    zoomInAction->setText(QString::fromLocal8Bit("�Ŵ�"));
    connect(zoomInAction, &QAction::triggered, this, &MyLabel::OnZoomInImage);
    menu->addAction(zoomInAction);

    QAction* zoomOutAction = new QAction(this);
    zoomOutAction->setText(QString::fromLocal8Bit("��С"));
    connect(zoomOutAction, &QAction::triggered, this, &MyLabel::OnZoomOutImage);
    menu->addAction(zoomOutAction);

    QAction* presetAction = new QAction(this);
    presetAction->setText(QString::fromLocal8Bit("��ԭ"));
    connect(presetAction, &QAction::triggered, this, &MyLabel::OnPresetImage);
    menu->addAction(presetAction);
    menu->exec(pos);
}
