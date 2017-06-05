#include "partie.h"
#include <iostream>

Partie::Partie()
{
    this->genererCibles();
}







void Partie::genererCibles(void){
    for (int i=0;i<10;i++){

       niveaux_[i]=Cible(rand()%30 + (-15), (i*5)-5 );

       cout<<"niveau : "<<i<< " x : "<< niveaux_[i].x_ <<" y : "<<niveaux_[i].y_<<endl;
    }
}
