#ifndef OTHERAPPS_H
#define OTHERAPPS_H

#include <QObject>
#include <QThread>
#include "fqaospcore.h"
class OtherAPPS : public QObject
{
    Q_OBJECT
public:
    explicit OtherAPPS(QObject *parent = nullptr);
    OtherAPPS(QString *devname);
private:
    QString *devname;

public slots:
  void Start();

signals:
  void Finished();

};

#endif // OTHERAPPS_H
