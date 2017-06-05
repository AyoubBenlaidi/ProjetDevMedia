#include "terrain.h"

Terrain::Terrain()
{
}

void Terrain::init(){
    initgazon();
    initgrillage();
    initLogo();
}




void Terrain::initgazon()
{
    QImage image;
    image.load(":/images/images/grass-small.png");
    image = image.convertToFormat(QImage::Format_RGB888);
    image = image.mirrored();
    glGenTextures(1, &textureGazon[0]);
    glBindTexture(GL_TEXTURE_RECTANGLE, textureGazon[0]);
    glTexImage2D(GL_TEXTURE_RECTANGLE, 0, 3,
                 image.width(), image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 image.bits());

    glTexParameteri(GL_TEXTURE_RECTANGLE,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_RECTANGLE,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

void Terrain::initgrillage()
{
    QImage image;
    image.load(":/images/images/fence.bmp");
    image = image.convertToFormat(QImage::Format_RGB888);
    image = image.mirrored();
    glGenTextures(1, &textureGrillage[0]);
    glBindTexture(GL_TEXTURE_2D, textureGrillage[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 image.width(), image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 image.bits());

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

void Terrain::initLogo(){
    // LOGO TSE
        QImage image;
        image.load(":/images/images/TSE.bmp");
        image = image.convertToFormat(QImage::Format_RGB888);
        image = image.mirrored();

        glGenTextures(1, &textureLogo[0]);
        glBindTexture(GL_TEXTURE_2D, textureLogo[0]);
        glTexImage2D(GL_TEXTURE_2D, 0, 3,
                     image.width(), image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                     image.bits());

        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

}
void Terrain::draw(){

    glDisable(GL_CULL_FACE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable( GL_TEXTURE_RECTANGLE );


    /* Dessin du Gazon */
    glBindTexture(GL_TEXTURE_RECTANGLE, textureGazon[0]);
    glBegin(GL_QUAD_STRIP);
    glColor3f(1,1,1);
    glTexCoord2f (0,0);
    glVertex3f(-30,-20,0);
    glTexCoord2f (512,0);
    glVertex3f(30,-20,0);
    glTexCoord2f (0,512);
    glVertex3f(-30,60,0);
    glTexCoord2f (512,512);
    glVertex3f(30,60,0);
    glEnd();
    glDisable( GL_TEXTURE_RECTANGLE );



    /*  Dessin du grillage */
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureGrillage[0]);
    glDepthMask (GL_TRUE);
    glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);
    glEnable( GL_BLEND );
    glDepthMask (GL_FALSE);
    glBegin(GL_QUAD_STRIP);
    glColor4f(1,1,1,0.5);
    glTexCoord2f (0,0);
    glVertex3f(-30,-12,0);
    glTexCoord2f (0,1);
    glVertex3f(-30,-12,15);
    glTexCoord2f (1,0);
    glVertex3f(-30,60,0);
    glTexCoord2f (1,1);
    glVertex3f(-30,60,15);
    glTexCoord2f (0,0);
    glVertex3f(30,60,0);
    glTexCoord2f (0,1);
    glVertex3f(30,60,15);
    glTexCoord2f (1,0);
    glVertex3f(30,-12,0);
    glTexCoord2f (1,1);
    glVertex3f(30,-12,15);
    glEnd();
    glDisable(GL_TEXTURE_2D);

     glDepthMask (GL_TRUE);
     glDisable (GL_BLEND);
    glDisable( GL_TEXTURE_2D );

    //LOGOS
    glBindTexture(GL_TEXTURE_2D, textureLogo[0]);



       glEnable(GL_TEXTURE_2D);

       glBindTexture(GL_TEXTURE_RECTANGLE, textureLogo[0]);
//



       glPushMatrix();
       glTranslated(0,60,0); //  deplacer  x_ entre -15 et 15 et y_ ente -5 et 40
       glRotated(90,1.0,0,0); //Rotation pour mettre la cible à 45°
       glBegin(GL_QUAD_STRIP);
       glColor3f(1,1,1);


       glTexCoord2f (1,1);
                glVertex3f(-10,10,0);
       glTexCoord2f (1,0);
                  glVertex3f(-10,0,0);
       glTexCoord2f (0,1);
                glVertex3f(10,10,0);
       glTexCoord2f (0,0);
                glVertex3f(10,0,0);

        glEnd();
        glPopMatrix();



          glDisable( GL_TEXTURE_RECTANGLE );


       glDisable(GL_TEXTURE_2D);




















}
