#include "housewindow.h"
#include "ui_housewindow.h"

HouseWindow::HouseWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::HouseWindow)
{
    ui->setupUi(this);
    ui->houseRegion->setScene(&interiorScene);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(StartTimer));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(StopTimer));
}
void HouseWindow::addHouseHollow(QGraphicsItemGroup * compoundItem){
    interiorScene.addItem(compoundItem);
}

void HouseWindow::setCentral(Central *c)
{
    HouseWindow::c = c;
}

void HouseWindow::StartTimer()
{
    c->getTimer()->start();
}

void HouseWindow::StopTimer()
{
    c->getTimer()->stop();
}

HouseWindow::~HouseWindow()
{
    delete ui;
}

