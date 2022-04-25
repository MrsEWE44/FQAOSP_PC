#ifndef FQAOSPCORE_H
#define FQAOSPCORE_H

#include <QString>
#include <QStringList>
#include <QProcess>
#include <QFile>
#include <QDebug>
#include <QCoreApplication>

class fqaospCore
{
public:
    fqaospCore();
public:
    QString getADB();
    QString runcmd(QStringList cmd);
    QString getADBDevices();
    QStringList getPackage3(QString *devname);
    QStringList getAllPackage(QString *devname);
    QStringList getDisablePackage(QString *devname);
    bool disablepkg(QString pkgname,QString *devname);
    bool enablepkg(QString pkgname,QString *devname);
    bool uninstallpkg(QString pkgname,QString *devname);
};

#endif // FQAOSPCORE_H
