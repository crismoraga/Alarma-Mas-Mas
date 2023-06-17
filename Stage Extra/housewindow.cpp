#include "housewindow.h"
#include "ui_housewindow.h"
#include <iostream>
using namespace std;

HouseWindow::HouseWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::HouseWindow)
{
    ui->setupUi(this);
    ui->houseRegion->setScene(&interiorScene);
}
void HouseWindow::addHouseHollow(QGraphicsItemGroup * compoundItem){
    interiorScene.addItem(compoundItem);
}

void HouseWindow::setCentral(Central *c)
{
    HouseWindow::c = c;
}

void HouseWindow::on_pushButton_clicked()
{
    c->timer->start(200);
    ui->lineEdit->setText("Alarma activada!!");
}


void HouseWindow::on_pushButton_2_clicked()
{
    c->timer->stop();
    ui->lineEdit->setText("Alarma desactivada!!");
}

HouseWindow::~HouseWindow()
{
    delete ui;
}
