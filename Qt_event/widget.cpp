#include "widget.h"
#include "ui_widget.h"
#include<iostream>
#include<QDebug>
#include<QTimer>
using namespace std;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //启动定时器
    id1 = startTimer(1000);//参数1,间隔
    id2 = startTimer(2000);


    //定时器的第二种方式
    QTimer *timer= new QTimer(this);

    //启动定时器
    timer->start(500);

    connect(timer,&QTimer::timeout,[=]()
    {
        static int number =1;
        cout<<number;
        ui->label_4->setText(QString::number(number++));

    });


    //给label1安装事件过滤器
    ui->label->installEventFilter(this);
    //重写eventfilter

}

bool Widget::eventFilter(QObject *obj, QEvent *e)
{
    if(obj==ui->label)
    {
        if(e->type()==QEvent::MouseButtonPress)
        {
            QMouseEvent * ev = static_cast<QMouseEvent *>(e);
             QString str =QString("event 鼠标按下 x=%1  y=%2").arg(ev->x()).arg(ev->y());
             qDebug()<<str;
        }
    }
    return QWidget::eventFilter(obj,e);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *p)
{
    if(p->timerId()==id1)
    {
        static int number =1;
        cout<<number;
        ui->label_2->setText(QString::number(number++));
    }
    if(p->timerId()==id2)
    {
        static int num2 = 1;
        ui->label_3->setText(QString::number(num2++));
    }

}
