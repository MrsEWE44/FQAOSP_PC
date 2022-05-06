#include "fqaosp.h"

FQAOSP::FQAOSP()
{

}

void FQAOSP::test(QHBoxLayout *hbox)
{

    QList<QString> *list = new QList<QString>;
    QList<bool> *blist = new QList<bool>;
    QListWidget *listWidget = new QListWidget(m);
    QTextEdit *ed = new QTextEdit();
    ed->setFixedHeight(30);
    ed->setPlaceholderText("input search name");
    listWidget->sortItems(Qt::AscendingOrder);
    searchb = new QPushButton("搜索");
    searchb->setFixedSize(100,30);
    QVBoxLayout *vbox2 = new QVBoxLayout();
    QHBoxLayout *hbox2 = new QHBoxLayout();
    hbox2->addWidget(ed);
    hbox2->addWidget(searchb);
    vbox2->addItem(hbox2);
    vbox2->addWidget(listWidget);
    hbox->addItem(vbox2);
    addBt(hbox);
    connn(ed,list,blist,listWidget,{b3,b1,b4,b5,b6,b7,searchb,miui,flyme,coloros,vivo,myui,otherapp});
}

void FQAOSP::addBt(QHBoxLayout *hbox)
{
    b1 = new QPushButton("禁用");
    b2 = new QPushButton("加载设备");
    b3 = new QPushButton("获取用户安装");
    b4 = new QPushButton("获取所有已安装");
    b5 = new QPushButton("获取禁用");
    b6 = new QPushButton("启用");
    b7 = new QPushButton("卸载");


    miui = new QPushButton("miui策略");
    myui = new QPushButton("myui策略");
    flyme = new QPushButton("flyme策略");
    coloros = new QPushButton("coloros策略");
    vivo = new QPushButton("vivo策略");
    otherapp = new QPushButton("其他策略");

    vbox = new QVBoxLayout();
    addBts(vbox,{b2,b1,b6,b7});
    addBts(vbox,{b3,b4,b5});
    addBts(vbox,{miui,flyme,coloros});
    addBts(vbox,{myui,vivo,otherapp});
    initDisButton({miui,flyme,coloros,myui,vivo,otherapp});
    hbox->addItem(vbox);
}

void FQAOSP::addBts(QVBoxLayout *vbox, QList<QPushButton *> bs)
{
    QHBoxLayout *hbox2 = new QHBoxLayout();
    foreach(QPushButton *b , bs){
        b->setFixedHeight(40);
        hbox2->addWidget(b);
    }
    vbox->addItem(hbox2);
}

