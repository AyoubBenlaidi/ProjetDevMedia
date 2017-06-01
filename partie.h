#ifndef PARTIE_H
#define PARTIE_H
#include "joueur.h"
#include <QTime>
#include "cible.h"

using namespace std;

class Partie
{
public:

    int score_;
    Cible* niveaux_[10] ; // 10 niveaux
    Partie();
    void genererNiveaux(void);
    int getScore(){return score_;}
    void setScore(int s){score_=s;}
};

#endif // PARTIE_H
