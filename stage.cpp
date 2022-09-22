#include <QGraphicsScene>
#include <QTimer>
#include <QRandomGenerator>
#include <QDebug>

#include "stage.h"
#include "bomber.h"

Field::Field(int x, int y, QObject *parent) : QObject(parent), _x(x), _y(y), _isPlayerOn(false) {
    setPos(x, y);
    setPixmap(QPixmap(":/graphics/imagenes/field.png"));
    for (int i = 0; i < sizes::Players; i++) {
        _bomber[i] = nullptr;
    }
}

Field::~Field() {
    if(_brokenblock)
        delete _brokenblock;
    if(_hardblock)
        delete _hardblock;
    if(_explotion)
        delete _explotion;
    if(_bomba)
        delete _bomba;
}

void Field::setUnDestroyableBlock(hardblock *hardblock) {
    createPixmapItem(hardblock, ":/graphics/imagenes/solidblock.png");
    _hardblock = hardblock;
}
