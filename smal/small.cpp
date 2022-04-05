#include "small.h"
#include "ui_small.h"

small::small(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::small)
{
    ui->setupUi(this);
    void(QSpinBox:: *sp)(int)= &QSpinBox::valueChanged;
    void(QSlider:: *sl)(int)= &QSlider::valueChanged;
    connect(ui->spinBox,sp,ui->horizontalSlider,&QSlider::setValue);
    connect(ui->horizontalSlider,sl,ui->spinBox,&QSpinBox::setValue);


}

small::~small()
{
    delete ui;
}
void small::setNum(int num){
    ui->spinBox->setValue(num);
}

int small::getNum(){
    return ui->spinBox->value();
}


