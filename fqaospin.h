#ifndef FQAOSPIN_H
#define FQAOSPIN_H

#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <QThread>
#include <QVBoxLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include <QList>
#include <QCheckBox>
#include <QFileDialog>
#include <QDir>
#include <QDirIterator>

#include "fqaospcore.h"
#include "appinstall.h"

class FQAOSPIN
{
public:
    FQAOSPIN();

private:
  QMainWindow *m;
  QWidget *ww;

private:
  QString *devname;
  QPushButton *loaddev;
  QPushButton *openfile,*opendir,*inapp;

private:
  void initLayout(QWidget *w);
  void initBt();
  void addHbt(QHBoxLayout *hbox,QList<QPushButton *> bts);
  void addVbt(QVBoxLayout *vbox,QList<QPushButton *> bts);
  void connn(QList<QString> *list,QList<bool> *blist,QListWidget *listWidget,QList<QPushButton *> bs);
  void enableBt(QList<QPushButton *> bs);
  void disableBt(QList<QPushButton *> bs);
  void showListWidgetDatas(QStringList sl,QList<QString> *list, QList<bool> *blist, QListWidget *listWidget);
  void getFiles(QStringList &sl,QString dirname , QString endname);


public:
    void show(QMainWindow *qmain);
};

#endif // FQAOSPIN_H
