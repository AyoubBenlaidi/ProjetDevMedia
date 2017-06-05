#ifndef CIBLE_H
#define CIBLE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <QImage>


class Cible
{

public:


    //Méthodes de dessin
    void draw();
    void initial();

    explicit Cible(int x=0 , int y=0 );
    int x_ =0 ;
    int y_ =0 ;
    //Cooredonées rand à passer à Opengl
private :
   // coordonnées de la cible


    GLUquadric *gluTargetPrmtrs;
    GLuint textureCible[1];



signals:

public slots:
};

#endif // CIBLE_H
