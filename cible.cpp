#include "cible.h"

Cible::Cible(QObject *parent) : QObject(parent)
{
    x_=rand()%255;
    y_=rand()%255;
}
