#include "Inicio.h"
#include <QThread>
#include "Game.h"
#include <QDebug>
#include <QWaitCondition>

extern Game * game;
Inicio::Inicio()
{
    //game -> setBackgroundBrush(QBrush(QImage(":/images/towerf.jpg")));
    setPixmap(QPixmap(":/images/gyp.png"));
    //setPos(x()+200,y()+120);


}

void Inicio::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    qDebug() << "click" ;

}
