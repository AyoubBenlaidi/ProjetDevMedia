#ifndef JOUEUR_H
#define JOUEUR_H
#include "string"
#include <QTime>
#include <map>

using namespace std;

class Joueur
{
private:
    int Score_=1000 ;
    string nom_ ;
    QTime tempsDeJeuTotal_ ;
    map<int , QTime > tempsdeJeuParPartie_;

public:
    Joueur();
    string getName();
    void setName(string name);
    void setScore(int score);
    int getScore();
    QTime getTotal();
    void setTotal(int timeElapsed);
    void setTempsParPartie(int partie , QTime temps);
    QTime getTempsPartie(int nPartie);


};

#endif // JOUEUR_H
