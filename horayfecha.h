#ifndef HORAYFECHA_H
#define HORAYFECHA_H

#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;

class HorayFecha
{
private:
    int hor;
    int min;
    time_t t = std::time(nullptr);
    tm* now = std::localtime(&t);
public:
    HorayFecha();
    void setHora(int h, int m);
    string getHora();
    string getFecha();
};

#endif // HORAYFECHA_H
