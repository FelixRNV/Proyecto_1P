#ifndef CLIENTE_H
#define CLIENTE_H

#include <persona.h>
#include <factura.h>

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


class Cliente: public Persona
{
private:
    int ci;
    string correo;
    vector<Factura> historia;
public:
    Cliente();
    Cliente(string, string, int, string);
};

#endif // CLIENTE_H
