#include "secdialog.h"
#include "ui_secdialog.h"
#include <typeinfo>
#include <QDebug>
#include <iostream>
#include <map>

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);


}



SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::Editmap(QStringList valo, int resul[32])
{
/*
    QMapIterator<QString, int> i2(valores2);
    while (i2.hasNext()) {
        i2.next();
        ui -> listWidget -> addItem(QString::number(valo.size()));

        //qDebug() << i.key() << ": " << i.value();
    }

    QMapIterator<QString, int> i3(valores3);
    while (i3.hasNext()) {
        i3.next();
        ui -> listWidget -> addItem(i3.key() + " :   " + QString::number(i3.value()));

        //qDebug() << i.key() << ": " << i.value();
    }
    QMapIterator<QString, int> i4(valores4);
    while (i4.hasNext()) {
        i4.next();
        ui -> listWidget -> addItem(i4.key() + " :   " + QString::number(i4.value()));

        //qDebug() << i.key() << ": " << i.value();
    }
    */
    for(int i=0; i<valo.size(); i++) {
        ui -> listWidget -> addItem(valo[i]+ "   " +QString::number(resul[i]));

    }
}
