#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mybtn.h"
#include "mylabel.h"
#include "mysound.h"
#include "mysounds.h"
#include "mytext.h"
#include<QComboBox>
#include <QMainWindow>
#include <fstream>
#include<QDebug>
#include <QSound>  //音效头文件
#define MAXSIZE 22
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~MainWindow();
    void select();
    void loaddata();


    //声音
//    mysounds *sound;
    //定义路线
    QString luxian[MAXSIZE];


    //设置燕大logo
    QLabel *ysu;
    void setpic();

    //设置表面背景和动画
    void graph();

    //语音类
//    mysounds sound;

    //配置距离矩阵初始化
    void setmaxtrix();

    QStringList *dot;

    //void paint();
    int x1,x2,y1,y2;
    //画笔测试集合文件
    //   int a[4][2];

    //last点击
    int lastqi,lastzong;

    void Delay_MSec(unsigned int msec);

    //设置一个22的长度线段
    int route[MAXSIZE];

    //定义距离矩阵
    int distance[MAXSIZE][MAXSIZE];


      mylabel * p;
    QComboBox *qidian=NULL;
    QComboBox *zongdian=NULL;
    mylabel **ptr=NULL;

    //显示路线
    void settext();


    //最终路线
    QStringList list;

    //设置点击的起始点和终点
    void setStartp(int i);
    void setEndp(int i);

    //初始化Route为-1
    void InitRoute();

    //Dijkstra算法
    void Dijkstra(int v);

    //设置文本框
    MyText * Tex=NULL;

   //运行按钮
   mybtn * go=NULL;

   //总长度
   int changdu;



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
