#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击新建按钮,弹出对话框
    connect(ui->actionnew,&QAction::triggered,this,[=]()
    {
        //弹出对话框 模态(不可对其他窗口进行操作),非模态(可以操作其他窗口);
        QDialog dlg(this);
        dlg.resize(200,100);

        dlg.exec();//模态

        qDebug()<<"模态";
    });

    //非模态
    connect(ui->actionfilw,&QAction::triggered,this,[=]()
    {
//        QDialog dlg(this);//这样不行,栈上的会自动释放
       QDialog*  dialog = new QDialog(this);  //关闭时没有释放内存
       dialog->resize(200,100);
       dialog->show();
       dialog->setAttribute(Qt::WA_DeleteOnClose);

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
