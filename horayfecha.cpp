#include "horayfecha.h"

HorayFecha::HorayFecha(){
}

void HorayFecha::setHora(int h, int m){
    hor=h;
    min=m;
}

string HorayFecha::getHora(){
    if (min<10){
        return to_string(hor)+"h0"+to_string(min);
    }
    return to_string(hor)+"h"+to_string(min);
}

string HorayFecha::getFecha(){
    string str;
    str= to_string(now->tm_mday) + '/' + to_string(now->tm_mon + 1) + "/"+ to_string(now->tm_year + 1900);
 return str;
}
