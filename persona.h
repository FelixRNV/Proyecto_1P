#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <string.h>
using namespace std;


class Persona
{
private:
    string nombre;
    string apellido;
public:
    Persona();
    Persona(const string &nombre, const string &apellido);

};

#endif // PERSONA_H
