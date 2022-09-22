#include <QGraphicsScene>

#include "explotion.h"


explotion::~explotion() {
    scene()->removeItem(this);
}

void explotion::removeExplosion() {
    delete this;
}
