#include "cliente.h"

int Cliente::getCi() const{
    return ci;
}

void Cliente::setCi(int newCi){
    ci = newCi;
}

const string &Cliente::getCorreo() const{
    return correo;
}

void Cliente::setCorreo(const string &newCorreo){
    correo = newCorreo;
}

const vector<Factura> &Cliente::getHistoria() const{
    return historia;
}

void Cliente::setHistoria(int numbo){
    historia.push_back(Factura(numbo,tercera));
}

bool Cliente::getTercera() const
{
    return tercera;
}

void Cliente::setTercera(bool newTercera)
{
    tercera = newTercera;
}

int Cliente::getlasFac()
{
    return historia.size();
}

string Cliente::datosFact(){
    int a = historia.size();
    a=a-1;
if (tercera==true){
    return "\t\tSubtotal: "+to_string(historia[a].getTsi())+"\n"
           +"\t\tIVA (%12): "+to_string(historia[a].getTsi()*historia[a].IVA/100)+"\n"
           +"\t\tDESC (%10): "+to_string(historia[a].getTsi()*historia[a].DESC/100)+"\n"
           +"\t\tTotal: " + to_string(historia[a].getTot());

}
    return "\t\tSubtotal: "+to_string(historia[a].getTsi())+"\n"
           +"\t\tIVA (%12): "+to_string(historia[a].getTsi()*historia[a].IVA/100)+"\n"
           +"\t\tDESC (%10): 0.00\n"
           +"\t\tTotal: " + to_string(historia[a].getTot());
}

Cliente::Cliente(){
}

Cliente::Cliente(string name, string l_name, int ci, string mail, bool ter):Persona(name,l_name),tercera(ter),ci(ci),correo(mail){
}
