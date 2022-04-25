#ifndef MYUIAPP_H
#define MYUIAPP_H

#include <QObject>

#include <QThread>
#include "fqaospcore.h"
class MYUIAPP : public QObject
{
    Q_OBJECT
public:
    explicit MYUIAPP(QObject *parent = nullptr);
    MYUIAPP(QString *devname);
private:
    QString *devname;

private:
    QStringList getMYUI();

public slots:
  void Start();

signals:
  void Finished();
};

#endif // MYUIAPP_H
