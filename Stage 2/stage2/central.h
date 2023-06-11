#ifndef CENTRAL_H
#define CENTRAL_H
#include "door.h"
#include "window.h"

using namespace std;
#include <QtCore/qglobal.h>

class central
{
public:
    central();
    void revisarZonas(vector<Door *> doors, vector<Window *> windows);
};

#endif // CENTRAL_H
