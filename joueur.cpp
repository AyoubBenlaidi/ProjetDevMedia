#include "joueur.h"
#include<QInputDialog>
#include "mainwindow.h"

Joueur::Joueur()
{

}

string Joueur::getName()
{
    return nom_;
}

void Joueur::setName(string name)
{
    nom_=name;
}

void Joueur::setScore(int score)
{
    Score_=score ;
}

int Joueur::getScore()
{
    return Score_;
}

QTime Joueur::getTotal()
{
    return tempsDeJeuTotal_;

}

void Joueur::setTotal(int timeElapsed)
{
    tempsDeJeuTotal_=QTime(0,0,0,timeElapsed);
}

void Joueur::setTempsParPartie(int partie, QTime temps)
{
    tempsdeJeuParPartie_[partie]=temps;

}

QTime Joueur::getTempsPartie(int nPartie)
{
    return tempsdeJeuParPartie_[nPartie];
}
