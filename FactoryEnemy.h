#ifndef FACTORYENEMY_H
#define FACTORYENEMY_H
#include "Enemy.h"
#include <QTimer>


class FactoryEnemy: public QObject{
    Q_OBJECT
public:
    FactoryEnemy();
    void paraordas();
private:
    QTimer *TimerCrear;
    QTimer *TimerOrda;
    int ordas = 0;
    int EnemigosCreados = 0; // enemigos creados
    int MaxEnem = 0; // maximo de enemigos creados
    int level = 4;


public slots:
    void createEnemies();
    void newenem();
};

#endif // FACTORYENEMY_H
