#include "mainsence.h"
#include "ui_mainsence.h"
#include"mybutton.h"
#include <QPainter>
#include<QDebug>
#include<QTimer>

mainsence::mainsence(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainsence)
{
    ui->setupUi(this);

    //配置场镜

    //设置固定大小，图标，标题
    setFixedSize(320,588);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("反转金币");

    //退出按钮
    connect(ui->actionquit,&QAction::triggered,this,[=]()
    {
        this->close();
    });

    //开始按钮

    mybutton *startbutoon = new mybutton(":/res/MenuSceneStartButton.png");
    startbutoon->setParent(this);
    startbutoon->move(this->width()*0.5-startbutoon->width()*0.5,this->height()*0.7);

    connect(startbutoon,&mybutton::clicked,[=]()
    {
        qDebug()<<"click";
        //做一个谈起的特效
        startbutoon->zoom1();
        startbutoon->zoom2();


        //进入到选择关卡的场镜
        //实例化管卡
        choosesence = new choose;
        connect(choosesence,&choose::chooseBack,[=]()
        {
            QTimer::singleShot(500,this,[=](){

                choosesence->hide();
                this->show();
            });

        });
        //延时进入选择关卡
        QTimer::singleShot(500,this,[=]()
        {
            this->hide();
            choosesence->show();
            //监听选择关卡返回按钮的信号
        });

    });
}
void mainsence::paintEvent(QPaintEvent *)
{
    //创建画家
    QPainter painter(this);
    //创建Qpixmap对象
    QPixmap pix;
    //加载图片
    pix.load(":/res/PlayLevelSceneBg.png");
    //绘制背景图,拉升成背景
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    //缩放图片
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    //绘制标题
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}
mainsence::~mainsence()
{
    delete ui;
}
