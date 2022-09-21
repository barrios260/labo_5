#include "bomber.h"


int soldado::getX() const
{
    return x;
}

void soldado::setX(int value)
{
    x = value;
}

int soldado::getY() const
{
    return y;
}

void soldado::setY(int value)
{
    y = value;
}

soldado::soldado(QString name, int w, int h)
{
    setPixmap(QPixmap(name).scaled(w,h));
}

void soldado::posicion()
{
    setPos(x,y);
}

void soldado::posicion(int x_1, int y_1)
{
    x = x_1;
    y = y_1;
    setPos(x_1,y_1);
}
