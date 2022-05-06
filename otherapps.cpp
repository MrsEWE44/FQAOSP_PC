#include "otherapps.h"

OtherAPPS::OtherAPPS(QObject *parent) : QObject(parent)
{

}

OtherAPPS::OtherAPPS(QString *de)
{
    this->devname=de;
}

void OtherAPPS::Start()
{
    fqaospCore fqcore;
    foreach(QString pkgname,fqcore.getPackage3(this->devname)){
        fqcore.uninstallpkg(pkgname,this->devname);
    }
    emit Finished();
}
