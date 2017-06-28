#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
#include <QThread>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setStyleSheet("background-color: darkGray;");
    ui->Bul_2->setStyleSheet("background-color: transparent; border-image: url(:bool2.png); background: none; border: none; background-repeat: none; }");
    ui->Bul_3->setStyleSheet("background-color: transparent; border-image: url(:bool2.png); background: none; border: none; background-repeat: none; }");
    ui->Bul_4->setStyleSheet("background-color: transparent; border-image: url(:bool2.png); background: none; border: none; background-repeat: none; }");
    ui->Bul_5->setStyleSheet("background-color: transparent; border-image: url(:bool2.png); background: none; border: none; background-repeat: none; }");
    ui->Bul_6->setStyleSheet("background-color: transparent; border-image: url(:bool2.png); background: none; border: none; background-repeat: none; }");
    ui->Bul_7->setStyleSheet("background-color: transparent; border-image: url(:bool2.png); background: none; border: none; background-repeat: none; }");

    valores["0  - $zero"] = 0;
    valores["1  - $at"] = 0;
    valores["2  - $v0"] = 0;
    valores["3  - $v1"] = 0;
    valores["4  - $a0"] = 0;
    valores["5  - $a1"] = 0;
    valores["6  - $a2"] = 0;
    valores["7  - $a3"] = 0;
    valores["8  - $t0"] = 0;
    valores["9  - $t1"] = 0;
    valores2["10 - $t2"] = 0;
    valores2["11 - $t3"] = 0;
    valores2["12 - $t4"] = 0;
    valores2["13 - $t5"] = 0;
    valores2["14 - $t6"] = 0;
    valores2["15 - $t7"] = 0;
    valores2["16 - $s0"] = 0;
    valores2["17 - $s1"] = 0;
    valores2["18 - $s2"] = 0;
    valores2["19 - $s3"] = 0;
    valores3["20 - $s4"] = 0;
    valores3["21 - $s5"] = 0;
    valores3["22 - $s6"] = 0;
    valores3["23 - $s7"] = 0;
    valores3["24 - $t8"] = 0;
    valores3["25 - $t9"] = 0;
    valores3["26 - $k0"] = 0;
    valores3["27 - $k1"] = 0;
    valores3["28 - $gp"] = 268468224;
    valores3["29 - $sp"] = 2147479548;
    valores4["30 - $fp"] = 0;
    valores4["31 - $ra"] = 0;

    valo << "$zero" << "$at" << "$v0" << "$v1" << "$a0" << "$a1" << "$a2" << "$a3";

    for (int i=0; i<8; i++){
        valo << "$t"+QString::number(i);
    }

    for (int i=0; i<8; i++){
        valo << "$s"+QString::number(i);
    }
    valo << "$t8" << "$t9" << "$k0" << "$k1" << "$gp" << "$sp" << "$fp" << "$ra";

    for (int i=0; i<32; i++) {
        resul[i] = 0;
    }

    resul[9] = 5;
    resul[10] = 4;


    QStringList inst;

    inst << "lui" << "add" << "sub" << "slt" << "addi" << "slti" << "and" << "or" << "xor" << "nor" << "andi"
             << "ori" << "xori" << "lw" << "sw"  << "bltz" << "beq" << "bne" << "jal" << "j" << "jr" << "syscall";

    for (int i=0; i<inst.size(); i++)
    {
        ui->comboBox->addItem(inst[i]);
    }

    numeros << "0" << "1" << "2" << "3" << "4" << "5" << "6"
            << "7" << "8" <<"9" << "10" ;

    comandos << "t0" << "t1" << "t2" << "t3" << "t4" << "t5"
             << "t6" << "t7" << "s0" << "s1" << "s2" << "s3" << "s4" << "s5" << "s7" << "t8" << "t9";

    lwsw << "(t0)" << "(t1)" << "(t2)" << "(t3)" << "4(t0)" << "4(t1)" << "4(t2)" << "4(t3)";
    saltos << "fin" << "bucle" << "otra" << "jump" ;
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Ope(){

    int da1 = ui->comboBox_3->currentIndex()+8;
    int da2 = ui->comboBox_4->currentIndex()+8;
    int index = ui->comboBox->currentIndex();

    if (index == 1) {
        resul[ui->comboBox_2->currentIndex()+8] = resul[da1]+resul[da2];
    }

    else if (index == 2) {
        resul[ui->comboBox_2->currentIndex()+8] = resul[da1]-resul[da2];
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    //SecDialog secdialog;
    //secdialog.setModal(true);
    //secdialog.exec();
    secdialog = new SecDialog(this);
    qDebug() << valo.size();
    secdialog->Editmap(valo, resul);
    secdialog -> show();

}

void MainWindow::on_comboBox_activated(int index)
{
    ui->comboBox_2 ->clear();
    ui->comboBox_3 ->clear();
    ui->comboBox_4 ->clear();
    if(index <=17){

        for (int i=0; i<comandos.size(); i++)
        {
            ui->comboBox_2->addItem(comandos[i]);
        }

        if(index==0){


            for (int i=0; i<numeros.size(); i++)
            {
                ui->comboBox_3->addItem(numeros[i]);
            }

        }else if(index<=12 || index == 16 || index == 17){

            for (int i=0; i<comandos.size(); i++)
            {
                ui->comboBox_3->addItem(comandos[i]);
            }

            if(index == 16 || index == 17){

                for (int i=0; i<saltos.size(); i++)
                {
                    ui->comboBox_4->addItem(saltos[i]);
                }

            }else if(index < 4 || (index >= 6 && index < 10)){

                for (int i=0; i<comandos.size(); i++)
                {
                    ui->comboBox_4->addItem(comandos[i]);
                }
            }else{

                for (int i=0; i<numeros.size(); i++)
                {
                    ui->comboBox_4->addItem(numeros[i]);
                }

            }
        }else if(index <= 14){

            for (int i=0; i<lwsw.size(); i++)
            {
                ui->comboBox_4->addItem(lwsw[i]);
            }

        }

    }else{
        if(index <= 19){
            for (int i=0; i<saltos.size(); i++)
            {
                ui->comboBox_4->addItem(saltos[i]);
            }
        }else if(index == 20){
            for (int i=0; i<comandos.size(); i++)
            {
                ui->comboBox_4->addItem(comandos[i]);
            }
        }

    }


}

void MainWindow::cambiarColor(bool Ucache, bool Ureg, bool UregFil, bool Uregxy, bool UAlu, QString Mul1, QString Mul2, QString Mul3, QString Mul4, QString Mul5, QString Mul6, QString Mul7, bool UZreg){

    ui ->Buttonpc -> setStyleSheet("background-color: red");

    QApplication::processEvents();
    QThread::sleep(1.5); // dormir

    ui ->Buttonpc -> setStyleSheet(""); // lo regresa a mismo color

    if (Ucache){
        ui-> Bul -> setText(Mul1);
        ui -> cache -> setStyleSheet("background-color: red");

        QApplication::processEvents();
        QThread::sleep(1.5); // dormir

        ui->cache-> setStyleSheet("");
    }

    if (Ureg){
        ui->instreg->setStyleSheet("background-color: red");
        ui->datareg->setStyleSheet("background-color: red");

        QApplication::processEvents();
        QThread::sleep(1.5); // dormir

        ui->instreg->setStyleSheet("");
        ui->datareg->setStyleSheet("");
    }

    ui->Bul_5->setText(Mul2);
    ui->Bul_4->setText(Mul3);

    if (UregFil) {
        ui->regfile->setStyleSheet("background-color: red");

        QApplication::processEvents();
        QThread::sleep(1.5); // dormir

        ui->regfile->setStyleSheet("");
    }

    if (Uregxy) {

        ui->xreg->setStyleSheet("background-color: red");
        ui->yreg->setStyleSheet("background-color: red");

        QApplication::processEvents();
        QThread::sleep(1.5); // dormir

        ui->xreg->setStyleSheet("");
        ui->yreg->setStyleSheet("");
    }

    ui->Bul_2->setText(Mul4);
    ui->Bul_3->setText(Mul5);

    if (UAlu) {
        ui->Alu->setStyleSheet("background-color: transparent; border-image: url(:alu2.png); background: none; border: none; background-repeat: none; }");

        QApplication::processEvents();
        QThread::sleep(1.5); // dormir

        ui->Alu->setStyleSheet("background-color: transparent; border-image: url(:alu.png); background: none; border: none; background-repeat: none; }");
    }

    if (UZreg){
        ui->zreg->setStyleSheet("background-color: red");

        QApplication::processEvents();
        QThread::sleep(1.5); // dormir

        ui->zreg->setStyleSheet("");
    }

    ui->Bul_7->setText(Mul6);

    QApplication::processEvents();
    QThread::sleep(1.5); // dormir

    ui->line_51->setStyleSheet("background-color: red");
    ui->line_50->setStyleSheet("background-color: red");
    ui->line_49->setStyleSheet("background-color: red");
    ui->line->setStyleSheet("background-color: red");
    ui->line_2->setStyleSheet("background-color: red");

    QApplication::processEvents();
    QThread::sleep(1.5); // dormir

    ui->line_51->setStyleSheet("");
    ui->line_50->setStyleSheet("");
    ui->line_49->setStyleSheet("");
    ui->line->setStyleSheet("");
    ui->line_2->setStyleSheet("");

    QApplication::processEvents();
    QThread::sleep(1.5); // dormir

    ui->Bul->setText("");
    ui->Bul_2->setText("");
    ui->Bul_3->setText("");
    ui->Bul_4->setText("");
    ui->Bul_5->setText("");
    ui->Bul_6->setText("");
}

void MainWindow::on_pushButton_10_clicked()
{
    int index = ui->comboBox->currentIndex();

    if (ui->comboBox->currentIndex() == 0)
    {
        cambiarColor(true, true, true, true, true, "0", "1", "1", "1", "1", "3", "", true);
    }

    else if ((index >= 1) && (index <= 12))
    {
        if (((index >= 1) && (index <= 3)) || ((index >=6) && (index <= 9)))
        {
           cambiarColor(true, true, true, true, true, "0", "1", "1", "1", "1", "3", "", true);
        }
        if (((index >= 4) && (index <= 5)) || ((index >=10) && (index <= 12)))
        {
            cambiarColor(true, true, true, true, true, "0", "0", "1", "1", "2", "3", "", true);
        }
    }

    else if (index == 13)
    {
        cambiarColor(true, true, true, true, true,  "0", "", "", "1", "2", "3", "", true);
    }

    else if (index == 14)
    {
        cambiarColor(true, true, false, true, true, "0", "", "", "1", "2", "3", "", true);
    }

    else if ((index >= 15) && (index <= 20)) {
        if (index == 18) {
            cambiarColor(true, true, true, true, true, "0", "", "", "1", "2", "3", "", true);
        }

        else  {
             cambiarColor(true, true, false, true, true, "0", "", "", "1", "2", "3", "", true);
        }
    }

    Ope();
}
