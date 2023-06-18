#include "housewindow.h"
#include "ui_housewindow.h"
#include <iostream>
using namespace std;

HouseWindow::HouseWindow(QWidget *parent, Central *cen): QMainWindow(parent), ui(new Ui::HouseWindow), c(cen)
{
    ui->setupUi(this);
    ui->houseRegion->setScene(&interiorScene);

    siren = new QGraphicsPolygonItem();
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

void HouseWindow::setCentral(Central *c){
    HouseWindow::c = c;
}

void HouseWindow::on_pushButton_clicked(){
    c->timer->start(200); //0.2[s]
    c->setZone0Build(true);
}

void HouseWindow::on_pushButton_2_clicked(){
    c->timer->stop();//5[s]
}
void HouseWindow::alarmCheck(){
    if (c->getIsClose()) {
        siren->setBrush(Qt::green);
        ui->lineEdit->setText("Ninguna Zona Abierta");
    } else {
        if (siren->brush() == Qt::green)
            siren->setBrush(Qt::red);
        else
            siren->setBrush(Qt::green);
        ui->lineEdit->setText("Alguna Zona Abierta");
    }
}

HouseWindow::~HouseWindow()
{
    delete ui;
}
