#ifndef MYSOUND_H
#define MYSOUND_H
#include<QStringList>
#include <QWidget>
#include<QSound>
#include<QThread>
#include<QDebug>
class mysound:  public QWidget
{
public:
    mysound(QWidget *parent = nullptr);

//    mysound( * parent);
    ~mysound();

    //停止
    void stop();

    //路线
    void start();
    QStringList list;
    QStringList soudlist;
    void audio();
    QSound *sound=NULL;


    //设置tag
//    void settag();
    //设置tag,判断中断
    int tag;
signals:
    void finish();

};

#endif // MYSOUND_H
