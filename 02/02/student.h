#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
    //Slots函数可以写在这里
signals:

public slots:
    //Slots函数可以写在这里
    //返回值是void，需要声明，需要实现，可以有参数，可以重载

    void Treat();
    void Treat(QString foodname);

};

#endif // STUDENT_H
