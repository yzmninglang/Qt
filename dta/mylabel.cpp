#include "mylabel.h"
#include <QDebug>
#include <QDialog>
#include <QMouseEvent>
#include <qpropertyanimation.h>

mylabel::mylabel(int huan,int gao,QWidget *p)
{
    timer2= new QTimer(this);
    timer3= new QTimer(this);
    pa=p;
    this->tag=1;

    this->changeflag();


    this->max=4;
    this->min=1;
    this->status=1;
    //设置水平对其和垂直对其
    this->huan=huan;
    this->gao=gao;
    //初始化mylabel的大小
//    this->resize(huan,gao);
    setbackcolor(status);
//    this->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);


}

//鼠标进入
void mylabel::enterEvent(QEvent *event)
{
    setbackcolor(this->status);
    timer1= new QTimer(this);
    //启动定时器
    //qDebug()<<"进入";
    timer1->start(1500);
    connect(timer1,&QTimer::timeout,this,[=]()
    {
        //qDebug()<<"我在这";
        QLabel pic;
        QPixmap pixmap =QPixmap(QString(":/res/%1.png").arg(this->id));

        this->setFixedSize(400,200);
        this->moveto(x,y);//居中显示
        pixmap=pixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        //qDebug()<<this->status;
        this->setIcon(pixmap);
        this->raise();
        this->setIconSize(pixmap.size());

    });

//    return QLabel::enterEvent(event);
}

//鼠标离开
void mylabel::leaveEvent(QEvent *event)
{
//    //qDebug()<<"鼠标离开";
    timer1->stop();
    delete timer1;
    //qDebug()<<status;
    this->setbackcolor(status);
}


//鼠标点击
void mylabel::mousePressEvent(QMouseEvent *ev)
{
    timer1->stop();
    timer1->start(2000);
//    qDebug()<<tag;
    if(tag==1)
    {
        //        timer3->start(50);
        //        emit startp(this->id);
        if(ev->button()==Qt::LeftButton)
        {
            //设置动画
            //qDebug()<<"左键";
            timer3->start(50);
            this->status=2;
            //        setbackcolor(status);
            emit startp(this->id);
        }
        if(ev->button()==Qt::RightButton)
        {

            //启动定时器
            //qDebug()<<"右键";
            timer2->start(50);
            this->status=3;
            //        setbackcolor(status);
            emit endp(this->id);
        }
    }
    else {
       emit this->toomany();
       return;
    }
}

void mylabel::mouseReleaseEvent(QMouseEvent *ev)
{
//    timer3->stop();
    //qDebug()<<"释放";
    //qDebug()<<status;
    setbackcolor(status);

//    QLabel::mouseReleaseEvent(ev);
}

void mylabel::changetag()
{

    if(tag==1)
    {
        this->tag=0;
        qDebug()<<"wozao";
    }
    if(tag==0)
    {
        this->tag=1;
        qDebug()<<"wozao21";
    }
}



//自定义mylabel的移动
void mylabel::moveto(int x, int y)
{
    this->move(x-this->width()*0.5,y-this->height()*0.5);
}


//设置背景色,1,2,3,代表,无色,起点色,终点色,状态色
void mylabel::setbackcolor(int i)
{
    if(i==1)
    {
        //qDebug()<<this->huan;
        QPixmap pixmap =QPixmap(QString(":/qita/res/qita/touming.png"));
        this->setFixedSize(pixmap.width(),pixmap.height());
//        this->huan=pixmap.width();
//        this->gao=pixmap.height();
        this->setStyleSheet("QPushButton{border:0px;}");
        //qDebug()<<this->status;
        this->setIcon(pixmap);
        this->setIconSize(pixmap.size());
        this->moveto(x,y);
//        this->show();

    }
    else if (i==2) {
        QPixmap pixmap =QPixmap(QString(":/qita/res/qita/q1.png"));
        this->setFixedSize(pixmap.width(),pixmap.height());
//        this->huan=pixmap.width();
//        this->gao=pixmap.height();
        this->setStyleSheet("QPushButton{border:0px;}");
        //qDebug()<<this->status;
        this->setIcon(pixmap);
        this->setIconSize(pixmap.size());
        this->moveto(x,y);
//        this->show();

    }
    else if(i==3){
        QPixmap pixmap =QPixmap(QString(":/qita/res/qita/z1.png"));
        this->setFixedSize(pixmap.width(),pixmap.height());
//        this->huan=pixmap.width();
//        this->gao=pixmap.height();
        this->setStyleSheet("QPushButton{border:0px;}");
        //qDebug()<<this->status;
        this->setIcon(pixmap);
        this->setIconSize(pixmap.size());
        this->moveto(x,y);
//        this->show();
    }
}

void mylabel::changeflag()
{

    connect(timer3,&QTimer::timeout,[=]()
    {
//        //qDebug()<<QLabel::width()<<" "<<QLabel::height();
//        //qDebug()<<QLabel::x()<<" "<<QLabel::y();
        QPixmap pixmap;
        //设置终点状态

        QString str= QString(":/qita/res/qita/q%1.png").arg(this->min++);
        pixmap.load(str);
//        this->resize(pixmap.width(),pixmap.height());
        this->setFixedSize(pixmap.size());
        this->moveto(x,y);//居中显示
        //qDebug()<<this->status;
        //qDebug()<<this->status;
        this->setIcon(pixmap);
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIconSize(pixmap.size());
        //qDebug()<<"左键重置";
        //qDebug()<<this->width()<<" "<<this->height();
        if(min>4)
        {
            this->min=1;
            setbackcolor(status);
            timer3->stop();
        }
    }
);
    connect(timer2,&QTimer::timeout,[=]()
    {
        QPixmap pixmap;
        //设置起点状态
        QString str= QString(":/qita/res/qita/z%1.png").arg(this->min++);
        pixmap.load(str);
//        pixmap= pixmap.scaled(huan,gao, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        this->setFixedSize(pixmap.width(),pixmap.height());
        this->moveto(x,y);
        this->setIcon(pixmap);
        //qDebug()<<this->status;
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIconSize(pixmap.size());
        //qDebug()<<this->width()<<" "<<this->height();
        if(min>4)
        {
            //qDebug()<<"右键重置";
            this->min=1;
            setbackcolor(status);
            timer2->stop();
        }
    });



}
//设置背景色


