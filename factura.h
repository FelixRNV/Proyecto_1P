#ifndef FACTURA_H
#define FACTURA_H


#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

#include <boleto.h>

class Factura
{
private:
    float tsi; //Total sin impuestos
    const int DESC=10; //Porcentaje de Descuento Preferencial
    const int IVA=12; //Porcentaje de IVA
    const float ENTRADA=3.15; //Costo de la Entrada Individual
    float tot; //Total de la  Factura
    int numf; //Número de factura por cliente
    vector<Boleto*> boleto;

public:
    Factura();
    float getTsi() const;
    void setTsi(float newTsi);
    int getDESC() const;
    int getIVA() const;
    float getTot() const;
    void setTot(float newTot);
    float getENTRADA() const;
};

#endif // FACTURA_H
