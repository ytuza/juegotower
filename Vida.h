#ifndef VIDA_H
#define VIDA_H

#include <QGraphicsTextItem>

class Vida : public QGraphicsTextItem {
public:
    Vida();
    void disvida();
    int getVida();
private:
    int vida;
};

#endif // VIDA_H
