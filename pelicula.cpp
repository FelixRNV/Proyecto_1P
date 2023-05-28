#include "pelicula.h"

const string &Pelicula::getId() const{
    return id;
}

const string &Pelicula::getTitulo() const{
    return titulo;
}

int Pelicula::getDuracion() const{
    return duracion;
}

bool Pelicula::getEstreno() const{
    return estreno;
}

void Pelicula::setId(const string &newId){
    id = newId;
}

void Pelicula::setTitulo(const string &newTitulo){
    titulo = newTitulo;
}

void Pelicula::setDuracion(int newDuracion){
    duracion = newDuracion;
}

void Pelicula::setEstreno(bool newEstreno){
    estreno = newEstreno;
}

int Pelicula::getSalaID(int h) const
{
    return sal[h].getId();
}

void Pelicula::setSala(int newSala)
{
    sala = newSala;
}

void Pelicula::setHora(int ho, int min, int i){
    hora[i].setHora(ho,min);
}

string Pelicula::getHora(int i)
{
    return hora[i].getHora();
}

void Pelicula::llenaAsiento(int h,int f,int co,bool con)
{
    sal[h].setAsientosM(f,co,con);
}

bool Pelicula::sabeAsiento(int h, int f, int c){
    return sal[h].getAsientosM(f,c);
}

Pelicula::Pelicula(){
}

Pelicula::Pelicula(const string &id, const string &titulo, int duracion, bool estreno) : id(id),
    titulo(titulo),
    duracion(duracion),
    estreno(estreno)
{}
