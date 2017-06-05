#ifndef SCENEDEJEU_H
#define SCENEDEJEU_H
#include <QGLWidget>
#include <QTime>
#include <QVector>
#include <QVector3D>
#include "terrain.h"
#include"cible.h"
#include"projectile.h"

class SceneDejeu : public QGLWidget
{
    Q_OBJECT
public:
    explicit SceneDejeu(QWidget * parent =0);
    Terrain field;
    Cible ciblegraph;
    Projectile projectile;
    //Trebuchet trebu;

protected:
    // OpenGL
    void resizeGL(int width, int height);
    void initializeGL() override;
    void paintGL() override;


private:
    int xRot;
    int yRot;
    int zRot;

};

#endif // SCENEDEJEU_H
