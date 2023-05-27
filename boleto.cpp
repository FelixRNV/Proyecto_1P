#include "boleto.h"

int Boleto::getAsientos() const
{
    return asientos;
}

void Boleto::setAsientos(int newAsientos)
{
    asientos = newAsientos;
}

const string &Boleto::getAs() const
{
    return as;
}

void Boleto::setAs(const string &newAs)
{
    as = newAs;
}

Boleto::Boleto()
{

}
