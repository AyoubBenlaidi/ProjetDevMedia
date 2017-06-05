#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <QImage>


class Projectile
{
private:
    int x_=0; //Changer coordonnées de départ
    int y_=0;
    int z_=0;
    int moveLast_=5; //Durée du mouvement


public:
    Projectile();
    void draw();
    void init();

   // void trajectoire(int vitesse ); //déterminer y corréspondant

    int getMoveLast(){return moveLast_ ;}
    void setMoveLast(int s){moveLast_=s;}
    int getX(){return z_;}
    void setX(int x){x_=x;}
    int getY(){return z_;}
    void setY(int y){y_=y;}
    int getZ(){return z_;}
    void setZ(int z){z_=z;}
};

#endif // PROJECTILE_H
