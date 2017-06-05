#include "cible.h"

Cible::Cible(int x , int y)
{
    x_=x;
    y_=y;

}


void Cible::draw(){
    glBindTexture(GL_TEXTURE_2D, textureCible[0]);



       glEnable(GL_TEXTURE_2D);

       glBindTexture(GL_TEXTURE_RECTANGLE, textureCible[0]);
//



       glPushMatrix();
       glTranslated(x_,y_,0); //  deplacer  x_ entre -15 et 15 et y_ ente -5 et 40
       glRotated(45,1.0,0,0); //Rotation pour mettre la cible à 45°
       glBegin(GL_QUAD_STRIP);
       glColor3f(1,1,1);


       glTexCoord2f (0,0);
                glVertex3f(-5,10,0);
       glTexCoord2f (0,1);
                  glVertex3f(-5,0,0);
       glTexCoord2f (1,0);
                glVertex3f(5,10,0);
       glTexCoord2f (1,1);
                glVertex3f(5,0,0);

        glEnd();
        glPopMatrix();



          glDisable( GL_TEXTURE_RECTANGLE );


       glDisable(GL_TEXTURE_2D);

}

void Cible::initial(){



    QImage image;
    image.load(":/images/images/target2.bmp");
    image = image.convertToFormat(QImage::Format_RGB888);
    image = image.mirrored();

    glGenTextures(1, &textureCible[0]);
    glBindTexture(GL_TEXTURE_2D, textureCible[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 image.width(), image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 image.bits());

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

}
