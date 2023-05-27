#include "vista.h"

Vista::Vista(){
}

void Vista::menuIni(){
    string usua;
    string pas;
    bool men;
    cout << "Ingrese Usuario: ";
    cin >> usua;
    cout << "Ingrese Contraseña: ";
    cin >> pas;
    men=cineModa.usuario(usua,pas);
    if (men==true){
        if (cineModa.getRoll()==true){
            clearscreen();
            menuAdmin();
        } else{
            clearscreen();
            menuVende();
        }
    }


}

void Vista::menuAdmin(){
    int opc;
    do{
        cout << "          --- CineModá ---" << endl;
        cout << "\nPrograma del Cine\n";

        cout << "1. Cambiar Funciones\n";
        cout << "2. Nuevo Vendedor\n";
        cout << "3. Eliminar Vendedor\n";
        cout << "4. Cambiar Contraseña\n";
        cout << "5. Cambiar Usuario\n";
        cout << "0. Cerrar Sesión\n";
        cout << "\nIngresar opción: \t";
        cin >> opc;
        switch(opc){
        case 1:
            int i;
            mosSimPelis();
            cout << "Ingrese opción de pelicula a cambiar: \t";
            cin >> i;
            cambiarFunciones(i);

                break;
        case 2:

                break;
        case 3:

                break;
        case 4:

                break;
        case 5:

                break;
        case 0:

            break;
        default:
            cout << "\nOpción Invalida\n";
            break;
        }
        pausarProgra();
        clearscreen();
    }while (opc != 0);
    cout << "Salio" << endl;
}

void Vista::menuVende(){
    int opc;
    do{

        cout << "          --- CineModá ---" << endl;
        cout << "\nPrograma del Cine\n";

        cout << "1. Cartelera\n";
        cout << "2. Comprar Boletos\n";
        cout << "3. Cambiar Contraseña\n";
        cout << "4. Cambiar Usuario\n";
        cout << "0. Cerrar Sesión\n";
        cout << "\nIngresar opción: \t";
        cin >> opc;
        switch(opc){
        case 1:
            mosPelis();

                break;
        case 2:

                break;
        case 3:

                break;
        case 4:
                break;
        case 0:
            break;
        default:
            cout << "\nOpción Invalida\n";
            break;
        }
        pausarProgra();
        clearscreen();
    }while (opc!=0);
}

void Vista::mosPelis(){
    string nombres[5];
    string idPeli[5];
    string horas1[5];
    string horas2[5];
    int durac[5];
    int sals[5];
    for (int a=0;a<5;a++){
        nombres[a]=cineModa.namePelis(a);
        idPeli[a]=cineModa.idPelis(a);
        horas1[a]=cineModa.horaPeli(a,0);
        horas2[a]=cineModa.horaPeli(a,1);
        durac[a]=cineModa.duraPeli(a);
        sals[a]=cineModa.idSala(a);
    }

    cout << "\n---- Cartelera ----\n";
    cout << left << setw(10) << "Sala"<< setw(2) << "|";
    cout << setw(8) << "ID" << setw(2) << "|";
    cout << setw(14) << "Hora"<< setw(2) << "|";
    cout << setw(8) << "Duración"<< setw(2) << "|";
    cout << setw(8) << "Película"<<endl;

    for (int a=0;a<5;a++){
        cout << left << setw(10) << " " + to_string(sals[a])<< setw(2) << "|";
        cout << setw(8) << idPeli[a]<< setw(2) << "|";
        cout << setw(14) << horas1[a]+" - "+horas2[a]<< setw(2) << "|";
        cout << setw(8) << durac[a]<< setw(2) << "|";
        cout << setw(8) << nombres[a]<< setw(2);
        cout << endl;
    }
}

void Vista::mosSimPelis(){
    string nombres[5];
    string idPeli[5];
    int sals[5];
    for (int a=0;a<5;a++){
        nombres[a]=cineModa.namePelis(a);
        idPeli[a]=cineModa.idPelis(a);
        sals[a]=cineModa.idSala(a);
    }

    cout << "\n---- Cartelera ----\n";
    cout << left << setw(10) << "Opción "<< setw(2) << "|";
    cout << setw(8) << "Sala" << setw(2) << "|";
    cout << setw(8) << "ID" << setw(2) << "|";
    cout << setw(8) << "Película"<<endl;

    for (int a=0;a<5;a++){
        cout << left << setw(10) << " " + to_string(a+1)<< setw(2) << "|";
        cout << setw(8) << to_string(sals[a])<< setw(2) << "|";
        cout << setw(8) << idPeli[a]<< setw(2) << "|";
        cout << setw(8) << nombres[a]<< setw(2);
        cout << endl;
    }
    cout << endl;
}

void Vista::menuCompra(){
    string bus;
    int peli;
    int hori;
    int numbo;
    string asie;
    mosPelis();
    cout << "Ingrese el ID de la pelicula: ";
    cin >> bus;
    peli=cineModa.encontrarPeli(bus);
    cout << "Ingrese el número de boletos: ";
    cin >> numbo;
    mosHorarios(peli);
    cout << "\nIngrese la opción del horario: ";
    cin >> hori;
    mosSala(peli,hori);




}

string Vista::getfecha(){
    return cineModa.getfecha();
}

void Vista::cambiarFunciones(int i)
{
    i=i-1;
    string tit,ids,est;
    int dra,sala,h,m;
    cout << "Ingrese el título: ";
    getline(cin>>ws, tit);
    cout << "Ingrese el ID de la cinta: ";
    cin >> ids;
    cout << "Es un estreno [S/N]: ";
    cin >> est;
    cout << "Duración de la cinta: ";
    cin >> dra;
    cout << "Sale de Proyección: ";
    cin >> sala;
    cout << "Ingrese la hora de proyeccíon\n";
    cout << "Hora: ";
    cin >> h;
    cout << "Minutos: ";
    cin >> m;
    cineModa.setMovie(tit,ids,dra,sala,h,m,i);
    if (est=="S"||est=="s"){
        cineModa.setEstreno(true,i);
    }else {
        cineModa.setEstreno(false,i);
    }
}

void Vista::mosHorarios(int i){
    cout << "\nLos Hoararios Disponibles\n";
    cout << "1. "<< cineModa.horaPeli(i,0);
    cout << "2. "<< cineModa.horaPeli(i,1);
}

void Vista::clearscreen(){
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}

void Vista::pausarProgra(){
#ifdef WINDOWS
    std::system("pause");
#else
    // Assume POSIX
    std::cout<<"\nPresione \"Enter\" para continuar\n";
    std::cin.ignore().get();
#endif
}
