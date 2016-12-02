#include "Vida.h"
#include <QFont>
#include "Game.h"
extern Game * game;

Vida::Vida()
{
    vida = 10; //inicializo la vida en 10
    setPos(x()+100 ,y());

    setPlainText(QString("Vidas ☢ : ") + QString::number(vida)); // imprime el texto
    setDefaultTextColor(Qt::red); // cambia de color

    setFont(QFont("Helvetica",20, QFont::Bold)); // Helvetica Negrita tamaño 20

}

void Vida::disvida()
{
    vida--;
    setPlainText(QString("Vidas ☢ : ") + QString::number(vida));
    if(vida <= 0){
        game->gameover();
    }
}

int Vida::getVida()
{
    return vida;
}
