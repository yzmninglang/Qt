#include "mypushbutton.h"
#include<QDebug>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug()<<"我的自定义按钮";

}
MyPushButton::~MyPushButton()
{
    qDebug()<<"我的按钮的析构";
}
