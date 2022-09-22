#ifndef STAGE_H
#define STAGE_H

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

class bomber;

class Field : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT
public:
    Field(int x, int y, QObject *parent = nullptr);
    ~Field();
    blockType isBlockOnField() const;
    void setUnDestroyableBlock(hardblock * hardblock);
    void setDestoryableBlock(brokenblock * brokenblock);
    void setBomb(bomba * bomba);
    void playerOn(bomber * bomber);
    void playerOut(bomber * bomber);
    //void getPowerUp(Player * player);
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
    brokenblock * _brokenblock = nullptr;
    hardblock * _hardblock = nullptr;
    explotion * _explotion = nullptr;
    bomba * _bomba = nullptr;
    bomber * _bomber[sizes::Players];
    //PowerUp * _powerUp = nullptr;
};


#endif // STAGE_H
