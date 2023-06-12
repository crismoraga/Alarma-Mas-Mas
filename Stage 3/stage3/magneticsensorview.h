#ifndef MAGNETICSENSORVIEW_H
#define MAGNETICSENSORVIEW_H

#include <QGraphicsItemGroup>

class MagneticSensorView : public QGraphicsItemGroup
{
public:
    MagneticSensorView();
    void setCloseView();
    void setOpenView();
    QGraphicsRectItem & getSwitchView();
    QGraphicsRectItem & getMagnetView();
private:
    QGraphicsRectItem switchView, magnetView;
};

#endif // MAGNETICSENSORVIEW_H
