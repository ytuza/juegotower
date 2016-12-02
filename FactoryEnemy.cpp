#include "FactoryEnemy.h"
#include "Game.h"
//#include <QDebug>



extern Game * game;

FactoryEnemy::FactoryEnemy()
{
    TimerCrear = new QTimer(this);
    TimerOrda = new QTimer(this);
    connect(TimerOrda,SIGNAL(timeout()),this,SLOT(createEnemies()));
    TimerOrda->start(14000);
}

void FactoryEnemy::paraordas()
{
    TimerOrda->disconnect(); // desconectara el timer
}


void FactoryEnemy::createEnemies()
{

    EnemigosCreados = 0;
    ordas++;
    MaxEnem = 5; // el numero maximo de enemigos es el parametro
    // lo conecta con un timer
    connect(TimerCrear,SIGNAL(timeout()),this,SLOT(newenem()));
    TimerCrear->start(1000);
    if (ordas >= 50){ // si la cantidad de ordas creados es igual a la cant maxima
        paraordas();
    }
    level++;

}

void FactoryEnemy::newenem()
{
    // crea un enemigo
    Enemy * enemy = new Enemy(game->pointsToFollow,level); // crea un enemigo y le pasa como parametro la lista de puntos a seguir
    enemy->setPos(game->pointsToFollow[0]); // inicializa el enemigo en el primer punto
    game->scene->addItem(enemy); // agrega a la escena el enemigo
    EnemigosCreados += 1; // aumenta uno a enemigos creados

    if (EnemigosCreados >= MaxEnem){ // si la cantidad de enemigos creados es igual a la cant maxima
        TimerCrear->disconnect(); // desconectara el timer
    }
}
