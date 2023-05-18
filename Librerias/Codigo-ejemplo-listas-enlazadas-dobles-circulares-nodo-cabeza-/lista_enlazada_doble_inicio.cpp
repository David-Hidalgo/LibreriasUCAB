#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "lista_enlazada_doble_nodo_cabeza_inicio.h"

using namespace std;

void reportarLista(TNodoCabeza lista) {
    int i = 1;
    TNodo nodo = lista->primeroLista;
    if (!esVacia(lista)){
        cout << "Cantidad de elementos = " << lista->cantidadElementos <<endl;
        while(nodo != NULL) {
            cout <<' '<< i <<") " << nodo->clave << "=" << nodo->nombre << endl;
            nodo = nodo->proximo;
            i++;
        }
    }   
    else
        cout <<"LA LISTA ESTA VACIA " << endl;
}

void borrarPantalla(){
  cout << "\x1B[2J"; // Clear the screen
  cout << "\x1B[0;0H"; // place cursor at home position  
}

void borrarPantalla2(){
    system( "read -n 1 -s -p \"\nPresiona cualquier tecla para continuar...\"" );
}

void pedirDatos(int &clave, string &nombre, string mensaje){
    cout << mensaje << ":" <<endl;  
    bool log = false;
    while (!log) {
    cout<< "\n NUMERO: "; cin >> clave;
    if(!cin) { // o también if(cin.fail()) 
        cout << "ERROR! NUMERO INCORRECTO INTENTE DE NUEVO" << endl;
        // El usuario no introdujo un número valido
        cin.clear(); // Borrar la entrada fallida
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Saltar la entrada no válida
    }
    else 
        log= true;
}
    cout<< "\n NOMBRE: "; cin >> nombre;
}


void menu1(){
    cout<<"\n\t\tLISTA ENLAZADA DOBLE\n\n";
    cout<<" 1. INSERTAR AL INICIO               "<<endl;
    cout<<" 2. INSERTAR AL FINAL                "<<endl;
    cout<<" 3. INSERTAR EN UNA POSICION         "<<endl;
    cout<<" 4. BUSCAR ELEMENTO POR CLAVE        "<<endl;
    cout<<" 5. BUSCAR ELEMENTO POR NOMBRE       "<<endl;    
    cout<<" 6. ELIMINAR ELEMENTO POR CLAVE      "<<endl;
    cout<<" 7. ELIMINAR ELEMENTO POR NOMBRE     "<<endl;
    cout<<" 8. REPORTAR LISTA                   "<<endl;
    cout<<" 9. SALIR                            "<<endl;
    cout<<"\n INGRESE OPCION: ";
}
 
/*                        Funcion Principal
---------------------------------------------------------------------*/
int main() {
    TNodoCabeza lista = crearLista();
    int op;         // opcion del menu
    int clave;      // elemenento a ingresar
    string nombre;  //nombre del elemento a ingresar
    TNodo nodo = NULL;
    do{
        system("tput clear"); 
        menu1();  cin>> op;
        switch(op) {
            case 1:
                cout << "\n\n**********INSERTANDO ELEMENTO PRIMERA POSICION************\n\n";
                 pedirDatos(clave, nombre, "DATOS A INSERTAR");   
                 insertarPrimeraPosicion(lista, clave, nombre);
                 cout << "ELEMENTO: Clave = "<<clave<< " NOMBRE = " << nombre << " CREADO EXITOSAMENTE" <<endl;
                 break;

            case 2:
                cout << "\n\n**********INSERTAR ELEMENTO ULTIMA POSICION************\n\n";            
                 pedirDatos(clave, nombre, "DATOS A INSERTAR");   
                 insertarUltimaPosicion(lista, clave, nombre );
                 cout << "ELEMENTO: Clave = "<<clave<< " NOMBRE = " << nombre << " CREADO EXITOSAMENTE" <<endl;
                 break;
  
            case 8:
                 cout << "\n\n**********MOSTRANDO LISTA************\n\n";
                 reportarLista(lista);
                 break;

            case 9:
                cout << "\n\n**********FIN DEL PROGRAMA************\n\n" << endl;
                break; 
            }

        if (op<9) borrarPantalla2();
        cout<<endl<<endl;
    }while(op!=9);

   return 0;
}