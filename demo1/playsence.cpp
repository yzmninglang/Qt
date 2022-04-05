#include "mybutton.h"
#include "mycoin.h"
#include "playsence.h"
#include <QDebug>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QPropertyAnimation>
#include"dataconfig.h"
#include <qpainter.h>
playsence::playsence(int number)
{
    this->levelindex = number;
    qDebug()<<QString("第%1关").arg(this->levelindex);

    //初始化固定大小

    this->setFixedSize(320,588);

    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    //设置标题
    this->setWindowTitle("翻金币");


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


    mybutton *back= new mybutton(QString(":/res/BackButton.png"),
                                 QString(":/res/BackButtonSelected.png"));

    back->setParent(this);
    //移动位置
    back->move(this->width()-back->width(),this->height()-back->height());

    connect(back,&mybutton::clicked,[=]()
    {
        emit this->backtolastleve();
        this->hide();
        qDebug()<<"来了";
    });


    //设置关卡数
    QLabel *label = new QLabel;
    label->setParent(this);

    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    //将字体设置到标签控件
    label->setFont(font);

    QString str2= QString ("Level%1").arg(this->levelindex);
    label->setText(str2);
    label->setGeometry(30,this->height()-50,120,50);

    dataConfig config;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            this->gameArray[i][j]=config.mData[this->levelindex][i][j];
        }
    }

    //设置胜利图片
    QLabel *winlabel = new QLabel;
    winlabel->setParent(this);
    QPixmap tempix;
    tempix.load(":/res/LevelCompletedDialogBg.png");
    winlabel->setGeometry(0,0,tempix.width(),tempix.height());
    winlabel->setPixmap(tempix);
    winlabel->move((this->width()-tempix.width())*0.5,-tempix.height());
    connect(this,&playsence::victory,[=]()
    {
        qDebug()<<"完成";

        QPropertyAnimation *animation = new QPropertyAnimation(winlabel,"geometry");
        //设值时间间隔
        animation->setDuration(1000);
        //设置开始位置

        animation->setStartValue(QRect(winlabel->x(),winlabel->y(),winlabel->width(),winlabel->height()));
         //设置结束位置
        animation->setEndValue(QRect(winlabel->x(),winlabel->y()+114,winlabel->width(),winlabel->height()));
        //设置缓和曲线
        animation->setEasingCurve(QEasingCurve::OutBounce);
        animation->start();
    });



    //显示金币的背景图
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            QLabel *label = new QLabel;
            label->setGeometry(0,0,50,50);
            label->setPixmap(QPixmap(":/res/BoardNode(1).png"));
            label->setParent(this);
            label->move(57+i*50,200+j*50);

            //显示金币
            mycoin * coin;

            if(this->gameArray[i][j]==1)
                 coin = new mycoin(":/res/Coin0001.png");
            else
                 coin = new mycoin(":/res/Coin0008.png");

            coin->setParent(this);
            coin->move(59+i*50,204+j*50);

            //给金币属性赋值
            coin->posx =i;
            coin->posy =j;
            coin->flag = gameArray[i][j];  //一表示正面,0表示发面

            this->coinList[i][j]=coin;
            //点击金币,进行反正
            connect(coin,&mycoin::clicked,[=]()
            {
                coin->changeflag();
                this->gameArray[i][j]=this->gameArray[i][j]==0?1:0;
                QTimer::singleShot(300,this,[=](){
                    if(coin->posx+1<4)
                    {
                        this->coinList[coin->posx+1][coin->posy]->changeflag();
                        this->gameArray[coin->posx+1][coin->posy]==this->gameArray[coin->posx+1][coin->posy]==0?1:0;
                    }
                    if(coin->posx-1>=0)
                    {
                        this->coinList[coin->posx-1][coin->posy]->changeflag();
                        this->gameArray[coin->posx-1][coin->posy]==this->gameArray[coin->posx-1][coin->posy]==0?1:0;
                    }
                    if(coin->posy+1<4)
                    {
                        this->coinList[coin->posx][coin->posy+1]->changeflag();
                        this->gameArray[coin->posx][coin->posx+1]==this->gameArray[coin->posx][coin->posy+1]==0?1:0;
                    }
                    if(coin->posy-1>=0)
                    {
                        this->coinList[coin->posx][coin->posy-1]->changeflag();
                        this->gameArray[coin->posx][coin->posx-1]==this->gameArray[coin->posx][coin->posy-1]==0?1:0;
                    }
                    this->vic=1;
                    for(int i =0;i<4;i++){
                        for(int j=0;j<4;j++)
                        {
                            vic=vic&&gameArray[i][j];
                            qDebug()<<gameArray[i][j];
                        }
                    }
                    qDebug()<<vic;
                    if(vic)
                    {
                        emit this->victory();
                    }

                });

            });

        }
    }




}

void playsence::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);


    //加载标题
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5 ,pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}
