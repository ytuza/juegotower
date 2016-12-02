#include "FabricaTorreB.h"
#include "Game.h"
#include "TorreB.h"

extern Game * game;

FabricaTorreB::FabricaTorreB(){ // imagen de la fabrica
    setPixmap(QPixmap(":/images/facep.png"));
    cst = new QGraphicsTextItem();
    cst->setPos(this->x()+10,this->y()+190);

    cst->setPlainText(QString("$ 100")); // imprime el texto
    cst->setDefaultTextColor(Qt::black); // cambia de color

    cst->setFont(QFont("Helvetica",15, QFont::Bold)); // Helvetica Negrita tamaño 15
}

void FabricaTorreB::mousePressEvent(QGraphicsSceneMouseEvent* event){//al apretar en la fabrica
    if (!game->building && game->money->getdinero() >= 100){
        game->building = new TorreB(); // creara un objeto torreb
        game->setCursor(QString(":/images/facep.png")); // la imagen seguira al cursor
    }
}
