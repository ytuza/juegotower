#include "Game.h"
#include "Inicio.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "TorreA.h"
#include "TorreB.h"
#include "Bullet.h"
#include "Enemy.h"
#include "FabricaTorreA.h"
#include "FabricaTorreB.h"
#include <QElapsedTimer>
#include <QTimer>
#include <QGraphicsLineItem>
#include <QPen>
#include <QGraphicsPixmapItem>

#include <QDebug>
#include <typeinfo>

#include <QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>

bool Game::instanceFlag = false;
Game* Game::single = NULL;

Game *Game::getInstance()
{
    if(!instanceFlag)
    {
        single = new Game();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}

Game::Game(): QGraphicsView(){

    scene = new QGraphicsScene(this); // crea una escena


    scene->setSceneRect(0,0,800,600); // establece el tamaño


    setBackgroundBrush(QBrush(QImage(":/images/fondopas.png")));

    // realiza los cambios en la escena
    setScene(scene);

    // inicializa los cursores
    cursor = nullptr;
    building = nullptr;
    setMouseTracking(true);

    // alter window
    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // elimina las barras horizontal y vertical
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    //crear vida

    vida = new Vida();
    scene -> addItem(vida);

    money = new Dinero();
    scene -> addItem(money);

    pointsToFollow << QPointF(700,0) << QPointF(700,150) << QPointF(300,150) << QPointF(300,300) << QPointF(700,300) << QPointF(700,450)<< QPointF(300,450) << QPointF(0,600);

    factoryenemy = new FactoryEnemy();

    // creo el camino (funcion abajo)
    creaPista();

    // Creo los constructores
    FabricaTorreA * fa = new FabricaTorreA();
    FabricaTorreB * fb = new FabricaTorreB();

    fb ->setPos(x()+5,y()+120);
    scene->addItem(fa->cst);
    scene->addItem(fb->cst);


    //lso agrego a la escena
    scene->addItem(fa);
    scene -> addItem(fb);

    QMediaPlayer * music = new QMediaPlayer();// inicializamos un puntero a un objeto qmedia
    music->setMedia(QUrl("qrc:/music/emot.m4a")); // set de la ubicacion del archivo

    music->play(); // reproduccion


}

void Game::setCursor(QString filename){
    //funcion para que cuando haga click el cursor tenga el icono apretado
    //de parametro pasa un string con la direccion de la imagen

    if (cursor){ // elimina un cursor si lo hubiera
        scene->removeItem(cursor);
        delete cursor;
    }
    //crea un objeto mapa de bits y le define la imagen pasadotcomo parametro(la direccion)
    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(filename));
    scene->addItem(cursor); // la agrega a la escena
}

void Game::mouseMoveEvent(QMouseEvent *event){ // Moviemiento del cursor
    if (cursor){ // si el cursor tiene una imagen
        cursor->setPos(event->pos()); // debera seguir el cursor
    }
}

void Game::mousePressEvent(QMouseEvent *event){

    if (building){ // si no es nulo el puntero a torre (si a presionado un constructor)
        // crea una lista con las colisiones
        QList<QGraphicsItem *> items = cursor->collidingItems();

        //revisa si no choca con nada , si lo hace no realiza nada y sale de la funcion
        if (items.size() > 2 ){
            //qDebug() << "entro";
            return;
        }

        //qDebug() << "salio" << items.size() ;
        // si no crea un objeto torre
        scene->addItem(building);
        money -> disdinero(building -> costo);
        building->setPos(event->pos()); // cambia la posicion de la torre a la del teclado
        cursor = nullptr; // cursor vuelve a ser nulo no tiene imagen
        building = nullptr; // el puntero a torre apunta al vacio
    }
    else {
        QGraphicsView::mousePressEvent(event); // si no es un constructor seguira esperando
    }

}


void Game::creaPista(){ //creo la pista
    for (size_t i = 0, n = pointsToFollow.size()-1; i < n; i++){
        //crea lineas con cada dos puntos del array
        QLineF line(pointsToFollow[i],pointsToFollow[i+1]);
        QGraphicsLineItem * lineItem = new QGraphicsLineItem(line);
        //DIBUJA la linea
        QPen pen;
        pen.setWidth(10); //grosor
        pen.setColor(Qt::green); // color

        lineItem->setPen(pen);  // la pinta
        scene->addItem(lineItem);

    }
}



void Game::sumPuntaje()
{
    puntaje++;
}

int Game::getPuntaje()
{
    return puntaje;
}

void Game::gameover()
{
    gover = true;
    factoryenemy->paraordas();
    QGraphicsTextItem *go;
    go = new QGraphicsTextItem();
    go->setPos(go->x()+150,go->y()+200);

    go ->setPlainText(QString("GAME OVER")); // imprime el texto
    go->setDefaultTextColor(Qt::red ); // cambia de color

    go->setFont(QFont("Helvetica",60, QFont::Bold)); // Helvetica Negrita tamaño 20
    scene->addItem(go);



    QGraphicsTextItem *ultpt;
    ultpt = new QGraphicsTextItem();
    ultpt->setPos(ultpt->x()+300,ultpt->y()+280);

    ultpt ->setPlainText(QString("Puntaje: ") + QString::number(getPuntaje())); // imprime el texto
    ultpt->setDefaultTextColor(Qt::black ); // cambia de color

    ultpt->setFont(QFont("Helvetica",25, QFont::Bold)); // Helvetica Negrita tamaño 25
    scene->addItem(ultpt);


}

bool Game::getgover()
{
    return gover;
}

