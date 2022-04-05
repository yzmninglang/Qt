#ifndef CHOOSE_H
#define CHOOSE_H

#include "playsence.h"

#include <QMainWindow>
#include<QPainter>
class choose : public QMainWindow
{
    Q_OBJECT
public:
    explicit choose(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    playsence *play;

signals:
    //写一个自定义的信号
    void chooseBack();
public slots:
};

#endif // CHOOSE_H
