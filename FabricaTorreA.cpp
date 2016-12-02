#include "FabricaTorreA.h"
#include "Game.h"
#include "TorreA.h"
#include <QGraphicsTextItem>
#include <QFont>

extern Game * game;

FabricaTorreA::FabricaTorreA() {// imagen de la fabrica

    setPixmap(QPixmap(":/images/inst.png"));
    cst = new QGraphicsTextItem();
    cst->setPos(this->x()+10,this->y()+60);

    cst->setPlainText(QString("$ 50")); // imprime el texto
    cst->setDefaultTextColor(Qt::black); // cambia de color

    cst->setFont(QFont("Helvetica",15, QFont::Bold)); // Helvetica Negrita tamaño 20

}

void FabricaTorreA::mousePressEvent(QGraphicsSceneMouseEvent* event){ // cambia el raton por la misma imagen
    if (!game->building && game->money->getdinero() >= 50){
        game->building = new TorreA();
        game->setCursor(QString(":/images/inst.png")); //durante el movimiento tendra la imagen
    }
}
