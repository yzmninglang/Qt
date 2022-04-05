#include "mylabel.h"
#include"QDebug"
mylabel::mylabel(QWidget * parent):QLabel(parent)
{
    //设置鼠标追踪
    setMouseTracking(true);
}

//鼠标进入
void mylabel::enterEvent(QEvent *event)
{
    qDebug()<<"鼠标进入";
}


//鼠标离开
void mylabel::leaveEvent(QEvent *event)
{
    qDebug()<<"鼠标离开";
}


//鼠标按下
void  mylabel::mousePressEvent(QMouseEvent *ev)
{
    //左键按下,提示这些
    if(ev->button()==Qt::LeftButton)
    {QString str =QString("鼠标按下 x=%1  y=%2").arg(ev->x()).arg(ev->y());
     qDebug()<<str;}

}
//鼠标释放
void mylabel::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::LeftButton)
    {qDebug()<<"鼠标释放";}
}

//鼠标重写
void mylabel::mouseMoveEvent(QMouseEvent *ev)
{
//    if(ev->buttons() && Qt::LeftButton)
//    {
        QString str =QString("鼠标移动 x=%1  y=%2").arg(ev->x()).arg(ev->y());
        qDebug()<<str;
//    }
}


