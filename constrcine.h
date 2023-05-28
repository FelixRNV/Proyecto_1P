#ifndef CONSTRCINE_H
#define CONSTRCINE_H

#include <iostream>
#include <string.h>
using namespace std;

#include <empleados.h>
#include <cliente.h>
#include <factura.h>
#include <horayfecha.h>
#include <pelicula.h>
#include <sala.h>

class ConstrCine
{
private:
    bool roll; //roll-> 1=Admin;0=Vendedor
    int ven;
    Sala *sal[5];
    Pelicula *peli[5];
    Empleados *admin;
    Empleados *vende[3];
    HorayFecha *date=new HorayFecha;
    char condi=64;

public:
    ConstrCine();
    string namePelis(int i);
    string getfecha();
    string idPelis(int i);
    int idSala(int i);
    int duraPeli(int i);
    string estrenoPeli(int i);
    string horaPeli(int i, int h);
    bool usuario(string usea, string pas);
    void setEstreno(bool a, int i);
    void setMovie(string titulo,string id,int du,int sal,int h, int m, int i);
    void setHorario (int i,int h, int hor, int min);
    void llenarSala(int i);
    void selecAsiento(int i, int j,int p,string k);
    string getAsiento(int i,int a, int b, int h);
    int encontrarPeli(string a);
    void setContraseña(string a);
    void setUsuario(string a);


    // Métodos para el menú principal
    // Métodos para el administrador
    // Métodos para el vendedor

    bool getRoll() const;
    void setRoll(bool newRoll);
};

#endif // CONSTRCINE_H
