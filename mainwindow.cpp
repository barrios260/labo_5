#include <QRandomGenerator>

#include "mainwindow.h"
#include "confi.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    _scene = new QGraphicsScene();
    _scene->setSceneRect(0, 0, 650, 550);
    _scene->clearFocus();

    _view = new QGraphicsView(_scene);
    _view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _view->setFixedSize(650, 550);

    setCentralWidget(_view);
    setWindowTitle(tr("Bomberman"));
    setWindowIcon(QPixmap(":/imagenes/bomba.png"));

    initFields(3);

    _playersCount = sizes::Players;
    _player1 = new Player(0, 0);
    connect(_player1, SIGNAL(playerDied()), this, SLOT(playerDied()));
    _fields[0][0]->playerOn(_player1);
    _player2 = new Player(sizes::Columns - 1, sizes::Rows - 1);
    connect(_player2, SIGNAL(playerDied()), this, SLOT(playerDied()));
    _fields[sizes::Rows - 1][sizes::Columns - 1]->playerOn(_player2);
    _scene->addItem(_player1);
    _scene->addItem(_player2);

    setFocus();
}

MainWindow::~MainWindow() {
    for (std::size_t i = 0; i < sizes::Rows; i++) {
        for(std::size_t j = 0; j < sizes::Columns; j++) {
          delete  _fields[i][j];
        }
    }

    delete _player1;
    delete _player2;
    delete _scene;
    delete _view;
}

void MainWindow::playerDied()
{
    _playersCount--;
    if(_playersCount == 1) {
        delete this;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    setFocus();
    //player1 control
    switch (event->key()) {
        case Qt::Key_A:
            _player1->move(Left, _fields);
            break;
        case Qt::Key_D:
            _player1->move(Right, _fields);
            break;
        case Qt::Key_S:
            _player1->move(Down, _fields);
            break;
        case Qt::Key_W:
            _player1->move(Up, _fields);
            break;
        case Qt::Key_Q:
            _player1->plantBomb(_fields);
            break;
        case Qt::Key_F4:
            close();

    }

}

void MainWindow::initFields(int frequency) {
    for (int i = 0; i < sizes::Rows; i++) {
        _fields.push_back(std::vector<Field *>());
        for(int j = 0; j < sizes::Columns; j++) {
            Field *newField = new Field(j * sizes::FieldSize, i * sizes::FieldSize);
            _fields[static_cast<std::size_t>(i)].push_back(newField);
            _scene->addItem(newField);
            //generating UndestroyableBlocks
            if (i % 2 && j % 2) {
                newField->setUnDestroyableBlock(new Hardblock());
            }
            //generating DestroyableBlocks
            else if ((i > 1 || j > 1) && (i < sizes::Rows - 2 || j < sizes::Columns - 2)) {
                if(QRandomGenerator::global()->bounded(frequency)) {
                    newField->setDestroyableBlock(new Brokenblock());
                }
            }
        }
    }
}
void MainWindow::onTimeOut()
{
    ui->lcdNumber_2->display(tiempo);
    tiempo--;
    if(tiempo == 0){
        score = 0;}
    }
