#include "Dinero.h"
#include <QFont>

Dinero::Dinero()
{
    //inicializo el dinero en 100
    setPos(x()+350 ,y());

    setPlainText(QString("Dinero: $") + QString::number(dinero)); // imprime el texto
    setDefaultTextColor(Qt::blue); // cambia de color

    setFont(QFont("Helvetica",20, QFont::Bold)); // Helvetica Negrita tamaño 20

}

int Dinero::getdinero()
{
    return dinero;
}

void Dinero::disdinero(int j)
{
    dinero-=j;
    setPlainText(QString("Dinero: $") + QString::number(dinero));

}

void Dinero::aumdinero(int h)
{
    dinero += h;
    setPlainText(QString("Dinero: $") + QString::number(dinero));
}
