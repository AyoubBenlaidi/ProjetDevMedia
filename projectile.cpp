#include "projectile.h"

Projectile::Projectile()
{
    x_=-10;
    y_=-10;
    z_=5;

}

void Projectile::init(){


}


void Projectile::draw(){
    GLUquadric* quadric;
    glEnable(GL_COLOR_MATERIAL);
           glColor3f (0.13, 0.14, 0.12);
           glPushMatrix();
           quadric=gluNewQuadric();
           gluQuadricDrawStyle(quadric, GLU_FILL);
           gluQuadricTexture(quadric,1);

           glTranslated(x_,y_,z_);


           gluSphere(quadric,1,10,10);
           gluDeleteQuadric(quadric);
           glPopMatrix();
           glColor4f (1, 1, 1, 0);
       glDisable(GL_COLOR_MATERIAL);
       glFlush();

}
