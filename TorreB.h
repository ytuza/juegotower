#ifndef TORREB_H
#define TORREB_H

#include "Tower.h"

class TorreB: public Tower{
    Q_OBJECT
public:
    TorreB();
    void fire();
public slots:
    void obt_objetivo();
};


#endif // TORREB_H
