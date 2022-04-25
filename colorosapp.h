#ifndef COLOROSAPP_H
#define COLOROSAPP_H

#include <QObject>
#include <QThread>
#include "fqaospcore.h"
class COLOROSAPP : public QObject
{
    Q_OBJECT
public:
    explicit COLOROSAPP(QObject *parent = nullptr);
    COLOROSAPP(QString *devname);
private:
    QString *devname;

private:
    QStringList getCOLOROS();

public slots:
  void Start();

signals:
  void Finished();


};

#endif // COLOROSAPP_H
