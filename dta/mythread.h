#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QStringList>
#include <QThread>

class mythread : public QThread
{
    Q_OBJECT
public:
    mythread(QStringList );

signals:

public slots:
};

#endif // MYTHREAD_H
