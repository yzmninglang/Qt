#include "widget.h"
#include <QApplication>
//argc命令行变量的数量   argv命令行变量的数组
int main(int argc, char *argv[])
{
    //应用程序对象
    QApplication a(argc, argv);
    //窗口对象  Widget ->Qwidget
    Widget w;
    //窗口对象默认不显示,必须调用show方法
    w.show();

    //让程序对象进入消息循环机制
    return a.exec();
}
