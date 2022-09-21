#include <QGraphicsScene>

#include "bomba.h"

bomba::bomba(int *maxbombs) : _maxbombs(maxbombs){ }

bomba::~bomba() {
    scene()->removeItem(this);
}

void bomba::emitExplode() {
    emit explode();
    (*_maxbombs)++;
    delete this;
}
