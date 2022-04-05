#ifndef PLAYSENCE_H
#define PLAYSENCE_H

#include "mycoin.h"

#include <QMainWindow>

class playsence : public QMainWindow
{
    Q_OBJECT
public:
    playsence(int number);
    int levelindex;

    //重写paintevent事件
    void paintEvent(QPaintEvent *);
    int gameArray[4][4];
    mycoin * coinList[4][4];


    //是否胜利
    int vic;
signals:
    void backtolastleve();
    void victory();
public slots:
};

#endif // PLAYSENCE_H
