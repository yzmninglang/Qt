#include "widget.h"
#include "ui_widget.h"
#include "QDebug"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->get,&QPushButton::clicked,[=]()
    {

        qDebug()<<ui->widget->getNum();
    });

    //设置到一半
    connect(ui->set,&QPushButton::clicked,[=]()
    {
        ui->widget->setNum(60);
    });
}

Widget::~Widget()
{
    delete ui;
}
