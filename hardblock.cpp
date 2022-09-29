#include <QGraphicsScene>

#include "hardblock.h"

Hardblock::~Hardblock() {
    scene()->removeItem(this);
}
