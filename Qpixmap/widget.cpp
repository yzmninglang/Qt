#include "widget.h"
#include "ui_widget.h"
#include<QPixmap>
#include<QPainter>
#include<QImage>
#include<QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //pixmap绘图

    //填充颜色

//    QPixmap pix(400,400);
//    pix.fill(Qt::white);
//    QPainter painter(&pix);
//    painter.drawEllipse(QPoint(150,150),20,20);

//    pix.save("D:\\pix.png");

    //Qimage 绘图设备
    //QImage img(300,300,QImage::Format_RGB32);


    //Qpicture 绘图设备 可以记录和重现绘图的指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);
    painter.setPen(Qt::blue);
    painter.drawEllipse(QPoint(150,150),100,100);


    painter.end();

    //保存
    pic.save("D:\\1.png");

}
void Widget::paintEvent(QPaintEvent *)
{
//    //像素点修改
//    QPainter painter(this);
//    QImage img;
//    img.load(":/C.png");
//    for (int i =50;i<100;i++)
//    {
//        for(int j=50;j<100;j++)
//        {
//            QRgb value =qRgb(255,0,0);
//            img.setPixel(i,j,value);
//        }
//    }
//    painter.drawImage(0,0,img);
    QPainter painter(this);
    //重新绘图指令
    QPicture pic;
    pic.load("D:\\1.png");
    painter.drawPicture(0,0,pic);
}

Widget::~Widget()
{
    delete ui;
}
