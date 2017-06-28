#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "secdialog.h"
#include <string>
#include <QMap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QMap<QString,int> valores;
    QMap<QString,int> valores2;
    QMap<QString,int> valores3;
    QMap<QString,int> valores4;
    QStringList valo;
    int resul[32];
    QStringList comandos;
    QStringList numeros;
    QStringList lwsw;
    QStringList saltos;

private slots:
    void on_pushButton_8_clicked();

    void on_comboBox_activated(int index);

    void on_pushButton_10_clicked();

    void cambiarColor(bool Ucache, bool Ureg, bool UregFil, bool Uregxy, bool UAlu, QString Mul1, QString Mul2, QString Mul3, QString Mul4, QString Mul5, QString Mul6, QString Mul7, bool UZreg);

    void Ope();

private:
    Ui::MainWindow *ui;
    SecDialog *secdialog;


};

#endif // MAINWINDOW_H
