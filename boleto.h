#ifndef BOLETO_H
#define BOLETO_H
#include <iostream>
#include <string.h>
using namespace std;

class Boleto
{
private:
    int asientos;
    string as;

public:
    Boleto();
    int getAsientos() const;
    void setAsientos(int newAsientos);
    const string &getAs() const;
    void setAs(const string &newAs);
};

#endif // BOLETO_H
