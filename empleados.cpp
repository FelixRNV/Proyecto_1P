#include "empleados.h"

const string &Empleados::getRoll() const
{
    return roll;
}

void Empleados::setRoll(const string &newRoll)
{
    roll = newRoll;
}

const string &Empleados::getUser() const
{
    return user;
}

void Empleados::setUser(const string &newUser)
{
    user = newUser;
}

const string &Empleados::getPass() const
{
    return pass;
}

void Empleados::setPass(const string &newPass)
{
    pass = newPass;
}

Empleados::Empleados()
{

}

Empleados::Empleados(string a, string b, string c, string d, string e):Persona(a,b),roll(c),user(d),pass(e){
}
