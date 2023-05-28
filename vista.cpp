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
            menuCompra();
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
    string bus,as;
    int peli;
    int hori;
    int numbo;
    vector<string> asie;
    vector<char> sep;
    Cliente cli;
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
    for (int z=0;z<numbo;z++){
        cout << "Escoja el asiento "<< z+1 <<": ";
        cin>>as;
        asie.push_back(string(as));
        sep=cineModa.getAsSep(as);
        cineModa.selecAsiento(peli,hori,sep);
    }
    cout << "\nLos asientos escogidos son: ";
    for (int z=0;z<int(asie.size());z++){
        cout << asie[z];
        if (int(asie.size())>1 && z<(int(asie.size())-1)){
        cout<< " , ";
        }
    }
    cout << endl;
    cout << "Confirma la selección S-> Seguir, N-> Menú : ";
    cin >> as;
    if (as=="S"||as=="s"){
        facturacion(numbo,peli,asie);

    }
}

void Vista::imprBoleto(int peli, vector<string> asie,int h){
    cout << "----- Boleto ------\n";
    cout << left << setw(4) << "╔";
    for (int p=0;p<100;p++){
        cout<<setw(4)<<"═";
    }
    cout<<setw(4)<<"╗"<<endl<<setw(4)<<"║";
    cout<<"Sala: "<<cineModa.idPelis(peli);
    for (int p=0;p<91;p++){
        cout<<setw(4)<<" ";
    }
    cout<<endl<<setw(4)<<"║"<<"Hora: "<<cineModa.horaPeli(peli,h);
    for (int p=0;p<84;p++){
        cout<<setw(4)<<" ";
    }
    cout<<endl<<setw(4)<<"║"<<"Asiento(s): ";
    for (int z=0;z<int(asie.size());z++){
        cout << asie[z];
        if (int(asie.size())>1 && z<(int(asie.size())-1)){
        cout<< " , ";
        }
    }
    if(int(asie.size())==1){
    for (int p=0;p<85;p++){
        cout<<setw(4)<<" ";
    }}else{
        for (int p=0;p<(2+int(asie.size()*6));p++){
            cout<<setw(4)<<" ";
    }}
    cout<<endl<<setw(4)<<"║"<<"Pelicula: "<<cineModa.namePelis(peli);
    for (int p=0;p<(100-int(cineModa.namePelis(peli).size()));p++){
        cout<<setw(4)<<" ";
}
}

void Vista::imprFactura(int cli, int peli, vector<string> asie){
        cout << "\n ----- ------ Cine Moda ------ -----\n";
        cout << "Factura Número: " << cineModa.lastFactCli(cli)<<endl;
        cout << "Cliente: " << cineModa.clienName(cli) << endl;
        cout << "C.I.: " << cineModa.clienCI(cli) << endl;
        cout << "E-mail: " << cineModa.clienMail(cli) << endl;
        cout << "---- ---- ---- ---- ---- ---- ---- ----\n";
        cout << "Película: "<< cineModa.namePelis(peli) << endl;
        cout << "Asientos: ";
        for (int z=0;z<int(asie.size());z++){
            cout << asie[z];
            if (int(asie.size())>1 && z<(int(asie.size())-1)){
            cout<< " , ";
            }
        }
        cout << endl;
        cout << cineModa.dataFact(cli);
}

void Vista::facturacion(int numbo, int peli, vector<string> asie){
    int op, pos;
    string name, l_name, email,te;
    int ci;
    bool ter;
    Cliente cli;
    cout << "\nSeleccione la opción de cliente: \n";
    cout << "\n1. Consumidor Final";
    cout << "\n2. Buscar Cliente";
    cout << "\n3. Cliente Nuevo";
    cout << "\n4. Ver Clientes";
    cout << "\nSelccionar opción: ";
    cin >> op;
    switch(op){
    case 1:
        pos=0;
        break;
    case 2:
        cout << "Ingrese el CI del Cliente: ";
        cin >> ci;
        cli=cineModa.encontrarCli(ci);
        ci=cli.getCi();
        for (int l=0;l<cineModa.numClien();l++){
            if (ci==cineModa.clienCI(l)){
                pos=l;
            }else {
                pos=0;
            }
        }
        break;
    case 3:
        cout << "\nIngrese el Nombre: ";
        cin >> name;
        cout << "\nIngrese el Apellido: ";
        cin >> l_name;
        cout << "\nIngrese el CI: ";
        cin >> ci;
        cout << "\nIngrese el correo: ";
        cin >> email;
        cout << "\nTiene tercera edad [S/n]: ";
        cin >> te;
        if (te=="S"||te=="s"){
            ter=true;
        }else{
            ter=false;
        }
        cineModa.newClien(name,l_name,ci,email,ter);
        pos=cineModa.numClien();
        pos=pos-1;
        break;
    case 4:
        mosClien();
        cout << "Ingresar la OPC que desea: ";
        cin >> ci;
        pos=ci-1;
        break;
    default:
        pos=-1;
        break;
    }
    cout << endl;

    cineModa.facturar(pos,numbo);
    cout << "\nPara Imprimir Factura Presione \"Enter\"...";
    pausarProgra();
    clearscreen();
    imprFactura(pos, peli,asie);
    pausarProgra();
    clearscreen();
    imprBoleto(peli,asie;
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
    cout << "Ingrese el horario de proyección 1:\n";
    cout << "Hora: ";
    cin >> h;
    cout << "Minutos: ";
    cin >> m;
    cineModa.setMovie(tit,ids,dra,sala,h,m,i);
    cout << "Ingrese el horario de proyección 2:\n";
    cout << "Hora: ";
    cin >> h;
    cout << "Minutos: ";
    cin >> m;
    cineModa.setHorario(i,1,h,m);
    if (est=="S"||est=="s"){
        cineModa.setEstreno(true,i);
    }else {
        cineModa.setEstreno(false,i);
    }
}

void Vista::mosHorarios(int i){
    cout << "\nLos Hoararios Disponibles\n";
    cout << "1. "<< cineModa.horaPeli(i,0)<<endl;
    cout << "2. "<< cineModa.horaPeli(i,1)<<endl;
}

void Vista::mosSala(int i, int h){
    cout << "--- Sala "<<cineModa.idSala(i)<<" ---\n";
    cout << left<<setw(4)<<" "<<setw(4)<<"1"<< setw(4)<<"2";
    cout << setw(4)<<"3"<< setw(4)<<"4"<< setw(4)<<"5"<<endl;
    for (int k=0;k<5;k++){
        if (k==0){
            cout << left << setw(4) << "A";
        } else if (k==1){
            cout << left << setw(4) << "B";
        } else if (k==2){
            cout << left << setw(4) << "C";
        } else if (k==3){
            cout << left << setw(4) << "D";
        } else if (k==4){
            cout << left << setw(4) << "E";
        }
        for (int j=0;j<5;j++){
            cout << setw(4) << cineModa.getAsiento(i,k,j,h);
        }
        cout << endl;
    }}

void Vista::mosClien(){
    int a=cineModa.numClien();
    vector<string> namescl;
    for (int k=0;k<a;k++){
        namescl.push_back(string(cineModa.clienName(k)));
    }

    cout << left << setw(5)<<"Opc" << setw(8) << "Nombres"<<endl;
    for (int k=0;k<a;k++){
        cout << left << setw(5)<<to_string(k+1)<< setw(8)<<namescl[k]<<endl;
    }
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
