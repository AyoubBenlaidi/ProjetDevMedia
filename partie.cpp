#include "partie.h"
#include <iostream>

Partie::Partie()
{

    this->genererNiveaux();
}







void Partie::genererNiveaux(void){
    for (int i=1;i<11;i++){
        niveaux_[i]=new Cible();
        niveaux_[i]->rayon_=(11-i)*10+(rand()%10);
        cout<<"niveau : "<<i<< " x : "<< niveaux_[i]->x_ <<" y : "<<niveaux_[i]->y_<<" rayon : "<<niveaux_[i]->rayon_<<endl;
    }
}
