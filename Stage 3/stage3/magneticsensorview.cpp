#include "magneticsensorview.h"
#include <QBrush>

MagneticSensorView::MagneticSensorView():switchView(0,0,8,6, this),magnetView(0,0,8,6, this)  {
    switchView.setBrush(QBrush(Qt::green));
    magnetView.setBrush(QBrush(Qt::black));
}

void MagneticSensorView::setCloseView(){
    ??
}
void MagneticSensorView::setOpenView(){
    ??
}
QGraphicsRectItem & MagneticSensorView::getSwitchView(){
    return switchView;
}
QGraphicsRectItem & MagneticSensorView::getMagnetView(){
    return magnetView;
}
