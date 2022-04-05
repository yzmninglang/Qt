#ifndef SINGLESLOT_H
#define SINGLESLOT_H
#include"student.h"
#include"teacher.h"
#include <QWidget>
#include<QPushButton>
namespace Ui {
class SingleSlot;
}

class SingleSlot : public QWidget
{
    Q_OBJECT

public:
    explicit SingleSlot(QWidget *parent = nullptr);
    ~SingleSlot();
    Teacher *zt;
    Student *st;
    void classover2();
    void classover();

private:
    Ui::SingleSlot *ui;
};

#endif // SINGLESLOT_H
