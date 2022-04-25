#include "vivoapp.h"

VIVOAPP::VIVOAPP(QObject *parent) : QObject(parent)
{

}

VIVOAPP::VIVOAPP(QString *de)
{
    this->devname=de;
}

QStringList VIVOAPP::getVIVO()
{
    QStringList ssl;
        ssl<<"com.vivo.videoeditor"<<"com.vivo.collage"<<"com.vivo.game"<<"com.vivo.Tips"<<"com.ibimuyu.lockscreen"  "com.android.skintwo"<<"com.android.skinthree"<<"com.android.skinfive"<<"com.yozo.vivo.office"<<"com.vivo.email"<<"com.bbk.VoiceOneshot"<<"com.bbk.VoiceAssist"<<"com.vlife.vivo.wallpaper"<<"com.vivo.space"<<"com.vivo.assistant"<<"com.vivo.hiboard"<<"com.vivo.motionrecognition"<<"com.bbk.updater"<<"com.vivo.abe"<<"com.baidu.duersdk.opensdk"<<"com.bbk.account"<<"com.bbk.appstore"<<"com.bbk.cloud"<<"com.android.BBKCrontab"<<"com.android.bbklog"<<"com.android.bbkmusic"<<"com.vivo.globalsearch"<<"com.android.VideoPlayer"<<"com.vivo.findphone"<<"com.android.BBKPhoneInstructions";

        return ssl;
}

void VIVOAPP::Start()
{
    fqaospCore fqcore;
    foreach(QString pkgname,getVIVO()){
        fqcore.uninstallpkg(pkgname,this->devname);
    }
    emit Finished();
}
