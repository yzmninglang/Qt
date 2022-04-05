#include "mycoin.h"
#include<QDebug>

mycoin::mycoin(QString buting)
{
    QPixmap pix;
    bool ret = pix.load(buting);
    if(!ret)
    {
        qDebug()<<"加载失败";
    }
    this->isannimation=false;

    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

    //初始化一下定时器对象
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    //监听正面翻翻面的信号
    min=1;max=8;
    connect(timer1,&QTimer::timeout,[=]()
    {
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->min++);
        pix.load(str);

        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        //如果翻完了,让min为1
        if(this->min>this->max)
        {
            this->min=1;
            timer1->stop();
            this->isannimation =false;
        }
    });

//    反面翻正面
    connect(timer2,&QTimer::timeout,[=]()
    {
        QPixmap pix;
        //this->max=8;
        //this->min=1;
        QString str = QString(":/res/Coin000%1.png").arg(this->max--);
        pix.load(str);

        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        //如果翻完了,让max为8
        if(this->max<this->min)
        {
            this->max=8;
            timer2->stop();
            this->isannimation =false;
        }
    });
}


//改变正反面的标志
void mycoin::changeflag()
{
    //如果是正面,翻成反面
    if(this->flag)
    {

        //开始正面翻方面
        timer1->start(30);
        isannimation =true;
        this->flag=false;
        qDebug()<<this->posx<<" "<<posy;
    }
    else
    {
        qDebug()<<this->posx<<" "<<posy;
        //开始反面翻正面
        timer2->start(30);
        isannimation =true;
        this->flag=true;
    }

}
//重写按下的转台
void mycoin::mousePressEvent(QMouseEvent *e)
{

    if(this->isannimation==true)
    {
        return;
    }
    else {
        QPushButton::mousePressEvent(e);
    }
}
