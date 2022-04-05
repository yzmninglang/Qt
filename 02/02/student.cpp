#include "student.h"
#include<QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::Treat()
{

    qDebug()<<"请老师吃饭";
}

void Student::Treat(QString foodname)
{
    //QString->char，先转QbyteArray（.toUtf8()）,再使用data()转char * ()
    qDebug()<<foodname.toUtf8().data();
}
