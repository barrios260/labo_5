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
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     void recoger();
public slots:
    void playerDied();


private slots:
    void onTimeOut();
private:
    void keyPressEvent(QKeyEvent *event);
    void initFields(int frequency);
    int tiempo = 40;
    Ui::MainWindow *ui;
    QGraphicsView *_view;
    QGraphicsScene *_scene;
    Player *_player1; //wasdqf4
    Player *_player2;
    int _playersCount;
    int score = 0;
    std::vector<std::vector<Field *>> _fields;
};

#endif // MAINWINDOW_H
