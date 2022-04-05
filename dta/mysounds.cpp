#include "mysounds.h"

#include <qcoreapplication.h>

mysounds::mysounds(QWidget *parent) : QWidget(parent)
{

}

void mysounds::audio()
{
    emit begin();
    soudlist<<QString(":/audio/res/audio/xiancong.wav");
    qDebug()<<list;
    for(int i=0;i<list.length()-1;i++)
    {
        soudlist<<QString(":/audio/res/audio/%1.wav").arg(list.at(i).toInt());
        soudlist<<QString(":/audio/res/audio/through.wav");
    }
    soudlist.removeLast();
    soudlist<<QString(":/audio/res/audio/arrive.wav");
    soudlist<<QString(":/audio/res/audio/%1.wav").arg(list.at(list.length()-1).toInt());
    soudlist<<QString(":/audio/res/audio/over.wav");
    for(int i=0;i<soudlist.length();i++)
    {
        //qDebug()<<"播放中的"<<tag;
       QSound sound(soudlist.at(i),this);
       sound.play();
       while(!sound.isFinished())
       {
           QCoreApplication::processEvents();
       }
    }
    emit this->finish();
}
