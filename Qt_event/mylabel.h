#ifndef MYLABEL_H
#define MYLABEL_H
#include<QEvent>
#include<QLabel>
#include<QMouseEvent>
class mylabel: public QLabel
{
public:
    explicit mylabel(QWidget * parent=0);

    //鼠标进入
    void enterEvent(QEvent *event);

    //鼠标离开
    void leaveEvent(QEvent *event);


    //鼠标按下
    virtual void  mousePressEvent(QMouseEvent *ev);
    //鼠标释放
    virtual void mouseReleaseEvent(QMouseEvent *ev);

    //鼠标重写
    virtual void mouseMoveEvent(QMouseEvent *ev);

    //bool event(QEvent *e);




};

#endif // MYLABEL_H
