#include "smallwidget.h"
#include "ui_smallwidget.h"

Smallwidget::Smallwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Smallwidget)
{
    ui->setupUi(this);
}

Smallwidget::~Smallwidget()
{
    delete ui;
}
