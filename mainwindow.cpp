#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMenu()
{
    QHBoxLayout *hbox = new QHBoxLayout();
    QPushButton *unapp = new QPushButton("卸载");
    QPushButton *inapp = new QPushButton("安装");
    QMainWindow *m = this;
     QWidget *ww = new QWidget();
    m->setWindowTitle("FQAOSPMENU");
    connect(unapp,&QPushButton::clicked,[=](){
        FQAOSP fqaosp;
        fqaosp.show(m);

    });

    connect(inapp,&QPushButton::clicked,[=](){
        FQAOSPIN fqaospin;
        fqaospin.show(m);

    });

    hbox->addWidget(unapp);
    hbox->addWidget(inapp);
    m->setCentralWidget(ww);
    ww->setLayout(hbox);
    ww->show();
}

