#include "sala.h"

int Sala::getId() const{
    return id;
}

void Sala::setId(int newId)
{
    id = newId;
}

Sala::Sala(){
}

Sala::Sala(int i):id(i){
}

bool Sala::getAsientosM(int i, int j){
return asientosM[i][j];
}

void Sala::setAsientosM(int i, int j,bool a){
    asientosM[i][j]=a;
}
