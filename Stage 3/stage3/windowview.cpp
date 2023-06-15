#include "windowview.h"
#include <QBrush>

WindowView::WindowView(int x, int y, int angle, MagneticSensorView * mv) {
    makeWindowView();
    mv->setParentItem(this);
    installMagneticSensor(*mv);
    magnet = &(mv->getMagnetView());
    QTransform transform;
    transform.translate(x,y);
    transform.rotate(angle);
    setTransform(transform);
}
void WindowView::makeWindowView(){
    QGraphicsPolygonItem * origenPillar=new QGraphicsPolygonItem(this);
    QPolygonF p;
    p.append(QPointF(0,0));
    p.append(QPointF(0,20));
    p.append(QPointF(10,20));
    p.append(QPointF(20,0));
    origenPillar->setPolygon(p);
    origenPillar->setBrush(Qt::blue);

    switchPillar=new QGraphicsPolygonItem(this);
    p.clear();
    p.append(QPointF(160,0));
    p.append(QPointF(160,20));
    p.append(QPointF(170,20));
    p.append(QPointF(170,0));

    switchPillar->setPolygon(p);
    switchPillar->setBrush(Qt::blue);

    QGraphicsPolygonItem * windowPanel = new QGraphicsPolygonItem(this);
    windowPanel = new QGraphicsRectItem(10, 10, 90, 10, this);
    windowPanel->setBrush(Qt::blue);

    windowSlidingPanel = new QGraphicsRectItem(90, 20, 90, 10, this);
    windowSlidingPanel->setBrush(Qt::blue);

    //windowSlidingPanel->setTransformOriginPoint(windowPanel->rect().left(), windowPanel->rect().bottom());

    addToGroup(origenPillar);
    addToGroup(switchPillar);
    addToGroup(windowPanel);
    addToGroup(windowSlidingPanel);
}
void WindowView::setWindowModel(Window * m){
    model=m;
}
void WindowView::installMagneticSensor(MagneticSensorView & mv){
    mv.getMagnetView().setRect(windowPanel->rect().right()-mv.getMagnetView().rect().width(),
                               windowPanel->rect().bottom(),
                               mv.getMagnetView().rect().width(),
                               mv.getMagnetView().rect().height());
    mv.getSwitchView().setRect(switchPillar->boundingRect().x()+switchPillar->boundingRect().width()/2,
                               switchPillar->boundingRect().height(),
                               mv.getSwitchView().rect().width(),
                               mv.getSwitchView().rect().height());
    mv.getMagnetView().setTransformOriginPoint(windowPanel->rect().left(), windowPanel->rect().bottom());
    addToGroup(&mv.getMagnetView());
    addToGroup(&mv.getSwitchView());
}
void WindowView::setOpen(){
    windowSlidingPanel->setPos(10, 20);
    magnet->setPos(10, 20);
}
void WindowView::setClose(){
    windowSlidingPanel->setPos(90, 20);
    magnet->setPos(90, 20);
}
void WindowView::mousePressEvent(QGraphicsSceneMouseEvent * event){
    if (model!= NULL && event->button()==Qt::LeftButton)
        model->changeState();
}
WindowView::~WindowView(){
    delete windowPanel;
    delete switchPillar;
}
