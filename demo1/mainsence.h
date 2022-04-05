#ifndef MAINSENCE_H
#define MAINSENCE_H
#include "choose.h"
#include <QMainWindow>

namespace Ui {
class mainsence;
}

class mainsence : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainsence(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~mainsence();
    choose *choosesence=NULL;

private:
    Ui::mainsence *ui;
};

#endif // MAINSENCE_H
