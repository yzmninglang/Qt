#include "mybutton.h"
#include<QDebug>
#include<QPropertyAnimation>

//mybutton::mybutton(QWidget *parent) : QPushButton(parent)
//{


//}
mybutton::mybutton(QString normalImg,QString pressImg)
{
    this->normalImgPath=normalImg;
    this->pressImg=pressImg;


    QPixmap pix;
    bool ret=pix.load(normalImg);
    if(!ret)
    {
        qDebug()<<"fail";
        return;
    }

    //设置图片固定大小
    this->setFixedSize(pix.width(),pix.height());

    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");


    //设置图标
    this->setIcon(pix);

    //设置图标的大小
    this->setIconSize(QSize(pix.width(),pix.height()));

}
void mybutton::zoom1()
{
    //创建动画对象
    QPropertyAnimation * animation =new QPropertyAnimation(this,"geometry");

    //创建时间间隔

    animation->setDuration(200);

    //创建起始位置

    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //创建结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));



    //设置缓和曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //开始执行动画
    animation->start();


}

void mybutton::zoom2()
{
    //创建动画对象
    QPropertyAnimation * animation =new QPropertyAnimation(this,"geometry");

    //创建时间间隔

    animation->setDuration(200);

    //创建起始位置

    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

    //创建结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));



    //设置缓和曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //开始执行动画
    animation->start();

}

void mybutton:: mousePressEvent(QMouseEvent *e)
{
    if(pressImg!=NULL)
    {
        QPixmap pix;
        bool ret=pix.load(this->pressImg);
        if(!ret)
        {
            qDebug()<<"fail";
            return;
        }

        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());

        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");


        //设置图标
        this->setIcon(pix);

        //设置图标的大小
        this->setIconSize(QSize(pix.width(),pix.height()));

    }
    //让父类执行下面操作
    return QPushButton::mousePressEvent(e);
}


void mybutton:: mouseReleaseEvent(QMouseEvent *e)
{
    if(pressImg!=NULL)
    {
        QPixmap pix;
        bool ret=pix.load(this->normalImgPath);
        if(!ret)
        {
            qDebug()<<"fail";
            return;
        }

        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());

        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");


        //设置图标
        this->setIcon(pix);

        //设置图标的大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mouseReleaseEvent(e);
}
