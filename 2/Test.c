#include <iostream>
#include <cstring>

using namespace std;

int Menu(int &opcion){
    cout<<"1) Compilar\n";
    cout<<"2) Ejecutar\n\n";
    cout<<" Opcion: ";
    cin>>opcion;
    return opcion;
}

int main(){
    string archivo = "";
    string compilador = "g++ -Wall ";
    string ejecutable = ".cpp -o ";
    string ejecutable1 = "";
    string final = "";
    char compilacion[100];
    char exe[50];
    int opcion;
    
    do{
        Menu(opcion);
        switch(opcion){
            case 1:
                cout<<"Nombre del Archivo: ";
                getline(cin,archivo);
                getline(cin,archivo);
                cout<<"Nombre del ejecutable: ";
                getline(cin,ejecutable1);
                
                final  = (compilador + archivo + ejecutable + ejecutable1);
                
                for(int i = 0; i < 100;i++)
                    compilacion[i] = final[i];
                system(compilacion);
                break;
            case 2:
                for(int i = 0; i < 100;i++)
                    exe[i] = ejecutable1[i];
                system(exe);
                break;
            default:
                    cerr<<"error";
                break;
        }
        system("cls");
    }while(true);
    return 0;
}