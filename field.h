#ifndef FIELD_H
#define FIELD_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "brokenblock.h"
#include "hardblock.h"
#include "explotion.h"
#include "bomba.h"
#include "confi.h"

enum blockType {
    Destroyable,
    Undestroyable,
    Empty
};

class Player;

class Field : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

public:
    Field(int x, int y, QObject *parent = nullptr);
    ~Field();
    blockType isBlockOnField() const;
    void setUnDestroyableBlock(Hardblock *hardblock);
    void setDestroyableBlock(Brokenblock * brokenblock);
    void setBomb(Bomba * bomba);
    void playerOn(Player * player);
    void playerOut(Player * player);
    void getPowerUp(Player * player);
    bool isBomb() const;
    bool isUnDestroyableBlock() const;
    bool isClear() const;

public slots:
    void explosion();

private:
    void createPixmapItem(QGraphicsPixmapItem *item, QString path) const;
    void createExplosion();
    void randPowerUp();

    int _x;
    int _y;
    bool _isPlayerOn;
    Brokenblock * _brokenblock = nullptr;
    Hardblock * _hardblock = nullptr;
    explotion * _explotion = nullptr;
    Bomba * _bomba = nullptr;
    Player * _players[sizes::Players];
};

#endif // FIELD_H
