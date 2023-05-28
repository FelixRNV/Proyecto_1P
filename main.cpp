#include <iostream>
#include <stdlib.h>
//#include <conio.h>
#include <iomanip>
#include <string>
#include <vista.h>

using namespace std;

Vista *vista = new Vista;
bool mens;
int main()
{
    char op;
    int opc;
    do{
        cout << "--- CineModá ---" << endl;
        cout << "\nPrograma del Cine\n";

        cout << "\n1. Ingresar\n";
        cout << "2. Salir\n";
        cout << "Ingrese la opción deseada: \t";
        cin >> op;
        if (isdigit(int(op))==1){
            if (int(op)==49){
                opc=1;
            }else if (int(op)=50){
                opc=2;
            }
        switch (opc){
        case 1:
            vista->menuIni();
            break;
        case 2:
            break;
        default:
            cout << "\nOpción Invalida\n";
            break;
        }
        }
        vista->pausarProgra();
        vista->clearscreen();
    }while(opc!=2);

    return 0;
}


