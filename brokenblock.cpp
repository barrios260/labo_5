#include <QGraphicsScene>

#include "brokenblock.h"

brokenblock::~brokenblock() {
    scene()->removeItem(this);
}
