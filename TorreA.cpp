#include "TorreA.h"
#include <QTimer>
#include "Bullet.h"
#include "Game.h"

extern Game * game;

TorreA::TorreA(){
    // conecta el timer para que busq objetivos
    costo = 50;

    timerobj->start(800);
}

//hereda el obtener objetivo
void TorreA::obt_objetivo(){
    Tower::obt_objetivo();
}
