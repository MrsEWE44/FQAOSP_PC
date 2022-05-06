#include "fqaospin.h"

FQAOSPIN::FQAOSPIN()
{

}

void FQAOSPIN::initLayout(QWidget *w)
{
    QHBoxLayout *hbox = new QHBoxLayout();
    QVBoxLayout *vbox = new QVBoxLayout();
    QVBoxLayout *vbox2 = new QVBoxLayout();
    QList<QString> *list = new QList<QString>;
    QList<bool> *blist = new QList<bool>;
    QListWidget *listWidget = new QListWidget(m);
    listWidget->sortItems(Qt::AscendingOrder);
    initBt();
    connn(list,blist,listWidget,{openfile,opendir,inapp});
    addVbt(vbox,{opendir,openfile});
    hbox->addWidget(listWidget);
    vbox2->addWidget(loaddev);
    vbox2->addWidget(inapp);
    hbox->addLayout(vbox2);
    vbox->addLayout(hbox);

    w->setLayout(vbox);
}

void FQAOSPIN::initBt()
{
    openfile = new QPushButton("file");
    opendir = new QPushButton("dir");
    inapp = new QPushButton("安装");
    loaddev = new QPushButton("加载设备");

}

void FQAOSPIN::addHbt(QHBoxLayout *hbox, QList<QPushButton *> bs)
{
    QVBoxLayout *hbox2 = new QVBoxLayout();
    foreach(QPushButton *b , bs){
        b->setFixedHeight(40);
        hbox2->addWidget(b);
    }
    hbox->addItem(hbox2);
}

void FQAOSPIN::addVbt(QVBoxLayout *vbox, QList<QPushButton *> bs)
{
    QHBoxLayout *hbox2 = new QHBoxLayout();
    foreach(QPushButton *b , bs){
        b->setFixedHeight(40);
        hbox2->addWidget(b);
    }
    vbox->addItem(hbox2);
}

void FQAOSPIN::connn(QList<QString> *list, QList<bool> *blist, QListWidget *listWidget, QList<QPushButton *> bs)
{
    fqaospCore *fqcore = new fqaospCore();
    disableBt(bs);

    QObject::connect(bs[0],&QPushButton::clicked,[=](){
        QStringList apks = QFileDialog::getOpenFileNames(NULL,"apk","c://","APK Files(*.apk)");
        showListWidgetDatas(apks,list,blist,listWidget);
    });

    QObject::connect(bs[1],&QPushButton::clicked,[=](){
        QString dirname = QFileDialog::getExistingDirectory(NULL,"dir","c://",QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
        QStringList apks;
        getFiles(apks,dirname,"apk");
        showListWidgetDatas(apks,list,blist,listWidget);
    });

    QObject::connect(bs[2],&QPushButton::clicked,[=](){
        QMessageBox *msg = new QMessageBox();
        msg->setWindowTitle("提示");
        msg->setText("正在安装apk...");
        msg->addButton(QMessageBox::Ok);
        msg->button(QMessageBox::Ok)->setHidden(true);
        APPINSTALL *m = new APPINSTALL(new QString(fqcore->getADBDevices()),list,blist);
        QThread *th = new QThread();
        th->start();
        m->moveToThread(th);
        QObject::connect(th, &QThread::started, m, &APPINSTALL::Start);
                    QObject::connect(m, &APPINSTALL::Finished, m,
                                     &APPINSTALL::deleteLater);
                    QObject::connect(m, &APPINSTALL::Finished, th, [=](){
                        msg->close();
                        th->quit();
                    });
                    QObject::connect(th, &QThread::finished, th, &QThread::deleteLater);

                    msg->exec();
    });


    QObject::connect(loaddev,&QPushButton::clicked, [=](){
        QString ddd = fqcore->getADBDevices();
        devname= new QString(ddd);
        if(devname->isEmpty()){
            QMessageBox::warning(this->m, "警告","设备没有正确读取",QMessageBox::Yes);
        }else{
            enableBt(bs);
        }
    });

}

void FQAOSPIN::enableBt(QList<QPushButton *> bs)
{
    foreach(QPushButton *b , bs){
     b->setHidden(false);
    }
}

void FQAOSPIN::disableBt(QList<QPushButton *> bs)
{
    foreach(QPushButton *b , bs){
     b->setHidden(true);
    }
}

void FQAOSPIN::showListWidgetDatas(QStringList sl, QList<QString> *list, QList<bool> *blist, QListWidget *listWidget)
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

void FQAOSPIN::getFiles(QStringList &sl, QString dirname, QString endname)
{
    QDir d(dirname);

   QFileInfoList flist =  d.entryInfoList();
   foreach (QFileInfo finfo, flist) {
       QString filename = finfo.fileName();
       if(filename!= "." && filename != ".."){
           QString filepath=finfo.filePath();
           if(finfo.isDir()){
               getFiles(sl,filepath,endname);
           }
           if(finfo.isFile()){

               if(finfo.suffix() == endname){
                sl.append(filepath);

               }
           }

       }

   }
}

void FQAOSPIN::show(QMainWindow *qmain)
{
    this->m = qmain;
          ww = new QWidget();
          m->setWindowTitle("FQAOSP INSTALL");
          m->setCentralWidget(ww);
          initLayout(ww);
          ww->show();
}
