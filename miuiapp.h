#ifndef MIUIAPP_H
#define MIUIAPP_H

#include <QObject>

#include <QThread>
#include "fqaospcore.h"

class MIUIAPP : public QObject
{
    Q_OBJECT
public:
    explicit MIUIAPP(QObject *parent = nullptr);
    MIUIAPP(QString *devname);
private:
    QString *devname;

private:
    QStringList getMIUI();

public slots:
  void Start();

signals:
  void Finished();

};

#endif // MIUIAPP_H
