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
    p.append(QPointF(20,20));
    p.append(QPointF(20,0));

    origenPillar->setPolygon(p);
    origenPillar->setBrush(Qt::blue);
    switchPillar=new QGraphicsPolygonItem(this);
    p.clear();
    p.append(QPointF(180,0));
    p.append(QPointF(180,20));
    p.append(QPointF(200,20));
    p.append(QPointF(200,0));

    switchPillar->setPolygon(p);
    switchPillar->setBrush(Qt::blue);

    QGraphicsRectItem * windowPanel = new QGraphicsRectItem(20, 3, 90, 5, this);
    windowPanel->setBrush(Qt::blue);

    windowSlidingPanel = new QGraphicsRectItem(90, 10, 90, 5, this);
    windowSlidingPanel->setBrush(Qt::blue);



    addToGroup(origenPillar);
    addToGroup(switchPillar);
    addToGroup(windowPanel);
    addToGroup(windowSlidingPanel);
}
void WindowView::setWindowModel(Window * m){
    model=m;
}
void WindowView::installMagneticSensor(MagneticSensorView & mv){
    mv.getMagnetView().setRect(windowSlidingPanel->rect().right()-mv.getMagnetView().rect().width(),
                               windowSlidingPanel->rect().bottom(),
                               mv.getMagnetView().rect().width(),
                               mv.getMagnetView().rect().height());
    mv.getSwitchView().setRect(switchPillar->boundingRect().x()+switchPillar->boundingRect().width()/2,
                               switchPillar->boundingRect().height(),
                               mv.getSwitchView().rect().width(),
                               mv.getSwitchView().rect().height());
    mv.getMagnetView().setTransformOriginPoint(windowSlidingPanel->rect().left(), windowSlidingPanel->rect().bottom());
    addToGroup(&mv.getMagnetView());
    addToGroup(&mv.getSwitchView());
}
void WindowView::setOpen(){
    windowSlidingPanel->setPos(-70, 0);
    magnet->setPos(-70, 0);
}
void WindowView::setClose(){
    windowSlidingPanel->setPos(0, 0);
    magnet->setPos(0, 0 );
}
void WindowView::mousePressEvent(QGraphicsSceneMouseEvent * event){
    if (model!= NULL && event->button()==Qt::LeftButton)
        model->changeState();
}
WindowView::~WindowView(){
    delete windowSlidingPanel;
    delete switchPillar;
}
