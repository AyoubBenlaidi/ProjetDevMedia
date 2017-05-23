#ifndef PARTIE_H
#define PARTIE_H
#include "joueur.h"
#include <QTime>
#include "map"

using namespace std;

class Partie
{
private:
    QTime startTime_ ;
    map<int , Joueur > tabScores_;
public:
    Partie();


    float getDuree();
    void setDuree(QTime duree){startTime_=duree ;}

    map<int , Joueur > getTabScores() {return tabScores_ ;}
    void addPlayer(Joueur j);
};

#endif // PARTIE_H
