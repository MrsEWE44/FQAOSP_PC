#ifndef FQAOSPMENU_H
#define FQAOSPMENU_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>

class FQAOSPMENU
{
public:
    FQAOSPMENU();
private:
    QMainWindow *m;
public:
    void show(QMainWindow *mmm);
};

#endif // FQAOSPMENU_H
