#include "scenedejeu.h"
#include <GL/glut.h>

SceneDejeu::SceneDejeu(QWidget * parent ):
    QGLWidget(parent)
{

}

void SceneDejeu::initializeGL(){
    glClearColor(.2,.2,.2,0);


}
void SceneDejeu::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,0);
    glBegin(GL_TRIANGLES);

    glVertex3f(-.5 ,-.5 ,0);

    glVertex3f(.5 ,-.5 ,0);

    glVertex3f( 0 ,.5 ,0);


    glEnd();


   // glutWireTeapot(0.6);

}
void SceneDejeu::resizeGL(int w , int h ){



}
