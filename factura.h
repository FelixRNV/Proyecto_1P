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
    float tot; //Total de la  Factura
    int fact;
    vector<Boleto> boletos;

public:
    static int numf; //Número de factura por cliente
    const int DESC=10; //Porcentaje de Descuento Preferencial
    const int IVA=12; //Porcentaje de IVA
    const float ENTRADA=3.15; //Costo de la Entrada Individual
    Factura();
    Factura(int numbo, bool de);
    float getTsi() const;
    void setTsi(float newTsi);
    float getTot() const;
    void setTot(float newTot);
    void setBoleto(int asientos, vector<string> as);
    int getFact() const;
    float getDesc();
};

#endif // FACTURA_H
