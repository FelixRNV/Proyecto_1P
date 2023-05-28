#ifndef PELICULA_H
#define PELICULA_H

#include <sala.h>
#include <horayfecha.h>

#include <iostream>
#include <string.h>
using namespace std;


class Pelicula
{
private:
    string id;
    string titulo;
    int duracion;
    bool estreno;
    HorayFecha hora[2];
    int sala;
    Sala sal[2];
public:
    Pelicula();
    Pelicula(const string &id, const string &titulo, int duracion, bool estreno);

    const string &getId() const;
    const string &getTitulo() const;
    int getDuracion() const;
    bool getEstreno() const;
    void setId(const string &newId);
    void setTitulo(const string &newTitulo);
    void setDuracion(int newDuracion);
    void setEstreno(bool newEstreno);
    int getSalaID(int h) const;
    void setSala(int newSala);
    void setHora(int ho,int min,int i);
    string getHora(int i);
    void llenaAsiento(int h,int f,int co,bool con);
    bool sabeAsiento(int h,int f,int c);
};

#endif // PELICULA_H
