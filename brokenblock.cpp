#include <QGraphicsScene>

#include "brokenblock.h"

Brokenblock::~Brokenblock() {
    scene()->removeItem(this);
}
