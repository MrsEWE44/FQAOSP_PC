#include "myuiapp.h"

MYUIAPP::MYUIAPP(QObject *parent) : QObject(parent)
{

}

MYUIAPP::MYUIAPP(QString *de)
{
    this->devname=de;
}

QStringList MYUIAPP::getMYUI()
{
    QStringList ssl;
    ssl<<"com.motorola.aiservices"<<"com.motorola.moto.overlay.personalizelauncher"<<"com.motorola.cn.voicetranslation"<<"com.motorola.discovery"<<"com.motorola.systemui.desk"<<"com.motorola.cn.searchintelligence"<<"com.thinkuem.motolc"<<"com.cmcc.gbaserver"<<"com.motorola.myscreen"<<"com.motorola.demo"<<"com.google.android.onetimeinitializer"<<"com.google.android.gsf"<<"com.lenovo.levoice_agent"<<"com.motorola.motcameradesktop"<<"com.motorola.mobiledesktop.core"<<"com.motorola.lifetimedata"<<"com.lenovo.levoice_trigger"<<"com.motorola.hiddenmenuapp"<<"com.zui.antitheft"<<"com.motorola.ccc.ota"<<"com.motorola.leanbacklauncher"<<"com.motorola.mototour"<<"com.motorola.motodisplay"<<"com.motorola.help"<<"com.baidu.map.location"<<"com.motorola.gamemode"<<"com.google.android.gms"<<"com.motorola.genie"<<"com.lenovo.lsf"<<"com.motorola.moto"<<"com.motorola.mobiledesktop"<<"com.android.vending"<<"com.lenovo.leos.appstore"<<"com.lenovo.lsf.device"<<"com.lenovo.leos.cloud.sync"<<"com.zui.browser"<<"com.zui.xlog";

   return ssl;
}

void MYUIAPP::Start()
{
    fqaospCore fqcore;
    foreach(QString pkgname,getMYUI()){
        fqcore.uninstallpkg(pkgname,this->devname);
    }
    emit Finished();
}
