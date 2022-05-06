#ifndef APPINSTALL_H
#define APPINSTALL_H

#include <QObject>
#include <QThread>
#include "fqaospcore.h"
class APPINSTALL : public QObject
{
    Q_OBJECT
public:
    explicit APPINSTALL(QObject *parent = nullptr);
    APPINSTALL(QString *devname,QList<QString> *list, QList<bool> *blist);
private:
    QString *devname;
    QList<QString> *list;
    QList<bool> *blist;

public slots:
  void Start();

signals:
  void Finished();

};

#endif // APPINSTALL_H
