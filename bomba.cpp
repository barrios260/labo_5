#include <QGraphicsScene>

#include "bomba.h"
#include "confi.h"

Bomba::Bomba(int *maxBombs) : _maxBombs(maxBombs){ }

Bomba::~Bomba() {
    scene()->removeItem(this);
}

void Bomba::emitExplode() {
    emit explode();
    (*_maxBombs)++;
    delete this;
}
