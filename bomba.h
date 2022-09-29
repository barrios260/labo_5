#ifndef BOMBA_H
#define BOMBA_H


#include <QObject>
#include <QGraphicsPixmapItem>

class Bomba : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit Bomba() = default;
    Bomba(int * maxbombs);
    ~Bomba();
    void emitExplode();

signals:
    void explode();

private:
    int * _maxBombs;

};


#endif // BOMBA_H
