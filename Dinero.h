#ifndef DINERO_H
#define DINERO_H

#include <QGraphicsTextItem>

class Dinero : public QGraphicsTextItem {
public:
    Dinero();
    int getdinero();
    void disdinero(int j);
    void aumdinero(int h);
private:
    int dinero = 200;

};
#endif // DINERO_H
