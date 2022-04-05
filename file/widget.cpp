#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QString>
#include<QFile>
#include<QTextCodec>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //点击信号选择文件

    connect(ui->select,&QPushButton::clicked,[=]()
    {
        QString path =QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\Administrator\\Desktop");

        //将路径放入lineedit
        ui->lineEdit->setText(path);
        QTextCodec *codec=QTextCodec::codecForName("GBK");

        //Qt默认支持utf8

        //读取内容,放入textedit
        QFile file(path);   //读取文件的地址
        file.open(QIODevice::ReadOnly);
        QByteArray array;
        while(!file.atEnd())
        {array= file.readLine();
            array +=file.readLine();
        }
        ui->textEdit->setText(array);
        //ui->textEdit->setText(array);

        //写文件
        file.close();
        file.open(QIODevice::Append);
        file.write("aaaa");
        file.close();
    });





}

Widget::~Widget()
{
    delete ui;
}
