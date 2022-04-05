#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //TableWidget
    //设置一下列数
    ui->tableWidget->setColumnCount(3);
    //设置表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");
    //设置行数
    ui->tableWidget->setRowCount(5);

    //设置正文
    QStringList nameList;
    nameList<<"亚瑟"<<"张飞"<<"关羽"<<"花木兰"<<"uz";

    //设置性别
    QList<QString> sexList;
    sexList<<"f"<<"m"<<"f"<<"f"<<"f";
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("亚瑟"));
    for(int i=0;i<5;i++)
    {
        int col =0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sexList.at(i)));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(i+18)));
    }

}

Widget::~Widget()
{
    delete ui;
}
