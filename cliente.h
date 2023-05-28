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
    bool tercera=0;
    vector<Factura> historia;
public:
    Cliente();
    Cliente(string name, string l_name, int ci, string mail, bool ter);
    int getCi() const;
    void setCi(int newCi);
    const string &getCorreo() const;
    void setCorreo(const string &newCorreo);
    const vector<Factura> &getHistoria() const;
    void setHistoria(int numbo);
    bool getTercera() const;
    void setTercera(bool newTercera);
    int getlasFac();
    string datosFact();
};

#endif // CLIENTE_H
