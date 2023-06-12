#ifndef DOORVIEW_H
#define DOORVIEW_H

#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>
#include "door.h"
#include "magneticsensorview.h"

class DoorView : public QGraphicsItemGroup
{
public:
    explicit DoorView(int x, int y, int angle, MagneticSensorView * msView);
    void setDoorModel(Door * model);
    void setOpen();
    void setClose();
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *);
    ~DoorView();
private:
    void installMagneticSensor(MagneticSensorView & msView);
    void makeDoorView();
    Door * model;
    QGraphicsRectItem * doorPanel;
    QGraphicsPolygonItem * switchPillar;
    QGraphicsRectItem * magnet;
};

#endif // DOORVIEW_H
