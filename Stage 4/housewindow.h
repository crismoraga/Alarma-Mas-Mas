#ifndef HOUSEWINDOW_H
#define HOUSEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>
#include "central.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HouseWindow; }
QT_END_NAMESPACE

class HouseWindow : public QMainWindow
{
    Q_OBJECT

public:
    HouseWindow(QWidget *parent = nullptr);
    void addHouseHollow(QGraphicsItemGroup *); // doors and windows
    void setCentral(Central *c);
    ~HouseWindow();

private slots:
    void StartTimer();
    void StopTimer();

private:
    Ui::HouseWindow *ui;
    QGraphicsScene interiorScene;
    Central *c;
};
#endif // HOUSEWINDOW_H
