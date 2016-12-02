#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>
#include <QTimer>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QList<QPointF> pointsToFollow, int vd ); // constructor pasa la lista de puntos que seguira
    void rotacion_a(QPointF p); //rotacion hacia algun punto
    void setvida(int j);
    int getvida();
public slots:
    void avanzar();
private:
    QTimer * timer;
    QList<QPointF> points; // lista de puntos a seguir
    QPointF dest;
    int vida = 4;
    int point_index; //indice del array en el que esta
};

#endif // ENEMY_H
