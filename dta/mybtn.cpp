#include "mybtn.h"

mybtn::mybtn(QPushButton *parent) : QPushButton(parent)
{
    timer1=new QTimer(this);
    timer2=new QTimer(this);
    this->pox=this->x();
    this->poy=this->y();


    //默认可以发消息
    tag=1;
    this->min=1;
    this->max=4;
    QPixmap pixmap;
    QString str= QString(":/qita/res/qita/start1.png");
    pixmap.load(str);
    pixmap=pixmap.scaled(150,70, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
    this->move(this->pox-this->width()*0.5,this->poy-this->height()*0.5);
    this->changeflag();

}

void mybtn::mousePressEvent(QMouseEvent *e)
{
    //qDebug()<<"s"<<tag;
    if(tag==1)
    {

        timer1->start(20);
/*        emit this->toomany()*/;
//        qDebug()<<tag;
        QPushButton::mousePressEvent(e);
        emit clicked();

    }
    else {
        emit this->toomany();
        timer1->start(20);
//        qDebug()<<tag;
        return;
    }
}

void mybtn::mouseReleaseEvent(QMouseEvent *e)
{
    timer2->start(20);
}

void mybtn::changeflag()
{

//    timer1->start(50);
    connect(timer1,&QTimer::timeout,[=]()
    {
        QPixmap pixmap;

        QString str= QString(":/qita/res/qita/start%1.png").arg(this->min++);
        pixmap.load(str);
        pixmap=pixmap.scaled(pixmap.width()*0.39,pixmap.height()*0.39, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        this->setFixedSize(pixmap.width(),pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->move(pox-this->width()*0.5,poy-this->height()*0.5);

        if(min>4)
        {
            this->min=1;
            timer1->stop();
        }
    });

//    timer1->start(50);
    connect(timer2,&QTimer::timeout,[=]()
    {
        QPixmap pixmap;
        QString str= QString(":/qita/res/qita/start%1.png").arg(this->max--);
        pixmap.load(str);
        pixmap=pixmap.scaled(pixmap.width()*0.39,pixmap.height()*0.39, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        this->setFixedSize(pixmap.width(),pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->move(pox-this->width()*0.5,poy-this->height()*0.5);
        if(max<1)
        {
            this->max=4;
            timer2->stop();
        }
    });

}

void mybtn::knowb()
{
    if(tag==1)
    {
        tag=0;
    }
    else {
        tag=1;
        emit this->ok();
    }

}

void mybtn::moveto()
{
    this->move(this->pox-0.5*this->width(),this->poy-0.5*this->height());
}
