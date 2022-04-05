#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->btn,&QPushButton::clicked,[=]()
    {
        posx+=20;

        //手动调用画图
        update();
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent * )
{
//    //实例化一个画家   //指定的是当前画画的设备
//    QPainter painter(this);

//    QPen pen(QColor(255,0,0));
//    //让画家使用这个笔
//    pen.setWidth(3);
//    painter.setPen(pen);

//    painter.drawLine(QPoint(0,0),QPoint(100,100));
//    painter.drawEllipse(QPoint(100,100),100,50);

//    //画一个矩形
//    painter.drawRect(QRect(100,100,50,50));

//    //写文字
//    painter.drawText(QRect(10,200,100,50),"好好学习,天天向上");
    //用画家来画资源图片
    if(posx>this->width())
    {
        posx=0;
    }
    QPainter painter(this);
    painter.drawPixmap(posx,10,QPixmap(":/cpp.png"));

}
