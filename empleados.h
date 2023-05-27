#ifndef EMPLEADOS_H
#define EMPLEADOS_H

#include <persona.h>

#include <iostream>
#include <string.h>
using namespace std;


class Empleados: public Persona
{
private:
    string roll;
    string user;
    string pass;
public:
    Empleados();
    Empleados(string, string, string, string, string);
    const string &getRoll() const;
    void setRoll(const string &newRoll);
    const string &getUser() const;
    void setUser(const string &newUser);
    const string &getPass() const;
    void setPass(const string &newPass);
};

#endif // EMPLEADOS_H
