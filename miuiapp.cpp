#include "miuiapp.h"

MIUIAPP::MIUIAPP(QObject *parent) : QObject(parent)
{

}

MIUIAPP::MIUIAPP(QString *dev)
{
    this->devname = dev;
}

QStringList MIUIAPP::getMIUI()
{
    QStringList ssl;
    ssl<<"com.duokan.reader"<<"com.miui.fmservice"<<"com.miui.fm"<<"com.miui.misound"<<"com.miui.player"<<"com.xiaomi.payment"<<"com.android.browser"<<"com.miui.cloudbackup"<<"com.xiaomi.finddevice"<<"com.miui.miservice"<<"com.miui.systemAdSolution"<<"com.miui.personalassistant"<<"com.android.quicksearchbox"<<"com.xiaomi.market"<<"com.miui.accessibility"<<"com.mipay.wallet"<<"com.miui.video"<<"com.xiaomi.ab"<<"com.xiaomi.mi_connect_service"<<"com.xiaomi.simactivate.service"<<"com.miui.cloudservice"<<"com.miui.voiceassist"<<"com.miui.backup"<<"com.miui.contentextension"<<"com.xiaomi.drivemode"<<"com.android.email"<<"com.xiaomi.gamecenter"<<"com.miui.smarttravel"<<"com.xiaomi.scanner"<<"com.mfashiongallery.emag"<<"com.miui.virtualsim"<<"com.miui.notes";
ssl<<"com.google.android.googlequicksearchbox"<<"com.miui.misound"<<"com.google.android.soundpicker"<<"pl.zdunex25.updater"<<"com.xiaomi.payment"<<"com.android.email"<<"com.miui.bugreport"<<"com.android.browser"<<"com.miui.cloudbackup"<<"com.xiaomi.finddevice"<<"com.miui.miservice"<<"com.miui.fm"<<"com.google.android.feedback"<<"cn.wps.moffice_eng.xiaomi.lite"<<"com.miui.huanji"<<"com.xiaomi.mi_connect_service"<<"com.miui.newmidrive"<<"com.google.android.apps.cloudprint"<<"com.miui.videoplayer"<<"com.google.ar.lens"<<"com.google.android.syncadapters.contacts"<<"com.google.android.partnersetup"<<"com.google.android.syncadapters.calendar"<<"com.google.android.tts"<<"com.google.android.gms.location.history"<<"com.google.android.onetimeinitializer"<<"com.android.vending";
ssl<<"com.baidu.input_mi"<<"com.iflytek.inputmethod.miui"<<"com.xiaomi.smarthome"<<"cn.wps.moffice_eng.xiaomi.lite"<<"com.duokan.phone.remotecontroller"<<"com.xiaomi.aiasst_service"<<"com.duokan.reader"<<"com.android.backupconfirm"<<"com.miui.backup"<<"com.miui.cloudservice.sysbase"<<"com.android.bips"<<"com.xiaomi.finddevice"<<"com.xiaomi.mircs"<<"com.miui.miservice"<<"com.miui.contentextension"<<"com.miui.player"<<"com.miui.personalassistant"<<"com.miui.video"<<"com.miui.vipservice"<<"com.android.quicksearchbox"<<"com.android.browser"<<"com.xiaomi.gamecenter.sdk.service"<<"com.miui.cloudbackup"<<"com.xiaomi.shop"<<"com.miui.fm"<<"com.mipay.wallet"<<"com.mi.liveassistant"<<"com.mfashiongallery.emag"<<"com.xiaomi.jr"<<"com.miui.newmidrive"<<"com.mi.health"<<"com.miui.thirdappassistant"<<"com.xiaomi.youpin"<<"com.xiaomi.mibrain.speech"<<"com.miui.virtualsim"<<"com.xiaomi.vipaccount"<<"com.miui.smarttravel"<<"com.xiaomi.scanner"<<"com.miui.notes"<<"com.miui.newhome"<<"com.miui.huanji"<<"com.xiaomi.gamecenter"<<"com.android.email"<<"com.miui.hybrid"<<"com.miui.hybrid.accessory"<<"com.fido.xiaomi.uafclient"<<"com.fido.asm"<<"com.xiaomi.macro"<<"com.miui.cloudservice"<<"com.mi.AutoTest"<<"com.miui.analytics"<<"com.xiaomi.aiasst.vision"<<"com.miui.audiomonitor"<<"com.miui.accessibility"<<"com.xiaomi.mipay_client"<<"com.milink.service"<<"com.xiaomi.mi_connect_service"<<"com.miui.micloudsync"<<"com.xiaomi.ab"<<"com.xiaomi.joyose"<<"org.ifaa.aidl.manager"<<"com.xiaomi.market"<<"com.android.printspooler"<<"com.miui.greenguard"<<"com.miui.contentcatcher"<<"com.miui.bugreport"<<"com.miui.nextpay"<<"com.miui.systemAdSolution"<<"com.miui.tsmclient"<<"com.miui.translationservice"<<"com.xiaomi.payment"<<"com.android.updater"<<"com.miui.voicetrigger"<<"com.miui.voiceassist"<<"com.unionpay.tsmservice.mi"<<"com.miui.vsimcore"<<"com.miui.translation.youdao"<<"com.xiaomi.xmsfkeeper"<<"com.miui.translation.xmcloud"<<"com.xiaomi.account";

return ssl;
}

void MIUIAPP::Start()
{
    fqaospCore fqcore;
    foreach(QString pkgname,getMIUI()){
        fqcore.uninstallpkg(pkgname,this->devname);
    }
    emit Finished();
}
