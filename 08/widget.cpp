#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //栈控件
    //scrollArea

    //设置默认第一个页面
    ui->tabWidget->setCurrentIndex(1);

    connect(ui->Btn1,&QPushButton::clicked,[=]()
    {
        ui->tabWidget->setCurrentIndex(1);
    });

   connect(ui->Btn2,&QPushButton::clicked,[=]()
   {
       ui->tabWidget->setCurrentIndex(0);
   });

   //下拉框
   ui->comboBox->addItem("宝马");
   ui->comboBox->addItem("奔驰");
   ui->comboBox->addItem("哥的");

   //点击按钮选择哥的
   connect(ui->select,&QPushButton::clicked,[=]()
   {
       //ui->comboBox->setCurrentIndex(2);
       ui->comboBox->setCurrentText("哥的");
   });

   //利用label
   ui->label->setPixmap(QPixmap(":/image/cpp.png"));
   QMovie *movie = new QMovie(":/image/R.gif");
   ui->label_2->setMovie(movie);
   movie->start();
}

Widget::~Widget()
{
    delete ui;
}
