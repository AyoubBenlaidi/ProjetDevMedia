#include "scenedejeu.h"
#include <QMouseEvent>
#include <GL/glu.h>





const float MAP_SIZE = 5.0;

SceneDejeu::SceneDejeu(QWidget * parent ):
    QGLWidget(parent)
{
    xRot = 198;
    yRot = 88;
    zRot = 0;

    paintGL();

}


void SceneDejeu::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100,((float)width/(float)height),0.1,100);
    glMatrixMode(GL_MODELVIEW);
}

void SceneDejeu::initializeGL(){
    qglClearColor(Qt::black);

        // Initialisation de l'éclairage/ombrage:
        GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

        glShadeModel (GL_SMOOTH);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);

        glEnable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);


    projectile.init();
    field.init();
    ciblegraph.initial(); // A enlever
    //trebu.init();
}
void SceneDejeu::paintGL(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //Initialisation du système de coordonnées.
    glRotatef(90.0,1.0,0.0,0.0);
    glRotatef(90.0,0.0,0.0,1.0);

    glTranslatef(-23, 0, 0);
    glRotatef(-xRot , 0.0, 1.0, 0.0);
    glRotatef(-yRot , 0.0, 0.0, 1.0);
    glRotatef(-zRot , 1.0, 0.0, 0.0);

    field.draw();
    ciblegraph.draw();
    projectile.draw();
    //trebu.draw();
}

