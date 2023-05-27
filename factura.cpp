#include "factura.h"

float Factura::getTsi() const{
    return tsi;
}

void Factura::setTsi(float newTsi){
    tsi = newTsi;
}

int Factura::getDESC() const{
    return DESC;
}

int Factura::getIVA() const{
    return IVA;
}

float Factura::getTot() const{
    return tot;
}

void Factura::setTot(float newTot){
    tot = newTot;
}

float Factura::getENTRADA() const{
    return ENTRADA;
}

Factura::Factura(){
}
