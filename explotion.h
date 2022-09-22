#ifndef EXPLOTION_H
#define EXPLOTION_H


#include <QGraphicsPixmapItem>
#include <QObject>

class explotion : public QGraphicsPixmapItem, public QObject  {
public:
    explotion() = default;
    ~explotion();
    void removeExplosion();
};
#endif // EXPLOTION_H
