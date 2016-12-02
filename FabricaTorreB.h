#ifndef FABRICATORREB_H
#define FABRICATORREB_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class FabricaTorreB: public QGraphicsPixmapItem{
public:
    FabricaTorreB();
    QGraphicsTextItem *cst;
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // FABRICATORREB_H
