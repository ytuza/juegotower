#include "TorreB.h"
#include <QTimer>
#include "Bullet.h"
#include "Game.h"

extern Game * game;


TorreB::TorreB()
{
    costo = 100;
    // conecta el timer para que busq objetivos
    // en consecuencia del juego mientras menor sea el tiempo que encuentre un nuevo objetivo
    // mas precisa seran las balas lanzadas

    timerobj->start(1000);
}

void TorreB::fire()
{

    Bullet *bala1 = new Bullet();
    Bullet *bala2 = new Bullet();
    Bullet *bala3 = new Bullet();

    bala1 -> setPixmap(QPixmap(":/images/felizo.png"));
    bala2 -> setPixmap(QPixmap(":/images/felizo.png"));
    bala3 -> setPixmap(QPixmap(":/images/felizo.png"));

    bala1->setPos(x()+44,y()+44);
    bala2->setPos(x()+44,y()+44);
    bala3->setPos(x()+44,y()+44);

    QLineF ln(QPointF(x()+44,y()+44),attack_dest);
    int angle = -1 * ln.angle();

    bala1->setRotation(angle);
    bala2->setRotation(angle+10);
    bala3->setRotation(angle-10);

    game->scene->addItem(bala1);
    game->scene->addItem(bala2);
    game->scene->addItem(bala3);

}

void TorreB::obt_objetivo(){
    Tower::obt_objetivo();
}
