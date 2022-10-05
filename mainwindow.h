#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <vector>
#include "score.h"
#include "player.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     Score * score;
     void recoger();
public slots:
    void playerDied();


private:
    void keyPressEvent(QKeyEvent *event);
    void initFields(int frequency);

    QGraphicsView *_view;
    QGraphicsScene *_scene;
    Player *_player1; //arrows
    Player *_player2; //wsad
    int _playersCount;
    std::vector<std::vector<Field *>> _fields;
};

#endif // MAINWINDOW_H
