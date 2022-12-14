#include "score.h"

#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //inicializar score en 0
    score = 0;

    //draw the text
    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ")+QString::number(score));
}

int Score::getScore()
{
    return score;
}
