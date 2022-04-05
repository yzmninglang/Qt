#include "mainwindow.h"
#include<QToolBar>
#include<QPushButton>
#include<QMenuBar>
#include<QStatusBar>
#include<QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //重置窗口
    resize(600,400);


    //创建菜单栏
    QMenuBar *menu1= menuBar();

    //将菜单栏放入Mainwindows其中
    setMenuBar(menu1);


    //创建一个菜单
    QMenu * file= menu1->addMenu("你好");
    QMenu * bianjie=menu1->addMenu("边界");

    //创建菜单项目
    QAction* edit =file->addAction("编辑");
    QAction* open= file->addAction("打开");


     //添加分隔符
    file->addSeparator();
    file->addAction("打开1");


    //工具栏,可以有多个
    QToolBar *tool=new QToolBar(this);

    //放入窗口中
    addToolBar(Qt::LeftToolBarArea,tool);

    //只允许左右停靠
    tool->setAllowedAreas(Qt::RightToolBarArea | Qt::RightToolBarArea);

    //允许浮动
    tool->setFloatable(true);


    //设置移动,总开关,无论上面设置什么
    tool->setMovable(false);


    //设置工具栏内容
    tool->addAction("你好");
    tool->addAction(open);
     //添加分割线
    tool->addSeparator();
    tool->addAction(edit);
    //添加控件:按钮
    QPushButton * btn = new QPushButton("aa",this);
    tool->addWidget(btn);



    //状态栏,只能有一个
    QStatusBar * status= new QStatusBar(this);
    setStatusBar(status);
    //放标签的控件
    QLabel * label =new QLabel("提示信息",this);
    status->addWidget(label);

    QLabel * label1 =new QLabel("右侧提示信息",this);
    status->addPermanentWidget(label1);


    //铆接固件,围绕着核心固件
    QDockWidget * dock = new QDockWidget("浮动",this);
    addDockWidget(Qt::LeftDockWidgetArea,dock);


    //设置中心部件
    QTextEdit * edit1 = new QTextEdit(this);
    setCentralWidget(edit1);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
}

MainWindow::~MainWindow()
{

}
