#include "colorosapp.h"

COLOROSAPP::COLOROSAPP(QObject *parent) : QObject(parent)
{

}

COLOROSAPP::COLOROSAPP(QString *deve)
{
    this->devname = deve;
}

QStringList COLOROSAPP::getCOLOROS()
{
    QStringList ssl;
    ssl<<"com.coloros.assistantscreen"<<"com.coloros.backuprestore"<<"com.coloros.backuprestore.remoteservice"<<"com.baidu.input_oppo"<<"com.coloros.childrenspace"<<"com.coloros.cloud"<<"com.coloros.colordirectservice"<<"com.coloros.directui"<<"com.mobiletools.systemhelper"<<"com.coloros.feedback"<<"com.coloros.encryption"<<"com.realme.findphone.client2"<<"com.coloros.floatassistant"<<"com.coloros.gamespace"<<"com.coloros.healthcheck"<<"com.nearme.instant.platform"<<"com.oppo.instant.local.service"<<"com.oppo.market"<<"com.nearme.atlas"<<"com.oppo.usercenter"<<"com.oppo.mimosiso"<<"com.coloros.ocrscanner"<<"com.coloros.ocrservice"<<"com.oppo.aod"<<"com.oppo.atlas"<<"com.nearme.statistics.rom"<<"com.dropboxchmod"<<"com.coloros.operationManual"<<"com.coloros.activation"<<"com.oppo.oppoportaldetect"<<"com.oppo.postmanservice"<<"com.coloros.translate.engine"<<"com.coloros.wallet"<<"com.coloros.oshare"<<"com.oppo.ota"<<"com.oppo.otaui"<<"com.oppo.ovoicemanager"<<"com.coloros.pictorial"<<"com.coloros.remoteguardservice"<<"com.nearme.romupdate"<<"com.coloros.sauhelper"<<"com.coloros.sau"<<"com.nearme.browser"<<"com.google.android.configupdater"<<"com.coloros.findmyphone"<<"com.oppo.quicksearchbox"<<"com.nearme.themestore"<<"com.oppo.music"<<"com.coloros.speechassist"<<"com.coloros.speechassist.engine"<<"com.coloros.sceneservice"<<"com.coloros.smartdrive"<<"com.coloros.video";
ssl<<"com.nearme.gamecenter"<<"com.heytap.quicksearchbox"<<"com.opos.ads"<<"com.coloros.digitalwellbeing"<<"com.realme.movieshot"<<"com.oplus.onetrace"<<"com.heytap.openid"<<"com.finshell.wallet"<<"com.heytap.music"<<"com.heytap.yoli"<<"com.coloros.translate.engine"<<"com.heytap.speechassist"<<"com.heytap.browser"<<"com.coloros.wifisecuredetect"<<"com.heytap.synergy"<<"com.heytap.pictorial"<<"com.heytap.cloud"<<"com.oppo.atlas"<<"com.coloros.healthcheck"<<"com.realme.wellbeing"<<"com.coloros.systemclone"<<"com.oplus.oscenter"<<"com.heytap.datamigration"<<"com.heytap.linker"<<"com.heytap.usercenter"<<"com.heytap.market"<<"com.coloros.apprecover"<<"com.coloros.safecenter"<<"com.coloros.bootreg"<<"com.coloros.regservice"<<"com.coloros.activation"<<"com.coloros.pictorial"<<"com.oppo.usercenter"<<"com.nearme.instant.platform"<<"com.nearme.romupdate"<<"com.nearme.statistics.rom"<<"com.coloros.phonemanager"<<"com.coloros.assistantscreen"<<"com.coloros.backuprestore"<<"com.coloros.backuprestore.remoteservice"<<"com.coloros.childrenspace"<<"com.coloros.cloud"<<"com.coloros.directui"<<"com.color.eyeprotect"<<"com.color.uiengine"<<"com.mobiletools.systemhelper"<<"com.oppo.ctautoregist"<<"com.coloros.feedback"<<"com.coloros.encryption"<<"com.realme.findphone.client2"<<"com.coloros.gamespace"<<"com.coloros.healthcheck"<<"com.iflytek.speechsuite"<<"com.nearme.instant.platform"<<"com.oppo.market"<<"com.nearme.atlas"<<"com.oppo.usercenter"<<"com.coloros.ocrscanner"<<"com.coloros.ocrservice"<<"com.oppo.aod"<<"com.oppo.atlas"<<"com.nearme.statistics.rom"<<"com.dropboxchmod"<<"com.oppo.engineermode"<<"com.oppo.logkit"<<"com.coloros.oppomultiapp"<<"com.coloros.operationManual"<<"com.coloros.activation"<<"com.coloros.translate.engine"<<"com.coloros.wallet"<<"com.coloros.oshare"<<"com.oppo.ota"<<"com.oppo.otaui"<<"com.coloros.remoteguardservice"<<"com.coloros.sau"<<"com.coloros.sauhelper"<<"com.nearme.browser"<<"com.google.android.configupdater"<<"com.coloros.findmyphone"<<"com.oppo.quicksearchbox"<<"com.oppo.music"<<"com.coloros.speechassist"<<"com.coloros.speechassist.engine"<<"com.coloros.sceneservice"<<"com.coloros.smartdrive"<<"com.coloros.smartlock"<<"com.coloros.video";

   return ssl;
}

void COLOROSAPP::Start()
{
    fqaospCore fqcore;
    foreach(QString pkgname,getCOLOROS()){
        fqcore.uninstallpkg(pkgname,this->devname);
    }
    emit Finished();
}
