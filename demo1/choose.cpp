#include "choose.h"
#include "mybutton.h"
#include<QMenuBar>
#include<QDebug>
#include<QLabel>
choose::choose(QWidget *parent) : QMainWindow(parent)
{
    //配置选择关卡大小
    setFixedSize(320,588);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("反转金币");

    //创建菜单栏
    QMenuBar *bar= menuBar();
    setMenuBar(bar);


    //创建开始菜单
    QMenu *startMenu= bar->addMenu("开始");

    //创建退出开始项
    QAction * quit= startMenu->addAction("退出");

    //点击退出，实现退出游戏
    connect(quit,&QAction::triggered,[=]()
    {
        this->close();
    });

    //返回按钮
    mybutton *backbtn= new mybutton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backbtn->setParent(this);
    backbtn->move(this->width()-backbtn->width(),this->height()-backbtn->height());
    connect(backbtn,&mybutton::clicked,[=]()
    {
        qDebug()<<"点击";
        //告诉主场景，我返回了
        emit this->chooseBack();
    });

    //创建选择关卡的按钮

    for(int i=0;i<20;i++)
    {

        mybutton *menuButton = new mybutton(":/res/LevelIcon.png");

        //监听每一按钮的点击事件
        connect(menuButton,&mybutton::clicked,[=]()
        {
//            QString str=;
//            qDebug()<<QString("您选择的是第%1").arg(i);
            play = new playsence(i+1);
            connect(play,&playsence::backtolastleve,[=]()
            {
                //告诉choose场镜，我反悔了
                play->hide();
                this->show();
            });
            play->show();//显示场景
            this->hide();//隐藏当前界面

        });


        menuButton->setParent(this);
        menuButton->move(20+i%4*75,60+(i/4+1)*80);

        QLabel *label=new QLabel;
        label->setParent(this);
        label->setFixedSize(menuButton->width(),menuButton->height());
        label->setText(QString::number(i));
        label->move(20+i%4*75,60+(i/4+1)*80);

        //设置label文字对其方式
        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        //设置让鼠标穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }

}


void choose::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);


    //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);

}
