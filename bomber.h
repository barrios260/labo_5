#ifndef BOMBER_H
#define BOMBER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>

class soldado: public QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int x = 0;
    int y = 0;

public:
    soldado(QString name, int w,  int h);
    void posicion();
    void posicion(int x_1, int y_1);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);
};

#endif // BOMBER_H
