#include "flymeapp.h"

FLYMEAPP::FLYMEAPP(QObject *parent) : QObject(parent)
{

}

FLYMEAPP::FLYMEAPP(QString *deve)
{
    this->devname = deve;
}

QStringList FLYMEAPP::getFLYME()
{
    QStringList ssl;
    ssl<<"com.meizu.flyme.gamecenter"<<"com.meizu.gamecenter.service"<<"com.flyme.meizu.store"<<"com.meizu.net.pedometer"<<"com.ibimuyu.lockscreen"<<"com.meizu.mcare"<<"com.meizu.alphame"<<"com.meizu.assistant"<<"com.android.browser"<<"com.meizu.flyme.easylauncher"<<"com.meizu.media.music"<<"com.meizu.net.nativelockscreen"<<"com.meizu.media.video"<<"com.meizu.voiceassistant"<<"com.meizu.net.search"<<"com.meizu.suggestion"<<"com.meizu.picker"<<"com.meizu.mznfcpay"<<"com.meizu.flymelab"<<"com.meizu.flyme.directservice"<<"com.meizu.mstore"<<"com.meizu.cloud"<<"com.meizu.account.pay"<<"com.meizu.flyme.service.find"<<"com.meizu.mzsyncservice"<<"com.meizu.flyme.update";

    return ssl;
}

void FLYMEAPP::Start()
{
    fqaospCore fqcore;
    foreach(QString pkgname,getFLYME()){
        fqcore.uninstallpkg(pkgname,this->devname);
    }
    emit Finished();
}
