#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class mybutton : public QPushButton
{
    Q_OBJECT
public:
    explicit mybutton(QWidget *parent = nullptr);
    mybutton(QString normalImg,QString pressImg="");
    //正常显示图片的路径

    //成员属性，
    QString normalImgPath;
    QString pressImg;
    void zoom1();
    void zoom2();

    //重写一下按钮的按下和释放
    void mousePressEvent(QMouseEvent *e);


    void mouseReleaseEvent(QMouseEvent *e);

signals:

public slots:
};

#endif // MYBUTTON_H
