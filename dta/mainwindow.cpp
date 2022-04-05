#include "mainwindow.h"
#include "mytext.h"
#include "ui_mainwindow.h"
#include<QThread>
#include <QFile>
#include <QPainter>
#include <qpropertyanimation.h>
#include <QGraphicsOpacityEffect>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    //设置go按键



    dot= new QStringList;

    this->setWindowFlags(this->windowFlags()&~Qt::WindowMinMaxButtonsHint);
    this->x1=1;
    this->x2=0;
    this->y1=0;
    this->y2=0;
    this->lastqi=-1;
    this->lastzong=-1;
    //新开进程
    //设置logo
    setWindowIcon(QIcon(":/res/logo.ico"));


    //设置燕大图标

    this->setpic();

    ui->setupUi(this);
    setFixedSize(1250,740);

    //定义一个ptr的数组,来装我的label
    ptr= new mylabel*[MAXSIZE];

    //先将距离矩阵配置为正无穷
    this->setmaxtrix();

    //初始化最短路径列表为-1
    InitRoute();

    this->go=new mybtn();
//    this->go->setText("开始导航");
    go->setParent(this);
    //    this->go->setGeometry(1086,600,120,100);
    go->pox=1160;
    go->poy=670;
    go->moveto();
    go->show();

    //读取label(point)
    loaddata();

    //定义起点框和终点框
    select();

    //定义文本框
    this->Tex= new MyText();
    this->Tex->setParent(this);
    this->Tex->setGeometry(1100,140,125,400);

    //设置动画等
    graph();


    //语音
    //mysound sound();
    //地点的点击


//    sound= new mysounds(this);
    //点击go

    connect(go,&mybtn::clicked,this,[&]()
    {
        for(int i=0;i<MAXSIZE;i++)
        {
            ptr[i]->tag=0;
        }

        go->knowb();

//        qDebug()<<qidian->currentIndex();
        Dijkstra(qidian->currentIndex());
        QString Line = luxian[zongdian->currentIndex()];

//        qDebug()<<Line;
        list = Line.split(",", QString::SkipEmptyParts);
        update();

        mysounds sound;
        sound.list=list;
        connect(&sound,&mysounds::finish,go,&mybtn::knowb);
        sound.audio();
    });
    connect(go,&mybtn::ok,[=]()
    {
        for(int i=0;i<MAXSIZE;i++)
        {
            ptr[i]->tag=1;
        }
    });



}

MainWindow::~MainWindow()
{
    delete ui;
}

//定义起点框和终点框
void MainWindow::select()
{
    //定义终点及其配置
    this->qidian=new QComboBox(this);
    this->qidian->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    QStringList q;
    for(int i=0;i<MAXSIZE;i++)
    {
        q<<ptr[i]->name;
    }
    this->qidian->addItems(q);
    this->qidian->move(1100,32);

    //定义终点及其配置
    this->zongdian=new QComboBox(this);
    this->zongdian->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    this->zongdian->addItems(q);
    this->zongdian->move(1100,100);
}



//载入数据
void MainWindow::loaddata()
{
    //载入点
    QFile file(":/res/Point.csv");
    file.open(QIODevice::ReadOnly);
    QStringList list;
    QTextStream in(&file);
    in.setCodec("UTF-8");
    //    qDebug()<<in.readAll();
    int index =0;
    for(int i = 0;!in.atEnd(); i++)
    {
        //qDebug()<<"I am ok";
        QString fileLine = in.readLine();
        list = fileLine.split(",", QString::SkipEmptyParts);    //根据","开分隔开每行的列
        //下面开始各个赋值
        mylabel *q= new mylabel(list.at(5).toInt()-list.at(4).toInt(),
                                list.at(7).toInt()-list.at(6).toInt(),this);//设置大小
        q->setParent(this);
        q->id=list.at(0).toInt();q->name=list.at(1);
        q->huan=list.at(5).toInt()-list.at(4).toInt(); //设置宽和高
        q->gao=list.at(7).toInt()-list.at(6).toInt();
        q->moveto(list.at(2).toInt(),list.at(3).toInt());
        q->x=list.at(2).toInt();
        q->y=list.at(3).toInt();

        //设置信号与槽函数
        connect(q,&mylabel::startp,this,&MainWindow::setStartp);
        connect(q,&mylabel::endp,this,&MainWindow::setEndp);


//        connect()

        ptr[index] =q;
        //        qDebug() << list.at(2);
        index++;
        //            qDebug()<<"I am ok";
    }

    file.close();



    //载入距离矩阵
    QFile file1(":/res/dis.csv");
    file1.open(QIODevice::ReadOnly);
    //    QStringList list;
    QTextStream in1(&file1);
    in1.setCodec("UTF-8");
    //    int index =0;
    for(int i = 0;!in1.atEnd(); i++)
    {
        QString fileLine = in1.readLine();
        list = fileLine.split(",", QString::SkipEmptyParts);
        //设置距离矩阵中的正常值
        this->distance[list.at(0).toInt()-1][list.at(1).toInt()-1]=list.at(2).toInt();
        this->distance[list.at(1).toInt()-1][list.at(0).toInt()-1]=list.at(2).toInt();
        //qDebug()<<list.at(0).toInt()-1<<" "<<list.at(1).toInt()-1<<" "<<this->distance[list.at(0).toInt()-1][list.at(1).toInt()-1];
    }
}

