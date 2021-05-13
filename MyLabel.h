#pragma once
#include <QObject>
#include <QLabel>

class MyLabel : public QLabel
{
public:
    explicit MyLabel(QWidget* parent = 0);
    void OnSelectImage(QString OpenFile);
    void OnSelectImage(QImage* img);

    void OnSelectImage(QImage img);

protected:
    void contextMenuEvent(QContextMenuEvent* event) override;   //�Ҽ��˵�
    void paintEvent(QPaintEvent* event);                        //QPaint��ͼ
    void wheelEvent(QWheelEvent* event) override;               //�����ֹ���
    void mousePressEvent(QMouseEvent* event) override;          //�������
    void mouseMoveEvent(QMouseEvent* event) override;           //����ɿ�
    void mouseReleaseEvent(QMouseEvent* event) override;        //��귢���¼�


private slots:
    void OnZoomInImage();       //ͼƬ�Ŵ�
    void OnZoomOutImage();      //ͼƬ��С
    void OnPresetImage();       //ͼƬ��ԭ

private:
    QImage Image;           //��ʾ��ͼƬ
    qreal ZoomValue = 1.0;  //�������ֵ
    int XPtInterval = 0;    //ƽ��X���ֵ
    int YPtInterval = 0;    //ƽ��Y���ֵ
    QPoint OldPos;          //�ɵ����λ��
    bool Pressed = false;   //����Ƿ���ѹ
    QString LocalFileName;  //ͼƬ��
};
