#include "Enemy.h"
#include "Game.h"
#include <QPixmap>

#include <qmath.h>
#include <QDebug>
extern Game * game;

Enemy::Enemy(QList<QPointF> pointsToFollow, int vd){
    // imagen del enemigo
    setPixmap(QPixmap(":/images/enem_opt.png"));
    vida = vd;


    //copia los puntos a seguir
    points = pointsToFollow;
    point_index = 0; // indice de puntos (el suigiente q toca)
    dest = points[0]; // destino, el punto q toca seguir
    rotacion_a(dest); //gira la imagen al punto siguiente

    // conecta el timer al enemigo para que avance
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(avanzar()));
    timer->start(150);

}

void Enemy::rotacion_a(QPointF p){
    QLineF ln(pos(),p); // crea una linea de la posicion al punto q girara

    setRotation(-1*ln.angle()); // gira la imagen con el angulo negativo de la linea
}

void Enemy::setvida(int j)
{
    vida = j;
}

int Enemy::getvida()
{
    return vida;
}

void Enemy::avanzar(){
    if(game->getgover()){
        timer->disconnect();
    }

    QLineF ln(pos(),dest); //linea de la posicion al destino

    if (ln.length() < 5){ // si el tamaño es menor a 5 osea antes de q acabe voltea
        point_index++; // indice de puntos
        //  ultimo punto
        if (point_index >= points.size()){
            game -> vida -> disvida();
            scene() -> removeItem(this);
            delete this;
            return; // ya no gira ni se mueve
        }
        // cambia el destino y rota la imagen
        dest = points[point_index];
        rotacion_a(dest);
    }

    // mueve al enemigo
    int STEP_SIZE = 5;
    double theta = rotation(); // gira al enemigo

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta)); //avance en y
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta)); // avance en x

    setPos(x()+dx, y()+dy); // cambio de pos
}
