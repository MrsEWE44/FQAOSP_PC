#ifndef FLYMEAPP_H
#define FLYMEAPP_H

#include <QObject>
#include <QThread>
#include "fqaospcore.h"
class FLYMEAPP : public QObject
{
    Q_OBJECT
public:
    explicit FLYMEAPP(QObject *parent = nullptr);

    FLYMEAPP(QString *devname);
private:
    QString *devname;

private:
    QStringList getFLYME();

public slots:
  void Start();

signals:
  void Finished();

};

#endif // FLYMEAPP_H
