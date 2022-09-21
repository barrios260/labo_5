#ifndef BOMBA_H
#define BOMBA_H


#include <QObject>
#include <QGraphicsPixmapItem>

class bomba : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit bomba() = default;
    bomba(int * maxbombs);
    ~bomba();
    void emitExplode();

signals:
    void explode();

private:
    int * _maxbombs;

};


#endif // BOMBA_H
