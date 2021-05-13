#include "MyLabel.h"
#include <QPainter>
#include <QDebug>
#include <QWheelEvent>
#include <QMenu>
#include <QFileDialog>

MyLabel::MyLabel(QWidget* parent) :QLabel(parent)
{

}
//QPainter画图
void MyLabel::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    // 根据窗口计算应该显示的图片的大小
    //int width = Image.width();
    //int height = Image.height();
   int width = qMin(Image.width(), this->width());
    int height = width * 1.0 / (Image.width() * 1.0 / Image.height());
    height = qMin(height, this->height());
    width = height * 1.0 * (Image.width() * 1.0 / Image.height());

    // 平移
    painter.translate(this->width() / 2 + XPtInterval, this->height() / 2 + YPtInterval);

    // 缩放
    painter.scale(ZoomValue, ZoomValue);

    // 绘制图像
    QRect picRect(-width / 2, -height / 2, width, height);
    painter.drawImage(picRect, Image);
}
//鼠标滚轮滚动
void MyLabel::wheelEvent(QWheelEvent* event)
{
    int value = event->delta();
    if (value > 0)  //放大
        OnZoomInImage();
    else            //缩小
        OnZoomOutImage();

    update();
}
//鼠标摁下
void MyLabel::mousePressEvent(QMouseEvent* event)
{
    OldPos = event->pos();
    Pressed = true;
}
//鼠标松开
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
//鼠标发射事件
void MyLabel::mouseReleaseEvent(QMouseEvent*/*event*/)
{
    Pressed = false;
    setCursor(Qt::ArrowCursor);
}
//选择打开图片
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
//图片放大
void MyLabel::OnZoomInImage()
{
    ZoomValue += 0.05;
    update();
}
//图片缩小
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
//图片还原
void MyLabel::OnPresetImage()
{
    ZoomValue = 1.0;
    XPtInterval = 0;
    YPtInterval = 0;
    update();
}
//右键菜单
void MyLabel::contextMenuEvent(QContextMenuEvent* event)
{
    QPoint pos = event->pos();
    pos = this->mapToGlobal(pos);
    QMenu* menu = new QMenu(this);

    /*   QAction* loadImage = new QAction(this);
       loadImage->setText("选择图片");
       connect(loadImage, &QAction::triggered, this, &MyLabel::OnSelectImage);
       menu->addAction(loadImage);
       menu->addSeparator();*/

    QAction* zoomInAction = new QAction(this);
    zoomInAction->setText(QString::fromLocal8Bit("放大"));
    connect(zoomInAction, &QAction::triggered, this, &MyLabel::OnZoomInImage);
    menu->addAction(zoomInAction);

    QAction* zoomOutAction = new QAction(this);
    zoomOutAction->setText(QString::fromLocal8Bit("缩小"));
    connect(zoomOutAction, &QAction::triggered, this, &MyLabel::OnZoomOutImage);
    menu->addAction(zoomOutAction);

    QAction* presetAction = new QAction(this);
    presetAction->setText(QString::fromLocal8Bit("还原"));
    connect(presetAction, &QAction::triggered, this, &MyLabel::OnPresetImage);
    menu->addAction(presetAction);
    menu->exec(pos);
}
