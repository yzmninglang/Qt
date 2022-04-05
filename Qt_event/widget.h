#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    //重新写定时器
    void timerEvent(QTimerEvent *);

    //重写时间过滤器的事件
    bool eventFilter(QObject *watched, QEvent *event);
private:
    Ui::Widget *ui;
    int id1,id2;
};

#endif // WIDGET_H
