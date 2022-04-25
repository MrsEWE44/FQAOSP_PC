#ifndef FQAOSP_H
#define FQAOSP_H


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
#include <QProcess>
#include <QTextEdit>
#include <QPalette>
#include <QCoreApplication>

#include "fqaospcore.h"
#include "miuiapp.h"
#include "flymeapp.h"
#include "myuiapp.h"
#include "colorosapp.h"
#include "vivoapp.h"

class FQAOSP
{
public:
    FQAOSP();

private:
  QMainWindow *m;
  QWidget *ww;
  QVBoxLayout *vbox;

private:
  QString *devname;
  QPushButton *b1,*b2,*b3,*b4,*b5,*b6,*b7,*searchb;
  QPushButton *miui,*myui,*flyme,*coloros,*vivo;

private:
  void test(QHBoxLayout *hbox);
  void addBt(QHBoxLayout *hbox);

  void addBts(QVBoxLayout *vbox,QList<QPushButton *> bs);
  void connn(QTextEdit *ed,QList<QString> *list,QList<bool> *blist,QListWidget *listWidget,QList<QPushButton *> bs);
  void showListWidgetDatas(QStringList sl, QList<QString> *list,QList<bool> *blist,QListWidget *listWidget);
  void disableBt(QList<QPushButton *> bs);
  void enableBt(QList<QPushButton *> bs);
  void initDisButton(QList<QPushButton *> bs);
  void showmsg(QStringList pkgs,QList<QString> *list, QList<bool> *blist, QListWidget *listWidget);

public:
    void show(QMainWindow *qmain);
};

#endif // FQAOSP_H
