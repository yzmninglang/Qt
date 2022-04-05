#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QWidget>

namespace Ui {
class Smallwidget;
}

class Smallwidget : public QWidget
{
    Q_OBJECT

public:
    explicit Smallwidget(QWidget *parent = nullptr);
    ~Smallwidget();

private:
    Ui::Smallwidget *ui;
};

#endif // SMALLWIDGET_H
