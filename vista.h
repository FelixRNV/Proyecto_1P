#ifndef VISTA_H
#define VISTA_H

#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

#include <constrcine.h>


class Vista
{
private:
    int ESI=201;
    int EII=200;
    int ESD=187;
    int EID=188;
    ConstrCine cineModa;
public:
    Vista();
    void menuIni(); //Menú Inicial
    void menuAdmin(); //Menu para el Administrador
    void menuVende(); //Menu para el vendedor
    void mosPelis(); // Muestra la cartelera
    void mosSimPelis(); //Muestra cartelera
    void menuCompra(); //Menu al momento de comprar
    void imprBoleto(int peli, vector<string> asie, int h); //Muestra el boleto comprado
    void imprFactura(int cli, int peli, vector<string> asie); //Muestra la factura
    string getfecha(); //obtiene la fecha
    void cambiarFunciones(int i); //Cambia a las funciones
    void mosHorarios(int i); //Muestra la Horarios de una Pelicula
    void mosSala(int i,int h); //Muestra el estado de la sala
    void mosClien();    //Muestra a todos los clientes registrados
    void facturacion(int numbo, int peli, vector<string> asie);
    void mosEmpl(); //Muestra los datos de todos los vendedores
    void clearscreen();
    void pausarProgra();
};

#endif // VISTA_H