void FQAOSP::connn(QTextEdit *ed,QList<QString> *list, QList<bool> *blist, QListWidget *listWidget,QList<QPushButton *> bs)
{
    fqaospCore *fqcore = new fqaospCore();
    disableBt(bs);
    QObject::connect(b1,&QPushButton::clicked,[=](){
        for(int j =0;j<blist->size();j++){
            if(blist->at(j)){
                QMessageBox msgBox;
                msgBox.setDefaultButton(QMessageBox::Ok);
               if(fqcore->disablepkg(list->at(j),devname)){
                   msgBox.setWindowTitle("info");
                     msgBox.setText("disable [ " + list->at(j) + " ] sucess");
                 }else{
                   msgBox.setWindowTitle("error");
                     msgBox.setText("disable [ " + list->at(j) + " ] faile");
               }
                msgBox.exec();
            }
        }
    });
    QObject::connect(b2,&QPushButton::clicked, [=](){

        devname= new QString(fqcore->getADBDevices());
        if(devname->isEmpty()){
            QMessageBox::warning(this->m, "警告","not device",QMessageBox::Yes);
        }else{
            enableBt(bs);
        }
    });

    QObject::connect(bs[0],&QPushButton::clicked,[=](){
       QStringList pkgs = fqcore->getPackage3(devname);
       QMessageBox msgBox;
       msgBox.setDefaultButton(QMessageBox::Ok);
       if(pkgs.isEmpty() || pkgs.size() < 1){
           msgBox.setWindowTitle("error");
             msgBox.setText("no get infos");
       }else{
           showListWidgetDatas(pkgs,list,blist,listWidget);
           msgBox.setWindowTitle("info");
             msgBox.setText("query ok");
       }
       msgBox.exec();
    });


    QObject::connect(bs[2],&QPushButton::clicked,[=](){
       QStringList pkgs = fqcore->getAllPackage(devname);
       showmsg(pkgs,list,blist,listWidget);
    });

    QObject::connect(bs[3],&QPushButton::clicked,[=](){
       QStringList pkgs = fqcore->getDisablePackage(devname);
       showmsg(pkgs,list,blist,listWidget);
    });

    QObject::connect(bs[4],&QPushButton::clicked,[=](){
        for(int j =0;j<blist->size();j++){
            if(blist->at(j)){
                QMessageBox msgBox;
                msgBox.setDefaultButton(QMessageBox::Ok);
               if(fqcore->enablepkg(list->at(j),devname)){
                   msgBox.setWindowTitle("info");
                     msgBox.setText("enable [ " + list->at(j) + " ] sucess");
                 }else{
                   msgBox.setWindowTitle("error");
                     msgBox.setText("enable [ " + list->at(j) + " ] faile");

               }
                msgBox.exec();
            }
        }
        QStringList pkgs = fqcore->getDisablePackage(devname);
        showListWidgetDatas(pkgs,list,blist,listWidget);
    });

    QObject::connect(bs[5],&QPushButton::clicked,[=](){
        for(int j =0;j<blist->size();j++){
            if(blist->at(j)){
                QMessageBox msgBox;
                msgBox.setDefaultButton(QMessageBox::Ok);
               if(fqcore->uninstallpkg(list->at(j),devname)){
                   msgBox.setWindowTitle("info");
                     msgBox.setText("uninstall [ " + list->at(j) + " ] sucess");
                 }else{
                   msgBox.setWindowTitle("error");
                     msgBox.setText("uninstall [ " + list->at(j) + " ] faile");
               }
                msgBox.exec();

            }
        }
        QStringList pkgs = fqcore->getPackage3(devname);
        showListWidgetDatas(pkgs,list,blist,listWidget);
    });

    QObject::connect(bs[6],&QPushButton::clicked,[=](){
       if(ed->toPlainText().isEmpty()){
           QStringList pkgs = fqcore->getPackage3(devname);
           QMessageBox msgBox;
           msgBox.setDefaultButton(QMessageBox::Ok);
           if(pkgs.isEmpty() || pkgs.size() < 1){
               msgBox.setWindowTitle("error");
                 msgBox.setText("no get infos");
           }else{
               showListWidgetDatas(pkgs,list,blist,listWidget);
               msgBox.setWindowTitle("info");
                 msgBox.setText("query ok");
           }
           msgBox.exec();
       }
        if(list->size() > 0){
           QStringList sl;
           for(int i =0;i<list->size();i++){
               QString ss = list->at(i);
               if(ss.indexOf(ed->toPlainText()) != -1){
                   sl.append(ss);
               }
           }
           showListWidgetDatas(sl,list,blist,listWidget);
       }
    });


    QObject::connect(bs[7],&QPushButton::clicked,[=](){

        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("提示");
        msg->setText("正在执行miui禁用策略...");
        msg->addButton(QMessageBox::Ok);
        msg->button(QMessageBox::Ok)->setHidden(true);
        MIUIAPP *m = new MIUIAPP(devname);
        QThread *th = new QThread();
        th->start();
        m->moveToThread(th);

        QObject::connect(th, &QThread::started, m, &MIUIAPP::Start);
                    QObject::connect(m, &MIUIAPP::Finished, m,
                                     &MIUIAPP::deleteLater);
                    QObject::connect(m, &MIUIAPP::Finished, th, [=](){
                        msg->close();
                        th->quit();
                    });
                    QObject::connect(th, &QThread::finished, th, &QThread::deleteLater);

                    msg->exec();
    });

    QObject::connect(bs[8],&QPushButton::clicked,[=](){

        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("提示");
        msg->setText("正在执行flyme禁用策略...");
        msg->addButton(QMessageBox::Ok);
        msg->button(QMessageBox::Ok)->setHidden(true);
        FLYMEAPP *m = new FLYMEAPP(devname);
        QThread *th = new QThread();
        th->start();
        m->moveToThread(th);

        QObject::connect(th, &QThread::started, m, &FLYMEAPP::Start);
                    QObject::connect(m, &FLYMEAPP::Finished, m,
                                     &FLYMEAPP::deleteLater);
                    QObject::connect(m, &FLYMEAPP::Finished, th, [=](){
                        msg->close();
                        th->quit();
                    });
                    QObject::connect(th, &QThread::finished, th, &QThread::deleteLater);

                    msg->exec();
    });

    QObject::connect(bs[9],&QPushButton::clicked,[=](){

        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("提示");
        msg->setText("正在执行coloros禁用策略...");
        msg->addButton(QMessageBox::Ok);
        msg->button(QMessageBox::Ok)->setHidden(true);
        COLOROSAPP *m = new COLOROSAPP(devname);
        QThread *th = new QThread();
        th->start();
        m->moveToThread(th);

        QObject::connect(th, &QThread::started, m, &COLOROSAPP::Start);
                    QObject::connect(m, &COLOROSAPP::Finished, m,
                                     &COLOROSAPP::deleteLater);
                    QObject::connect(m, &COLOROSAPP::Finished, th, [=](){
                        msg->close();
                        th->quit();
                    });
                    QObject::connect(th, &QThread::finished, th, &QThread::deleteLater);

                    msg->exec();
    });

    QObject::connect(bs[10],&QPushButton::clicked,[=](){

        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("提示");
        msg->setText("正在执行vivo禁用策略...");
        msg->addButton(QMessageBox::Ok);
        msg->button(QMessageBox::Ok)->setHidden(true);
        VIVOAPP *m = new VIVOAPP(devname);
        QThread *th = new QThread();
        th->start();
        m->moveToThread(th);

        QObject::connect(th, &QThread::started, m, &VIVOAPP::Start);
                    QObject::connect(m, &VIVOAPP::Finished, m,
                                     &VIVOAPP::deleteLater);
                    QObject::connect(m, &VIVOAPP::Finished, th, [=](){
                        msg->close();
                        th->quit();
                    });
                    QObject::connect(th, &QThread::finished, th, &QThread::deleteLater);

                    msg->exec();
    });

    QObject::connect(bs[11],&QPushButton::clicked,[=](){

        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("提示");
        msg->setText("正在执行myui禁用策略...");
        msg->addButton(QMessageBox::Ok);
        msg->button(QMessageBox::Ok)->setHidden(true);
        MYUIAPP *m = new MYUIAPP(devname);
        QThread *th = new QThread();
        th->start();
        m->moveToThread(th);

        QObject::connect(th, &QThread::started, m, &MYUIAPP::Start);
                    QObject::connect(m, &MYUIAPP::Finished, m,
                                     &MYUIAPP::deleteLater);
                    QObject::connect(m, &MYUIAPP::Finished, th, [=](){
                        msg->close();
                        th->quit();
                    });
                    QObject::connect(th, &QThread::finished, th, &QThread::deleteLater);

                    msg->exec();
    });

    QObject::connect(bs[12],&QPushButton::clicked,[=](){

        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("提示");
        msg->setText("正在卸载第三方内置软件...");
        msg->addButton(QMessageBox::Ok);
        msg->button(QMessageBox::Ok)->setHidden(true);
        OtherAPPS *m = new OtherAPPS(devname);
        QThread *th = new QThread();
        th->start();
        m->moveToThread(th);

        QObject::connect(th, &QThread::started, m, &OtherAPPS::Start);
                    QObject::connect(m, &OtherAPPS::Finished, m,
                                     &OtherAPPS::deleteLater);
                    QObject::connect(m, &OtherAPPS::Finished, th, [=](){
                        msg->close();
                        th->quit();
                    });
                    QObject::connect(th, &QThread::finished, th, &QThread::deleteLater);

                    msg->exec();
    });




}