void MainWindow::setpic()
{
    ysu = new QLabel;
    ysu->setParent(this);
    QPixmap *pixmap = new QPixmap(QString(":/res/ysu.png"));
    ysu->resize(400,200);
    ysu->move(600,-30);//居中显示
    QPixmap pixmap1=pixmap->scaled(ysu->width(),ysu->height(),  Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ysu->setPixmap(pixmap1);
}

void MainWindow::graph()
{
    //设置导航框
    QLabel *winlabel = new QLabel;
    winlabel->setParent(this);
    //设置鼠标穿透
    winlabel->setAttribute(Qt::WA_TransparentForMouseEvents,true);
    QPixmap tempix;
    tempix.load(":/qita/res/qita/daohang.png");
    winlabel->setGeometry(0,0,tempix.width(),tempix.height());

    tempix=tempix.scaled(500,177, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    winlabel->setPixmap(tempix);

    winlabel->move((this->width()-tempix.width())*0.5,-tempix.height());
    winlabel->move(350,-300);
    QGraphicsOpacityEffect *m_pGraphicsOpacityEffect = new QGraphicsOpacityEffect(winlabel);
    m_pGraphicsOpacityEffect->setOpacity(0);
    for(int i=0;i<MAXSIZE;i++)
    {
        connect(ptr[i],&mylabel::toomany,[=]()
        {
            QPropertyAnimation *animation = new QPropertyAnimation(winlabel,"geometry");
            //设值时间间隔
            animation->setDuration(2500);
            //设置开始位置

            animation->setStartValue(QRect(350,-200,winlabel->width(),winlabel->height()));
             //设置结束位置
            animation->setEndValue(QRect(350,-30,winlabel->width(),winlabel->height()));

            //设置缓和曲线
    //        QGraphicsOpacityEffect *m_pGraphicsOpacityEffect = new QGraphicsOpacityEffect(winlabel);
    //        m_pGraphicsOpacityEffect->setOpacity(1);
            winlabel->setGraphicsEffect(m_pGraphicsOpacityEffect);


            QPropertyAnimation * m_pNameAnimation = new QPropertyAnimation(m_pGraphicsOpacityEffect,"opacity",winlabel);


            m_pNameAnimation->setStartValue(1);
            m_pNameAnimation->setEasingCurve(QEasingCurve::Linear);
            m_pNameAnimation->setEndValue(0);
            m_pNameAnimation->setDuration(5000);
            animation->setEasingCurve(QEasingCurve::OutBounce);

            m_pNameAnimation->start();
            animation->start();
        });

    }
    connect(go,&mybtn::toomany,[=]()
    {
        QPropertyAnimation *animation = new QPropertyAnimation(winlabel,"geometry");
        //设值时间间隔
        animation->setDuration(2500);
        //设置开始位置

        animation->setStartValue(QRect(350,-200,winlabel->width(),winlabel->height()));
         //设置结束位置
        animation->setEndValue(QRect(350,-30,winlabel->width(),winlabel->height()));

        //设置缓和曲线
//        QGraphicsOpacityEffect *m_pGraphicsOpacityEffect = new QGraphicsOpacityEffect(winlabel);
//        m_pGraphicsOpacityEffect->setOpacity(1);
        winlabel->setGraphicsEffect(m_pGraphicsOpacityEffect);


        QPropertyAnimation * m_pNameAnimation = new QPropertyAnimation(m_pGraphicsOpacityEffect,"opacity",winlabel);


        m_pNameAnimation->setStartValue(1);
        m_pNameAnimation->setEasingCurve(QEasingCurve::Linear);
        m_pNameAnimation->setEndValue(0);
        m_pNameAnimation->setDuration(5000);
        animation->setEasingCurve(QEasingCurve::OutBounce);

        m_pNameAnimation->start();
        animation->start();

//        QEventLoop loop;//定义一个新的事件循环
//        QTimer::singleShot(2500, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
//        loop.exec();//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出

//        m_pNameAnimation->setStartValue(1);
//        m_pNameAnimation->setDuration(2500);
//        m_pNameAnimation->setEasingCurve(QEasingCurve::OutBounce);
//        m_pNameAnimation->setEndValue(0);

//        m_pNameAnimation->start();

        //把所有按键禁用


    });
    this->setWindowTitle("ysu navigation by ninglang and his friends");
}




//配置距离矩阵初始化
void MainWindow::setmaxtrix()
{
    for(int i=0;i<MAXSIZE;i++)
    {
        for(int j=0;j<MAXSIZE;j++)
        {
            if(i!=j)
            {
                this->distance[i][j]=10000;
            }
            else
            {
                this->distance[i][j]=0;
            }

        }
    }
}



//设置路线显示
void MainWindow::settext()
{
    QString tex="路线:\n"+ptr[list.at(0).toInt()-1]->name;
    for(int i=1;i<list.length();i++)
    {
        tex=tex+"\n"+ptr[list.at(i).toInt()-1]->name;
    }
    //    qDebug()<<list.at(list.length()-1);
//        qDebug()<<"这是settext中的调用";
//        qDebug()<<this->changdu;
    tex=tex+"\n\n"+"总长度:"+QString::number(this->changdu);
    this->Tex->setText(tex);
}



//设置左键输入起点,返回显示
void MainWindow::setStartp(int i)
{
    this->qidian->setCurrentIndex(i-1);
    if(lastzong!=-1&& lastzong!=i-1)
    {

        this->ptr[lastzong]->status=1;
        list.clear();
        update();
        this->ptr[lastzong]->setbackcolor(this->ptr[lastzong]->status);
    }

    lastzong=i-1;
}

//设置右键输入终点,返回至显示
void MainWindow::setEndp(int i)
{
    this->zongdian->setCurrentIndex(i-1);
    if(lastqi!=-1&&lastqi!=i-1)
    {

        this->ptr[lastqi]->status=1;
        list.clear();
        update();
        this->ptr[lastqi]->setbackcolor(this->ptr[lastqi]->status);
    }

    lastqi=i-1;
}


//初始化Route为-1
void MainWindow::InitRoute()
{
    for(int i=0;i<MAXSIZE;i++)
    {
        route[i]=-1;
        luxian[i]= QString("");
    }
}


//Dijkstra算法
void MainWindow::Dijkstra(int v)//只需要源点v
{
    int dis[MAXSIZE]={0};
    //先清零路线
    InitRoute();
    for(int i=0;i<MAXSIZE;i++)
    {
        this->route[i]=this->distance[v][i];
        if(route[i]!=10000)
        {
            luxian[i]=QString("%1").arg(v+1)+QString(",")+QString("%1").arg(i+1);
            dis[i]=distance[v][i];
        }
        else {
            luxian[i]=QString("");
        }
    }
    for(int num=1;num<MAXSIZE;num++)
    {
        //求route的最小值
        int cout=0;
        int k=10000;

        //找出route的最小值下标
        for(int i=0;i<MAXSIZE;i++)
        {
            if(this->route[i]<k && i!=v &&route[i]!=0)
            {  k=route[i];
                cout=i;
            }
        }

        //        qDebug()<<cout;
        for(int i=0;i<MAXSIZE;i++)
        {
            if(route[i]>route[cout]+distance[cout][i] && i!=v)
            {
                route[i]=route[cout]+distance[cout][i];
                luxian[i]=luxian[cout]+QString(",")+QString("%1").arg(i+1);
                dis[i]=dis[i]+distance[cout][i];
            }
        }
        route[cout]=0;


    }


}



void MainWindow::paintEvent(QPaintEvent *)
{
    //创建画家
    QPainter painter(this);
    //创建Qpixmap对象
    QPixmap pix;
    pix.load(":/res/map.png");
    //绘制背景图
    painter.drawPixmap(0,0,pix.width(),pix.height(),pix);

    QPen pen;
    pen.setStyle(Qt::DashLine);
    pen.setColor(Qt::red);           // 设置画笔为黄色
    pen.setWidth(5);
    painter.setPen(pen);                // 设置画笔
    if(!list.isEmpty())
    {
        this->changdu=0;
        for(int i =0;i<this->list.length()-1;i++)
        {
            int x1=list.at(i).toInt()-1;//点
            int x2=list.at(i+1).toInt()-1;
            painter.drawLine(ptr[x1]->x,ptr[x1]->y,ptr[x2]->x,ptr[x2]->y);

            this->changdu+=distance[x1][x2];
            //qDebug()<<distance[x1][x2];
            x1=x2;
            x2=list.at(i+1).toInt()-1;

         }
        this->settext();

    }


}


//void MainWindow::paint()
//{
//    if(!dot->isEmpty())
//    {
//        dot->clear();
//    }
//    for(int i =0;i<this->list.length();i++)
//    {
//        int x1=list.at(i).toInt()-1;//点
//        int x=ptr[x1]->x;
//        int y=ptr[x1]->y;

//        QString xy=QString("%1,%2").arg(x).arg(y);
//        this->dot->append(xy);

////        this->update();
////        this->changdu=this->changdu+distance[x1][x2];
//    }
//    qDebug()<<*dot;
////    update();

//}
void MainWindow::Delay_MSec(unsigned int msec)
{
    QEventLoop loop;//定义一个新的事件循环
    QTimer::singleShot(msec, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
    loop.exec();//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出
}



