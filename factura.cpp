#include "factura.h"

float Factura::getTsi() const{
    return tsi;
}

void Factura::setTsi(float newTsi){
    tsi = newTsi;
}



float Factura::getTot() const{
    return tot;
}

void Factura::setTot(float newTot){
    tot = newTot;
}


void Factura::setBoleto(int asientos, vector<string> as){
    boletos.push_back(Boleto(asientos,as));
}

int Factura::getFact() const
{
    return fact;
}

float Factura::getDesc(){
 return DESC;
}

Factura::Factura(){
}

Factura::Factura(int numbo, bool de){
    numf=numf+1;
    tsi=ENTRADA*numbo;
    if (de==true){
        tsi=ENTRADA*numbo*0.9;
    }
    tot=(tsi*IVA/100)+tsi;
    fact=numf;
}
