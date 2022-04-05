#include<QPushButton>
#include "widget.h"
#include"mypushbutton.h"
#include<QDebug>
//命名规则
//类名,首字母大写,单词和单词之间首字母大写



Widget::Widget(QWidget *parent)
    : QWidget(parent) //调用父类的构造,将parent传递给父类
{
    //创建一个按钮
    QPushButton * p= new QPushButton;
    p->show();  //以顶层的方式弹出
    p->setParent(this); //让p随着父类指针显示
    p->setText("第一个按钮");

    //创建第二个按钮,父类直接传入
    QPushButton *btn2= new QPushButton("第二个按钮",this);
    btn2->move(100,100);    //移动到100,100的位置


    //按钮指定大小
    btn2->resize(100,100);


    //重置窗口大小
    resize(600,400);


    //设置固定的窗口大小
    setFixedSize(600,400);

    //设置窗口的标题
    setWindowTitle("第一个窗口");


    //创建一个自己按钮的对象
    MyPushButton * btn3= new MyPushButton();
    btn3->setText("你好");
    btn3->move(200,200);
    btn3->setParent(this);


    //我点击一下按钮，关闭窗口
    //参数一：信号的发送者；参数二：发送的信号(函数地址)；
    //参数三：信号的接受者；参数四：信号处理函数（函数地址）
    connect(btn3,&QPushButton::clicked,this,&Widget::close);
    //要使用静态函数的方式去传递函数




}

Widget::~Widget()
{
    qDebug()<<"MyWidget析构";
    //先去寻找自己挂载的对象

}
