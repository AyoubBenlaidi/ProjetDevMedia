#ifndef CIBLE_H
#define CIBLE_H

#include <QObject>

class Cible : public QObject
{
    Q_OBJECT
public:
    explicit Cible(QObject *parent = 0);
    //Cooredonées rand à passer à Opengl
    int x_ ;
    int y_ ;
    int rayon_; //De plus en plus petit selon le niveau



signals:

public slots:
};

#endif // CIBLE_H
