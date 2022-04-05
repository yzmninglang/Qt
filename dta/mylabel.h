#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include<QLabel>
#include<QTimer>
#include<QPushButton>
class mylabel : public QPushButton
{
    Q_OBJECT
public:
//    explicit mylabel(QLabel *parent = nullptr);
    //label的宽高构造函数

    mylabel(int huan,int gao,QWidget *p=NULL);

    //parent指针
    QWidget *pa;
    //鼠标进入事件
    void enterEvent(QEvent *event);
    //离开事件
    void leaveEvent(QEvent *event);

    void mousePressEvent(QMouseEvent *ev);

    void mouseReleaseEvent(QMouseEvent *ev);
    //设置动画
    void changeflag();
    QTimer* timer2;
    QTimer* timer3;

    //图标的最大和最小
    int min,max;
    //移动至x,y,居中显示
    void moveto(int x,int y);

    //设置宽高
    int huan,gao;

    //设置id
    int id;
    //设置周边界限
    int minx,maxx,miny,maxy;

    //设置状态位1,2,3,表示,随便结点,起点,终点
    int status;

    //设置一个名字
    QString name;
    //定时器
    QTimer *timer1;


    //设置背景色,1,2,3,代表,无色,起点色,终点色
    void setbackcolor(int i);

    //设置x,y
    int x,y;


    //封锁键盘
    int tag;
signals:
    void startp(int i);
    void endp(int i);
    void toomany();

public slots:
    void changetag();
};

#endif // MYLABEL_H
