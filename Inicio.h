#ifndef INICIO_H
#define INICIO_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Inicio: public QGraphicsPixmapItem{
public:
    Inicio();
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // INICIO_H
