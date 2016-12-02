#include "Bullet.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h> // qSin, qCos, qTan
#include <typeinfo>
#include "Game.h"
#include "Enemy.h"
#include <QDebug>
extern Game * game;

Bullet::Bullet(): QObject(){

    setPixmap(QPixmap(":/images/bal.png")); // el mapa de bits sera de una imagen


    QTimer * move_timer = new QTimer(this); // incializo un timer
    //cada 50 se movera
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    //concectado al slot de movimiento de la bala

    move_timer->start(50);

    // inicializa rango maximo y distancia recorrida
    maxRange = 100;
    DistRec = 0;
}

void Bullet::move(){
    int tam_paso = 30; // tamaño del paso de la bala
    double theta = rotation();  //consigue el angulo a la q se dirige la bala con la rotacion de la imagen

    double dy = tam_paso * qSin(qDegreesToRadians(theta)); // seno del angulo por el paso para hallar loq avanzara en y
    double dx = tam_paso * qCos(qDegreesToRadians(theta));//coseno del angulo por el paso para hallar loq avanzara en x
    DistRec += 30;

    setPos(x()+dx, y()+dy); // cambia la posicion

    QList<QGraphicsItem *> itemsco = this ->collidingItems();

    for (int i = 0, n = itemsco.size(); i<n; ++i ){ //revisara cada elemento de dicha lista


        if(typeid(*(itemsco[i])) == typeid(Enemy)){ // si el elemento es de la clase enemigo

            Enemy * tem = dynamic_cast<Enemy *> (itemsco[i]);
            if(tem->getvida() == 0 ){

                scene() -> removeItem(itemsco[i]); // remueve el elemento que toco
                game->money->aumdinero(10);
                game -> sumPuntaje();
                delete itemsco[i];
                return;

            }

            tem -> setvida(tem->getvida()-1);

            scene() -> removeItem(this); // remueve la bala
            delete this;


            return;


        }
    }
    if(DistRec >= 400){
        scene() -> removeItem(this); // remueve la bala
        delete this;

    }

}

double Bullet::getMaxRange(){
    return maxRange;
}

double Bullet::getDistRec(){
    return DistRec;
}

void Bullet::rango_alc(double rng){
maxRange = rng;
}

void Bullet::setDistRec(double dist){
    DistRec = dist;
}