void FQAOSP::showListWidgetDatas(QStringList sl,QList<QString> *list, QList<bool> *blist, QListWidget *listWidget)
{
    listWidget->clear();
    list->clear();
    blist->clear();

    for(int i = 0;i<sl.size();i++){
        QString str=sl[i];
        if(!str.isEmpty()){
            list->append(str);
            blist->append(false);
            QListWidgetItem *newItem = new QListWidgetItem;
            QCheckBox *check = new QCheckBox();
            check->setText(str);
            check->setChecked(false);

            QObject::connect(check,&QCheckBox::stateChanged,[=](){
                blist->replace(i,check->isChecked());
            });
            listWidget->addItem(newItem);
            listWidget->setItemWidget(newItem,check);
        }
    }


}

void FQAOSP::disableBt(QList<QPushButton *> bs)
{
    foreach(QPushButton *b , bs){
     b->setHidden(true);
    }

}

void FQAOSP::enableBt(QList<QPushButton *> bs)
{
    foreach(QPushButton *b , bs){
     b->setHidden(false);
    }
}

void FQAOSP::initDisButton(QList<QPushButton *> bs)
{
    QPalette p;
    p.setColor(QPalette::Button,Qt::darkYellow);
    foreach (QPushButton* b, bs) {
        b->setPalette(p);
        b->setFlat(true);
        b->setAutoFillBackground(true);
    }
}

void FQAOSP::showmsg(QStringList pkgs,QList<QString> *list, QList<bool> *blist, QListWidget *listWidget)
{
    QMessageBox msgBox;
    msgBox.setDefaultButton(QMessageBox::Ok);
    if(pkgs.isEmpty() || pkgs.size() < 1){
        msgBox.setWindowTitle("error");
          msgBox.setText("no get infos");
    }else{
        showListWidgetDatas(pkgs,list,blist,listWidget);
        msgBox.setWindowTitle("info");
          msgBox.setText("query ok");
    }
    msgBox.exec();
}

void FQAOSP::show(QMainWindow *qmain)
{
    this->m = qmain;
          ww = new QWidget();
          m->setWindowTitle("FQAOSP");
          m->setCentralWidget(ww);
          QHBoxLayout *hbox = new QHBoxLayout();
          test(hbox);
          ww->setLayout(hbox);
          ww->show();
}
