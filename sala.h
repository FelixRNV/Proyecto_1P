#ifndef SALA_H
#define SALA_H
#include <iostream>
#include <string.h>
using namespace std;


class Sala
{
private:
    int id;
    bool asientosM[5][5];
public:
    Sala();
    Sala(int id);
    bool getAsientosM(int i, int j);
    void setAsientosM(int i, int j, bool a);
    int getId() const;
    void setId(int newId);
};

#endif // SALA_H
