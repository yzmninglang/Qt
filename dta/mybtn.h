#ifndef MYBTN_H
#define MYBTN_H

#include <QWidget>
#include<QPushButton>
#include<QDebug>
#include<QMouseEvent>
#include<QTimer>
class mybtn : public QPushButton
{
    Q_OBJECT
public:
    explicit mybtn(QPushButton *parent = nullptr);

    int tag,min,max;
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    QTimer* timer1;
    QTimer* timer2;
    bool flag;
    int pox,poy;
    void changeflag();
    void moveto();
signals:
    void toomany();
    void ok();
public slots:

    void knowb();
};

#endif // MYBTN_H
