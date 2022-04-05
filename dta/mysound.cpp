#include "mysound.h"

#include <QCoreApplication>


mysound::mysound(QWidget *parent):QWidget(parent)
{
//    tag=0;
    //    this->audio();
}

//mysound::mysound(MainWindow *parent)
//{
//    connect(parent->go,&mybtn::clicked,[&]()
//    {
//        this->tag=1;
//    });
//}

//mysound::mysound()
//{

//}

mysound::~mysound()
{
}

void mysound::stop()
{

}

void mysound::start()
{

    this->audio();
}

void mysound::audio()
{
    soudlist<<QString(":/audio/res/audio/xiancong.wav");
    for(int i=0;i<list.length()-1;i++)
    {
        soudlist<<QString(":/audio/res/audio/%1.wav").arg(list.at(i).toInt());
        soudlist<<QString(":/audio/res/audio/through.wav");
    }
    soudlist.removeLast();
    soudlist<<QString(":/audio/res/audio/arrive.wav");
    soudlist<<QString(":/audio/res/audio/%1.wav").arg(list.at(list.length()-1).toInt());

    for(int i=0;i<soudlist.length();i++)
    {
        qDebug()<<"播放中的"<<tag;
       QSound sound(soudlist.at(i),this);
       sound.play();
       while(!sound.isFinished())
       {
           QCoreApplication::processEvents();

       }
    }
//    this->finish();



////    //先从...出发
////    sound = new QSound(":/audio/res/audio/xiancong.wav",this);
////    sound->play();

//    //判断是否播放完
//    while(!sound->isFinished())
//    {
//        QCoreApplication::processEvents();

//    }
//    delete sound;

//    sound = new QSound(QString(":/audio/res/audio/%1.wav").arg(list.at(0).toInt()),this);
//    if(sound!=NULL&& tag!=1)
//    {
//        sound->play();
//    }
//    while(!sound->isFinished())
//    {
//        QCoreApplication::processEvents();
//    }
//    qDebug()<<list.at(0);
//    for(int i =1;i<list.length()-1;i++)
//    {
//        sound = new QSound(QString(":/audio/res/audio/through.wav"),this);
//        if(sound!=NULL&& tag!=1)
//        {sound->play();}
//        while(!sound->isFinished())
//        {
//            QCoreApplication::processEvents();
//        }
//        delete sound;
//        sound = new QSound(QString(":/audio/res/audio/%1.wav").arg(list.at(i).toInt()),this);
//        if(sound!=NULL&& tag!=1)
//        { sound->play();}
//        while(!sound->isFinished())
//        {
//            QCoreApplication::processEvents();
//        }
//        delete sound;
//        //qDebug()<<list.at(i);
//    }
//    //    qDebug()<<list.at(list.length()-1);
//    sound = QSound(QString(":/audio/res/audio/arrive.wav"),this);
//    if(sound!=NULL&& tag!=1)
//    {sound->play();}
//    while(!sound->isFinished())
//    {
//        QCoreApplication::processEvents();
//    }
//    sound = new QSound(QString(":/audio/res/audio/%1.wav").arg(list.at(list.length()-1).toInt()),this);
//    if(sound!=NULL&& tag!=1)
//    {sound->play();}
//    while(!sound->isFinished())
//    {
//        QCoreApplication::processEvents();
//    }
//    delete sound;
//    //Over
//    sound = new QSound(QString(":/audio/res/audio/over.wav"),this);
//    if(sound!=NULL&& tag!=1)
//    { sound->play();
//    qDebug()<<this->tag;}
//    while(!sound->isFinished())
//    {
//        QCoreApplication::processEvents();
//    }
    //    delete sound;
}

//void mysound::settag()
//{
//    if(tag==0)
//    {
//        tag=1;
//    }

//}
