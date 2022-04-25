#ifndef VIVOAPP_H
#define VIVOAPP_H

#include <QObject>

#include <QThread>
#include "fqaospcore.h"
class VIVOAPP : public QObject
{
    Q_OBJECT
public:
    explicit VIVOAPP(QObject *parent = nullptr);
    VIVOAPP(QString *devname);
private:
    QString *devname;

private:
    QStringList getVIVO();

public slots:
  void Start();

signals:
  void Finished();
};

#endif // VIVOAPP_H
