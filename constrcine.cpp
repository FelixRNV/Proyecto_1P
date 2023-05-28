#include "constrcine.h"

bool ConstrCine::getRoll() const
{
    return roll;
}

void ConstrCine::setRoll(bool newRoll)
{
    roll = newRoll;
}

ConstrCine::ConstrCine()
{
    this->admin = new Empleados("Juan","Perez","Administrador","JPerez","A22sad.2");
    this->vende[0] = new Empleados("Juanita","Perez","Vendedora","JuPerez","Juaez2.2");
    this->vende[1] = new Empleados("Pepe","Gutierrez","Vendedor","PGuti","aswqerdf.1");
    this->vende[2] = new Empleados("Leonardo","Jimenez","Vendedor","LeoMenez","kap12.rt5");
    this->peli[0] = new Pelicula("GDLG","Guardianes de la Galaxia", 150 ,false);
    this->peli[1] = new Pelicula("LHLM","La heredera de la Mafia",100,true);
    this->peli[2] = new Pelicula("LCDZ","Los Caballeros del Zodiaco",115,false);
    this->peli[3] = new Pelicula("MUTI","Muti",93,false);
    this->peli[4] = new Pelicula("OSIN","Oso Intoxicado",95,false);
    this->sal[0] = new Sala(1);
    this->sal[1] = new Sala(2);
    this->sal[2] = new Sala(3);
    this->sal[3] = new Sala(4);
    this->sal[4] = new Sala(5);
    peli[0]->setSala(sal[0]->getId());
    peli[1]->setSala(sal[1]->getId());
    peli[2]->setSala(sal[2]->getId());
    peli[3]->setSala(sal[3]->getId());
    peli[4]->setSala(sal[4]->getId());
    this->peli[0]->setHora(23,45,1);
    this->peli[1]->setHora(22,05,1);
    this->peli[2]->setHora(21,25,1);
    this->peli[3]->setHora(21,15,1);
    this->peli[4]->setHora(19,40,1);
    this->peli[0]->setHora(20,22,0);
    this->peli[1]->setHora(18,55,0);
    this->peli[2]->setHora(17,25,0);
    this->peli[3]->setHora(20,15,0);
    this->peli[4]->setHora(17,40,0);
}

string ConstrCine::namePelis(int i){
    return peli[i]->getTitulo();
}

string ConstrCine::getfecha(){
    return date->getFecha();
}

string ConstrCine::idPelis(int i){
    return peli[i]->getId();
}

int ConstrCine::idSala(int i){
    return peli[i]->getSala();
}

int ConstrCine::duraPeli(int i){
    return peli[i]->getDuracion();
}

string ConstrCine::estrenoPeli(int i){
    return peli[i]->getEstreno() ? "Estreno" : "...";
}

string ConstrCine::horaPeli(int i,int h){
    return peli[i]->getHora(h);
}
// Valida el usuario que ingrese
bool ConstrCine::usuario(string usea, string pas){
    bool a;
    a=false;
    roll=false;
    if (admin->getUser()==usea){
        if (admin->getPass()==pas){
            a=true;
            roll=true;
            ven=0;
        }
    }
    for (int b=0;b<3;b++){
        if (vende[b]->getUser()==usea){
            if (vende[b]->getPass()==pas){
                a=true;
                roll=false;
                ven=b+1;
            }
        }
    }
    return a;
}

void ConstrCine::setEstreno(bool a, int i){
    peli[i]->setEstreno(a);
}

void ConstrCine::setMovie(string titulo, string id, int du, int sali, int h, int m,int i)
{
    peli[i]->setTitulo(titulo);
    peli[i]->setId(id);
    peli[i]->setDuracion(du);
    peli[i]->setHora(h,m,0);
    peli[i]->setSala(sali);
    sal[i]->setId(sali);
}

void ConstrCine::setHorario(int i, int h, int hor, int min){
    peli[i]->setHora(hor,min,h);
}

void ConstrCine::llenarSala(int i)
{
    for (int c=0;c<2;c++){
    for (int a=0;a<5;a++){
    for (int b=0;b<5;b++){
        peli[i]->llenaAsiento(c,a,b,false);
    }
    }
    }
}

void ConstrCine::selecAsiento(int i, int co,int h, string k){
int fil=0;
if (k=="a"||k=="A"){
    fil=0;
}else if (k=="b"||k=="B"){
    fil=1;
}else if (k=="c"||k=="C"){
    fil=2;
}else if (k=="d"||k=="D"){
    fil=3;
}else if (k=="e"||k=="E"){
    fil=4;
}
peli[i]->llenaAsiento(h,fil,co,true);
}

string ConstrCine::getAsiento(int i,int a, int b, int h){
    return peli[i]->sabeAsiento(h,a,b) ? "X" : "-";
}

vector<char> ConstrCine::getAsSep(string k){
    vector<char> d;

    for (size_t i=0;i<k.length();++i){
    d.push_back(k[i]);
    }

    return d;
}

int ConstrCine::encontrarPeli(string a){
    for (int i=0;i<5;i++){
    if (peli[i]->getId()==a){
        return i;
    }
}
    return 0;
}

void ConstrCine::setContraseña(string a){
    if (ven==0){
    admin->setPass(a);
    }else if (ven==1){
        vende[0]->setPass(a);
     }else if (ven==2){
    vende[1]->setPass(a);
    }else if (ven==3){
        vende[2]->setPass(a);
    }
}

void ConstrCine::setUsuario(string a){
    if (ven==0){
        admin->setUser(a);
    }else if (ven==1){
        vende[0]->setUser(a);
    }else if (ven==2){
        vende[1]->setUser(a);
    }else if (ven==3){
        vende[2]->setUser(a);
    }
}


