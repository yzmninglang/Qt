#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>  //包含Qwidget窗口类

class Widget : public QWidget
{
    Q_OBJECT    //Q_OBJECT宏,使之可以用信号和槽机制

public:
    Widget(QWidget *parent = 0);    //构造函数
    ~Widget();
};

#endif // WIDGET_H



