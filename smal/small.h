#ifndef SMALL_H
#define SMALL_H

#include <QWidget>

namespace Ui {
class small;
}

class small : public QWidget
{
    Q_OBJECT

public:
    explicit small(QWidget *parent = nullptr);
    ~small();
    void setNum(int num);
    int getNum();

private:
    Ui::small *ui;
};

#endif // SMALL_H
