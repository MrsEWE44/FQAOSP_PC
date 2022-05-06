#include "fqaospcore.h"

fqaospCore::fqaospCore()
{

}

QString fqaospCore::getADB()
{
    QString adbpath="adb";
#ifdef Q_OS_WINDOWS
    adbpath=QCoreApplication::applicationDirPath()+"/platform-tools/adb.exe";
    QFile f(adbpath);
    if(f.exists()){
        return adbpath;
    }else{
        adbpath = "adb";
    }
#endif
    return  adbpath;
}

QString fqaospCore::runcmd(QStringList cmd)
{
    QString basic_cmd = "cmd.exe";
    QStringList sl;
#ifdef Q_OS_WINDOWS
    basic_cmd = "cmd.exe";
    sl << "/c" << cmd;
#else
    basic_cmd = "sh";
    sl << "-c" << cmd;
#endif
    QProcess p;
    p.start(basic_cmd,sl);
    p.waitForStarted();
    p.waitForFinished();
    QString ss = p.readAllStandardOutput();
    return ss;
}

QString fqaospCore::getADBDevices()
{
    QString rrr = runcmd({getADB(),"devices"});
    QStringList arr = rrr.split("\r\n");
    return arr[1].replace("\tdevice","");
}

QStringList fqaospCore::getPackage3(QString *devname)
{
    QString rrr = runcmd({getADB(),"-s",QString::fromUtf8(devname->toUtf8()),"shell"," pm list packages -3|cut -d':' -f2"});
    QStringList arr = rrr.split("\r\n");
    return arr;
}

QStringList fqaospCore::getAllPackage(QString *devname)
{
    QString rrr = runcmd({getADB(),"-s",QString::fromUtf8(devname->toUtf8()),"shell"," pm list packages|cut -d':' -f2"});
    QStringList arr = rrr.split("\r\n");
    return arr;
}

QStringList fqaospCore::getDisablePackage(QString *devname)
{
    QString rrr = runcmd({getADB(),"-s",QString::fromUtf8(devname->toUtf8()),"shell"," pm list packages -d|cut -d':' -f2"});
    QStringList arr = rrr.split("\r\n");
    return arr;
}

bool fqaospCore::disablepkg(QString pkgname, QString *devname)
{
    QString rrr = runcmd({getADB(),"-s",QString::fromUtf8(devname->toUtf8()),"shell"," pm disable-user " +pkgname+" && echo 0"});
    QStringList sl = rrr.split("\r\n");
    if(!sl.isEmpty() && sl.size() > 0 && sl[1] == "0"){
        return true;
    }
    return false;
}

bool fqaospCore::enablepkg(QString pkgname, QString *devname)
{
    QString rrr = runcmd({getADB(),"-s",QString::fromUtf8(devname->toUtf8()),"shell"," pm enable " +pkgname+" && echo 0"});
    QStringList sl = rrr.split("\r\n");
    if(!sl.isEmpty() && sl.size() > 0 && sl[1] == "0"){
        return true;
    }
    return false;
}

bool fqaospCore::uninstallpkg(QString pkgname,QString *devname)
{
    QString rrr = runcmd({getADB(),"-s",QString::fromUtf8(devname->toUtf8()),"shell"," pm uninstall --user 0 " +pkgname+" && echo 0"});
    QStringList sl = rrr.split("\r\n");
    if(!sl.isEmpty() && sl.size() > 0 && sl[1] == "0"){
        return true;
    }
    return false;
}

bool fqaospCore::installapk(QString apkpath, QString *devname)
{
    QString rrr = runcmd({getADB(),"-s",QString::fromUtf8(devname->toUtf8()),"install",apkpath});
    QStringList sl = rrr.split("\r\n");

    if(!sl.isEmpty() && sl.size() > 0 && sl.contains("Success")){
        return true;
    }
    return false;
}
