#ifndef MYCOIN_H
#define MYCOIN_H
#include<QPushButton>
#include <QTimer>
#include <QWidget>

class mycoin : public QPushButton
{
    Q_OBJECT
public:

    //传入显示的图片
    mycoin(QString buting);


    //金币的属性
    int posx;
    int posy;
    bool flag;//正反的标志
    int min;
    int max;

    //改变标志的方法
    void changeflag();
    QTimer *timer1;
    QTimer *timer2;

    //执行动画
    bool isannimation;


    //重写按下状态
    void mousePressEvent(QMouseEvent *e);


signals:

public slots:
};

#endif // MYCOIN_H
