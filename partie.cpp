#include "partie.h"
#include <iostream>

Partie::Partie()
{
    startTime_.start();

}




void Partie::addPlayer(Joueur j){
    tabScores_[tabScores_.size()+1]=j ;
}


float Partie::getDuree(){
    return startTime_.elapsed()*0,001;
}
