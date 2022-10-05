#include <QGraphicsScene>
#include <QTimer>
#include <QRandomGenerator>
#include <QDebug>

#include "field.h"
#include "player.h"

Field::Field(int x, int y, QObject *parent) : QObject(parent), _x(x), _y(y), _isPlayerOn(false) {
    setPos(x, y);
    setPixmap(QPixmap(":/imagenes/field.png"));
    for (int i = 0; i < sizes::Players; i++) {
        _players[i] = nullptr;
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

void Field::setUnDestroyableBlock(Hardblock *hardblock) {
    createPixmapItem(hardblock, ":/imagenes/solidblock.png");
    _hardblock = hardblock;
}

void Field::setDestroyableBlock(Brokenblock *brokenblock) {
    createPixmapItem(brokenblock, ":/imagenes/destroyblock.png");
    _brokenblock = brokenblock;
}

void Field::setBomb(Bomba *bomba) {
    createPixmapItem(bomba, ":/imagenes/bomba.png");
    _bomba = bomba;
}

void Field::playerOn(Player * player) {
    for (int i = 0; i < sizes::Players; i++) {
        if(!_players[i]) {
            _players[i] = player;
            break;
        }
    }
    _isPlayerOn = true;
}

void Field::playerOut(Player * player) {
    for (int i = 0; i < sizes::Players; i++) {
        if(_players[i] == player)
            _players[i] = nullptr;
        else if(_players[i])
            _isPlayerOn = false;
    }
}

bool Field::isBomb() const {
    if(_bomba == nullptr)
        return false;
    return true;
}

bool Field::isUnDestroyableBlock() const {
    if(_hardblock == nullptr)
        return false;
    return true;
}

blockType Field::isBlockOnField() const
{
    if (_brokenblock)
        return Destroyable;
    else if (_brokenblock)
        return Undestroyable;
    else
        return Empty;
}

bool Field::isClear() const {
    if(_hardblock == nullptr && _brokenblock == nullptr && _bomba == nullptr)
        return true;
    return false;
}


void Field::explosion() {
    _bomba = nullptr;
    if (_brokenblock) {
        delete _brokenblock;
        _brokenblock = nullptr;
        createExplosion();
    }
    else if (!_brokenblock && !_hardblock) {
        createExplosion();
    }
}

void Field::createPixmapItem(QGraphicsPixmapItem *item, QString path) const {
    item->setPos(_x, _y);
    item->setPixmap(QPixmap(path));
    scene()->addItem(item);
}

void Field::createExplosion() {
    _explotion = new explotion();
    createPixmapItem(_explotion, ":/imagenes/fire.gif");
    if(_isPlayerOn == true) {
        for (int i = 0; i < sizes::Players; i++) {
            if(_players[i])
                _players[i]->decreaseHP(this);
        }
    }
    QTimer::singleShot(300, _explotion, &explotion::removeExplosion);
    _explotion = nullptr;
}

