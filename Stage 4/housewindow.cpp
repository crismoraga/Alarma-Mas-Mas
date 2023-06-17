#include "housewindow.h"
#include "ui_housewindow.h"
#include <iostream>
using namespace std;

HouseWindow::HouseWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::HouseWindow)
{
    ui->setupUi(this);
    ui->houseRegion->setScene(&interiorScene);




    QPolygonF p;
    p.append(QPointF(0,0));
    p.append(QPointF(0,20));
    p.append(QPointF(10,20));
    p.append(QPointF(10,10));
    p.append(QPointF(20,10));
    p.append(QPointF(20,0));
    siren->setPolygon(p);
    siren->setBrush(Qt::green);
    exteriorScene.addItem(siren);

    ui->alarmRegion->setScene(&exteriorScene);
    connect(c->timer, SIGNAL(timeout()), this, SLOT(alarmCheck()));
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
void HouseWindow::alarmCheck(){
    if(c->getIsClose()){
        siren->hijo->setBrush(Qt::green);
    }else{
        if (siren.color == Qt::green) siren->hijo->setBrush(Qt::red);
        else siren->setBrush(Qt::green);
    }
}

HouseWindow::~HouseWindow()
{
    delete ui;
}
