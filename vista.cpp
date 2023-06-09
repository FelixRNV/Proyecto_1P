﻿#include "vista.h"

Vista::Vista(){
}

void Vista::menuIni(){
    string usua;
    string pas;
    bool men;
    cout << "\nIngrese Usuario: ";
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
    char op;
    int opc;
    string val;
    string na,la,pa,us;
    do{
        cout << "          --- CineModá ---" << endl;
        cout << "\nPrograma del Cine\n";

        cout << "1. Cambiar Funciones\n";
        cout << "2. Nuevo Vendedor\n";
        cout << "3. (Ver/Eliminar) Vendedor(es)\n";
        cout << "4. (Ver/Eliminar) Clientes\n";
        cout << "5. Cambiar Contraseña\n";
        cout << "6. Cambiar Usuario\n";
        cout << "0. Cerrar Sesión\n";
        cout << "\nIngresar opción: \t";
        cin >> op;
        opc=cineModa.validarOp(op);
        switch(opc){
        case 1:
            int i;
            mosSimPelis();
            cout << "Ingrese opción de pelicula a cambiar: \t";
            cin >> i;
            cambiarFunciones(i);
                break;
        case 2:
            if (cineModa.maxVende()==false){
                cout << "Proceda a Ingresar los datos del  Vendedor\n";
                cout << "Ingrese Nombre: ";
                cin >> na;
                cout << "Ingrese Apellido: ";
                cin >> la;
                cout << "Ingrese Usuario: ";
                cin >> us;
                cout << "Ingrese Contraseña: ";
                cin >> pa;
                cineModa.setVende(na,la,us,pa);
                cout << endl << "Nuevo Vendedor Creado\n";

            }else{
            cout << "\nSólo se permiten 3 vendedores\n";
            }
                break;
        case 3:
            mosEmpl();
            cout << "Deseas Eliminar a algún Vendedor [S/n]: ";
            cin >> op;
            if (int(op)==78||int(op)==110){
                break;
            }else{
                cout << "Ingrese el ID del Vendedor: ";
                cin >> op;
                opc=cineModa.validarOp(op);
                cineModa.emptyVende(opc);
                break;
            }
            break;
        case 4:
            mosClien();
            cout << "Deseas Eliminar a algún Cliente [S/n]: ";
            cin >> op;
            if (int(op)==78||int(op)==110){
                break;
            }else{
                cout << "Ingrese la OPC de Cliente: ";
                cin >> op;
                opc=cineModa.validarOp(op);
                cineModa.emptyClien(opc);
                break;
            }
            break;
        case 5:
            cout << "\n --- Cambio de Contraseña --- \n";
            cout << "Ingrese su Usuario: ";
            cin >> val;
            if(val!=cineModa.nameEmpl()){
                cout << "\n-- Usuario Invalido --\n";
                cout << "No se puede seguir con el proceso\n";
                break;
            }else {
            cout << "Ingrese su nueva Contraseña: ";
            cin >> val;
            cineModa.setContraseña(val);
            }
            cout << "\nSe Actualizó con Exito\n";
                break;
        case 6:
            cout << "\n --- Cambio de Usuario --- \n";
            cout << "Ingrese su Contraseña: ";
            cin >> val;
            if(val!=cineModa.passEmpl()){
                cout << "\n-- Contraseña Invalida --\n";
                cout << "No se puede seguir con el proceso\n";
                break;
            }else {
            cout << "Ingrese su nuevo Usuario: ";
            cin >> val;
            cineModa.setUsuario(val);
            }
            cout << "\nSe Actualizó con Existo\n";
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
    char op;
    string val;
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
        cin >> op;
        opc=cineModa.validarOp(op);
        switch(opc){
        case 1:
            mosPelis();
                break;
        case 2:
            menuCompra();
                break;
        case 3:
            cout << "\n --- Cambio de Contraseña --- \n";
            cout << "Ingrese su Usuario: ";
            cin >> val;
            if(val!=cineModa.nameEmpl()){
                cout << "\n-- Usuario Invalido --\n";
                cout << "No se puede seguir con el proceso\n";
                break;
            }else {
            cout << "Ingrese su nueva Contraseña: ";
            cin >> val;
            cineModa.setContraseña(val);
            }
            cout << "\nSe Actualizó con Exito\n";
                break;
        case 4:
            cout << "--- Cambio de Usuario ---\n";
            cout << "Ingrese su Contraseña: ";
            cin >> val;
            if(val!=cineModa.passEmpl()){
                cout << "\n-- Contraseña Invalida --\n";
                cout << "No se puede seguir con el proceso\n";
                break;
            }else {
            cout << "Ingrese su nuevo Usuario: ";
            cin >> val;
            cineModa.setUsuario(val);
            }
            cout << "\nSe Actualizó con Exito\n";
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
        sals[a]=cineModa.idSala(a,0);
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
        sals[a]=cineModa.idSala(a,0);
    }

    cout << "\n---- Cartelera ----\n";
    cout << left << setw(11) << "Opción "<< setw(2) << "|";
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
    char ho;
    vector<string> asie;
    vector<char> sep;
    Cliente cli;
    mosPelis();
    do{
    cout << "Ingrese el ID de la pelicula: ";
    cin >> bus;
    peli=cineModa.encontrarPeli(bus);
    }while(peli==5);
    cout << "Ingrese el número de boletos: ";
    cin >> numbo;
    mosHorarios(peli);
    do{
    cout << "\nIngrese la opción del horario: ";
    cin >> ho;
    hori=cineModa.validarOp(ho);
    }while(isdigit(ho)==0);
    mosSala(peli,hori);
    for (int z=0;z<numbo;z++){
        do{do{
        cout << "Escoja el asiento "<< z+1 <<": ";
        cin>>as;
            }while(cineModa.validarPos(as,peli,hori)!=true);
        }while(cineModa.validarAs(as)!=true);

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
        cout << "\n---- Impresión del Boleto ---\n";
        imprBoleto(peli,asie,hori);
    }else{
        for (int z=0;z<int(asie.size());z++){
            sep=cineModa.getAsSep(asie[z]);
            cineModa.emptyAs(peli,hori,sep);
        }
    cout << "\nHa salido del Apartado de Compra\n";
    }
}

void Vista::imprBoleto(int peli, vector<string> asie,int h){
    cout << "----- Boleto ------\n";
    cout << left << setw(2) << "╔";
    for (int p=0;p<78;p++){
        cout<<setw(2)<<"═";
    }
    cout<<setw(2)<<"╗"<<endl<<setw(2)<<"║";
    cout<<"Sala: "<<to_string(cineModa.idSala(peli,h));
    for (int p=0;p<71;p++){
        cout<<setw(1)<<" ";
    }
    cout<<setw(2)<<"║"<<endl<<setw(2)<<"║"<<"Hora: "<<cineModa.horaPeli(peli,h);
    for (int p=0;p<67;p++){
        cout<<setw(1)<<" ";
    }
    cout<<setw(2)<<"║"<<endl<<setw(2)<<"║"<<"Asiento(s): ";
    for (int z=0;z<int(asie.size());z++){
        cout << asie[z];
        if (int(asie.size())>1 && z<(int(asie.size())-1)){
        cout<< " , ";
        }
    }
    if(int(asie.size())==1){
    for (int p=0;p<64;p++){
        cout<<setw(1)<<" ";
    }}else{
        for (int p=0;p<(71-(2+int(asie.size())*5));p++){
            cout<<setw(1)<<" ";
    }}
    cout<<setw(2)<<"║"<<endl<<setw(2)<<"║"<<"Pelicula: "<<cineModa.namePelis(peli);
    for (int p=0;p<(68-int(cineModa.namePelis(peli).size()));p++){
        cout<<setw(1)<<" ";
    }
    cout <<setw(2)<<"║"<<endl<< left << setw(2) << "╚";
    for (int p=0;p<78;p++){
        cout<<setw(2)<<"═";
    }
    cout<<setw(2)<<"╝"<<endl;
}

void Vista::imprFactura(int cli, int peli, vector<string> asie){
        cout << "\n ----- ------ Cine Moda ------ -----\n";
        cout << "Factura Número: " << cineModa.lastFactCli(cli)<<endl;
        cout << "Cliente: " << cineModa.clienName(cli) << endl;
        cout << "C.I.: " << cineModa.clienCI(cli) << endl;
        cout << "E-mail: " << cineModa.clienMail(cli) << endl;
        cout << "Fecha: "<< cineModa.getfecha()<<endl;
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
    int opc, pos;
    string name, l_name, email,te;
    char op;
    int ci;
    bool ter;
    Cliente cli;
    cout << "\nSeleccione la opción de cliente: \n";
    cout << "\n1. Consumidor Final";
    cout << "\n2. Buscar Cliente";
    cout << "\n3. Cliente Nuevo";
    cout << "\n4. Ver Clientes";
    do{
    cout << "\nSelccionar opción: ";
    cin >> op;
    }while (isdigit(op)==0);
    opc=cineModa.validarOp(op);
    switch(opc){
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
}

void Vista::mosEmpl()
{
    string names[3];
    string l_names[3];
    string users[3];
    string pass[3];

    for(int i=0;i<3;i++){
        names[i]=cineModa.nameVende(i);
        l_names[i]=cineModa.lnameVende(i);
        users[i]=cineModa.userVende(i);
        pass[i]=cineModa.passVende(i);
    }

    cout << "\n          --- Lista de Empleados ---\n";
    cout << left << setw(4)<<"ID"<<setw(2)<<"|"<<setw(10)<< "Apellido";
    cout  <<setw(2)<<"|"<< setw(10)<<"Nombre"<<setw(2)<<"|"<<setw(10)<< "Usuario";
    cout  <<setw(2)<<"|"<< setw(10)<<"Contraseña"<<endl;
    for(int i=0;i<3;i++){
        cout << left << setw(4)<<i+1<<setw(2)<<"|"<<setw(10)<< l_names[i];
        cout <<setw(2)<<"|"<< setw(10)<<names[i]<<setw(2)<<"|"<<setw(10)<< users[i];
        cout <<setw(2)<<"|"<< setw(8)<<pass[i]<<endl;
       }
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
    cout << "Sala de Proyección: ";
    cin >> sala;
    cout << "Ingrese el horario de proyección 1:\n";
    cout << "Hora: ";
    cin >> h;
    cout << "Minutos: ";
    cin >> m;
    cineModa.setMovie(tit,ids,dra,sala,h,m,i);
    cout << "Ingrese el horario de proyección 2:\n";
    cout << "Hora [13-23]: ";
    cin >> h;
    cout << "Minutos [00-59]: ";
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
    cout << "--- Sala "<<cineModa.idSala(i,h)<<" ---\n";
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
