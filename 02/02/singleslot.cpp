#include "singleslot.h"
#include "ui_singleslot.h"
#include<QDebug>

//自定义信号和槽

//teacher 类
//student 类
//需求：下课后，老师说饿了，学生请客吃饭


SingleSlot::SingleSlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SingleSlot)
{
    ui->setupUi(this);//ui设计函数，不用管

    //创建老师对象
    zt= new Teacher(this);//指明他们的父亲


    //创建学生对象
    st = new Student(this);

    //老师饿了，学生请客
//    connect(zt,&Teacher::hungry,st,&Student::Treat);
//    classover();
//    classover2();
    //也就是说，以后再调用zt的hungry的同时，自动调用student::treat
    //为什么要传入对象？信号和槽机制主要是想知道是谁调用的，谁回答的




    //连接带参数的信号和槽
    //重载的时候一定要去除函数地址的二义性
    //使用函数指针指向地址
    //声明函数指针解决重载的问题
    void(Teacher::*teachersignal)(QString)=&Teacher::hungry;//需要函数作用域Teacher
    void(Student::*Studentslot)(QString)=&Student::Treat;

    //连接信号和槽
    connect(zt,teachersignal,st,Studentslot);
    classover();



    //点击一个按钮，再下课
    setFixedSize(600,400);
    QPushButton *btn1= new QPushButton("Class Over",this);

    //固定窗口的大小
    setFixedSize(800,500);
    btn1->resize(100,50);
    btn1->move(100,200);

    //点击按钮，触发下课
    connect(btn1,&QPushButton::clicked,this,&SingleSlot::classover);

    //无参的信号和槽的连接（重载的情况下）
    void (Student::* st1)(void)=&Student::Treat;
    void (Teacher:: *zt1)(void)=&Teacher::hungry;

    QPushButton *btn2=new QPushButton("classover2",this);
    btn2->resize(100,50);
    btn2->move(400,200);

    //将信号和槽的关系，定义了zt和st的关系
    connect(zt,zt1,st,st1);

    //用原始的信号和函数的调用
//    connect(btn2,&QPushButton::clicked,this,&SingleSlot::classover2);


    //信号连接信号
    //connect(btn2,&QPushButton::clicked,zt,zt1);

    //connect(btn2,&QPushButton::clicked,zt,teachersignal);
    //断开信号:disconnect(对象一，类的函数地址，对象二，类的槽函数地址)
//    disconnect(btn2,&QPushButton::clicked,zt,zt1);


    //拓展
    //一个信号多个槽函数
    connect(btn2,&QPushButton::clicked,this,&SingleSlot::close);


    //多个信号连接一个槽函数
    connect(btn1,&QPushButton::clicked,this,&SingleSlot::close);

    //匿名函数
//    [btn1]()
//    {
//        btn1->setText("nihao");
//        btn2->setText("nihao");
//    }();

    //mutable修饰值传递,修改拷贝
    int m=10;
    connect(btn1,&QPushButton::clicked,this,[m]()mutable{m++;qDebug()<<m;});
    qDebug()<<m;

    QPushButton * btn3 = new QPushButton("最后一个",this);
    btn3->move(250,250);
    connect(btn3,&QPushButton::clicked,this,[=](){
    //this->close();
    st->Treat("麻辣鸭池");
    btn3->setText("aaa");
    });
}

SingleSlot::~SingleSlot()
{
    delete ui;
}
void SingleSlot::classover()
{
    //    zt->hungry();
    zt->hungry("宫保鸡丁"); //这个参数也会直接传递到st的函数之中

}

void SingleSlot::classover2()
{
    emit zt->hungry();  //emit要不要无所谓
}
