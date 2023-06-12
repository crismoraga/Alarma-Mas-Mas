#include "doorview.h"
#include <QBrush>
DoorView::DoorView(int x, int y, int angle, MagneticSensorView * mv) {
    makeDoorView();
    mv->setParentItem(this);
    installMagneticSensor(*mv);
    magnet = &(mv->getMagnetView());
    QTransform transform;
    transform.translate(x,y);
    transform.rotate(angle);
    setTransform(transform);
}
void DoorView::makeDoorView(){
    QGraphicsPolygonItem * origenPillar=new QGraphicsPolygonItem(this);
    QPolygonF p;
    p.append(QPointF(0,0));
    p.append(QPointF(0,20));
    p.append(QPointF(10,20));
    p.append(QPointF(10,10));
    p.append(QPointF(20,10));
    p.append(QPointF(20,0));
    origenPillar->setPolygon(p);
    origenPillar->setBrush(Qt::blue);
    switchPillar=new QGraphicsPolygonItem(this);
    p.clear();
    p.append(QPointF(160,0));
    p.append(QPointF(160,10));
    p.append(QPointF(170,10));
    p.append(QPointF(170,20));
    p.append(QPointF(180,20));
    p.append(QPointF(180,0));
    switchPillar->setPolygon(p);
    switchPillar->setBrush(Qt::blue);
    doorPanel = new QGraphicsRectItem(??, ??, ??, ??, this);
    doorPanel->setBrush(Qt::blue);
    doorPanel->setTransformOriginPoint(doorPanel->rect().left(), doorPanel->rect().bottom());
    addToGroup(origenPillar);
    addToGroup(switchPillar);
    addToGroup(doorPanel);
}
void DoorView::setDoorModel(Door * m){
    model=m;
}
void DoorView::installMagneticSensor(MagneticSensorView & mv){
    mv.getMagnetView().setRect(doorPanel->rect().right()-mv.getMagnetView().rect().width(),
                                 doorPanel->rect().bottom(),
                                 mv.getMagnetView().rect().width(),
                                 mv.getMagnetView().rect().height());
    mv.getSwitchView().setRect(switchPillar->boundingRect().x()+switchPillar->boundingRect().width()/2,
                                 switchPillar->boundingRect().height(),
                                 mv.getSwitchView().rect().width(),
                                 mv.getSwitchView().rect().height());
    mv.getMagnetView().setTransformOriginPoint(??, ??);
    addToGroup(&mv.getMagnetView());
    addToGroup(&mv.getSwitchView());
}
void DoorView::setOpen(){
    doorPanel->setRotation(90);
    magnet->setRotation(90);
}
void DoorView::setClose(){
    doorPanel->setRotation(0);
    magnet->setRotation(0);
}
void DoorView::mousePressEvent(QGraphicsSceneMouseEvent * event){
    if (model!= NULL && event->button()==Qt::LeftButton)
        model->changeState();
}
DoorView::~DoorView(){
    delete doorPanel;
    delete switchPillar;
}
