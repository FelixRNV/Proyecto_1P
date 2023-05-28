#include "boleto.h"

int Boleto::getAsientos() const
{
    return asientos;
}

void Boleto::setAsientos(int newAsientos)
{
    asientos = newAsientos;
}


Boleto::Boleto()
{

}

Boleto::Boleto(int asientos, vector<string> as):asientos(asientos),as(as){

}
