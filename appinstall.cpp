#include "appinstall.h"

APPINSTALL::APPINSTALL(QObject *parent) : QObject(parent)
{

}

APPINSTALL::APPINSTALL(QString *de, QList<QString> *l, QList<bool> *b)
{
    this->devname = de;
    this->list = l;
    this->blist=b;
}

void APPINSTALL::Start()
{
    fqaospCore fqcore;
    int count =0;
    for(int i =0;i<blist->size();i++){
        if(blist->at(i)){
            fqcore.installapk(list->at(i),this->devname);
            count++;
        }
    }
    if(count == 0){
        for(int j =0;j<list->size();j++){
            fqcore.installapk(list->at(j),devname);
        }
    }
    emit Finished();
}
