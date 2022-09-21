#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QTimer>
#include "bomber.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *event);

private slots:

    void on_pushButton_clicked();

    void hmov();

private:
    int vel;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    //QGraphicsRectItem *barra;
    soldado *jugador;
    QTimer *timer;
};
#endif // MAINWINDOW_H
