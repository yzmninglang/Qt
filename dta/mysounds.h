#ifndef MYSOUNDS_H
#define MYSOUNDS_H

#include <QWidget>
#include<QSound>
#include<QDebug>
class mysounds : public QWidget
{
    Q_OBJECT
public:
    explicit mysounds(QWidget *parent = nullptr);
    QStringList list;
    QStringList soudlist;
    void audio();
    QSound *sound=NULL;

signals:
    void finish();
    void begin();
public slots:

};

#endif // MYSOUNDS_H
