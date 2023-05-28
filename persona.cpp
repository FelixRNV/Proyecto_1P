#include "persona.h"

const string &Persona::getNombre() const{
    return nombre;
}

const string &Persona::getApellido() const{
    return apellido;
}

Persona::Persona(){

}

Persona::Persona(const string &nombre, const string &apellido) : nombre(nombre),
    apellido(apellido)
{}
