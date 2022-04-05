#include "widget.h"
#include "ui_widget.h"
#include<QStringList>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //i->treeView->setHeader();
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄简介");
    QTreeWidgetItem *item = new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem *item1 = new QTreeWidgetItem(QStringList()<<"危险");
    QTreeWidgetItem *item2 = new QTreeWidgetItem(QStringList()<<"错误");
    //加载顶层结点
    ui->treeWidget->addTopLevelItem(item);
    ui->treeWidget->addTopLevelItem(item1);
    ui->treeWidget->addTopLevelItem(item2);

    //追加子节点
    QStringList hero1;
    hero1<<"刚被猪"<<"前排坦克";
    QTreeWidgetItem *h = new QTreeWidgetItem(hero1);
    item->addChild(h);




}

Widget::~Widget()
{
    delete ui;
}
