#include "appitemcomponent.h"

appItemComponent::appItemComponent()
{

}

appItemComponent::appItemComponent(QString pkgname, bool checkboxEnable)
{
    qhbox = new QHBoxLayout();
    QCheckBox *checkBox = new QCheckBox();
    QLabel *label=new QLabel();
    checkBox->setChecked(checkboxEnable);
    label->setText(pkgname);
    qhbox->addWidget(checkBox);
    qhbox->addWidget(label);
}


QHBoxLayout *appItemComponent::getQhbox() const
{
    return qhbox;
}
