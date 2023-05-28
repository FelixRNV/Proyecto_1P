#ifndef BOLETO_H
#define BOLETO_H
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Boleto
{
private:
    int asientos;
    vector<string> as;

public:
    Boleto();
    Boleto(int asientos, vector<string> as);
    int getAsientos() const;
    void setAsientos(int newAsientos);


};

#endif // BOLETO_H
