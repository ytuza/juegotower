#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "Tower.h"
#include "Vida.h"
#include "FactoryEnemy.h"
#include "Dinero.h"


class Game: public QGraphicsView{
    Q_OBJECT
public:
    static Game* getInstance();

    Game(); //constructor
    void setCursor(QString filename);  // cambia el curso (le pone imagen cuando selecciona el const)
    void mouseMoveEvent(QMouseEvent *event); //recibe el moviemiento del mouse y le sigue imagen si apreto
    void mousePressEvent(QMouseEvent *event); // recibe los click para poner torres
    void creaPista();// dibuja la pista
    void sumPuntaje();
    int getPuntaje();
    void gameover();
    bool getgover();

    Dinero * money;

    FactoryEnemy * factoryenemy;
    QGraphicsScene * scene;
    Vida * vida;
    QGraphicsPixmapItem * cursor; // imagen señalada
    Tower * building; // puntero a torre
    QList<QPointF> pointsToFollow; // lista de puntos del camino


private:
    static bool instanceFlag;
    static Game *single;

    int puntaje = 0;
    bool gover = false;


};

#endif // GAME_H
