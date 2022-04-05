#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    ui->actionnew->setIcon(QIcon("G:\\Downloads\\Office.png"));

    //添加资源
    ui->actionnew->setIcon(QIcon(":/C.png"));
    ui->actionOK->setIcon(QIcon(":/Office.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
