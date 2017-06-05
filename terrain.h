#ifndef TERRAIN_H
#define TERRAIN_H
#include <GL/gl.h>
#include <GL/glu.h>

#include <QImage>

class Terrain
{
public:
    Terrain();

        //Méthodes de dessin
        void draw();
        void init();
 //       void drawTargetRectangle(int difficultyLevel); //Dessine le rectangle dans lequel se trouvera la cible

        //Chargement des textures
        void initgazon();
        void initgrillage();
        void initLogo();



    protected:


        GLuint GLtexture[1];
        GLuint textureGazon[1]; //Texture Gazon
        GLuint textureGrillage[1]; //Texture Grillage
        GLuint textureLogo[1];
};

#endif // TERRAIN_H
