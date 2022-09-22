#include <QGraphicsScene>

#include "hardblock.h"

hardblock::~hardblock() {
    scene()->removeItem(this);
}
