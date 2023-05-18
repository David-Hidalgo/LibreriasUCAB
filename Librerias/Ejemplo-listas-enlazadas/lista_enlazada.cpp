#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "lista_enlazada.h"

using namespace std;

void reportarLista(Tlista lista) {
     char tecla;
     int i = 0; 
     while(lista != NULL) {
          cout <<' '<< i+1 <<") " << lista->clave << "=" << lista->nombre << endl;
          lista = lista->prox;
          i++;
     }   
     cout<< "\n PRESIONE CUALQUIER LETRA "; cin >> tecla;
}

void imprimirNodo(Tlista nodo){
     cout  << nodo->clave << "=" << nodo->nombre << endl;
}

void borrarPantalla(){
system("clear");
//cout << "\x1B[2J"; // Clear the screen
//cout << "\x1B[0;0H"; // place cursor at home position  
}

void pedir_datos(int &clave, string &nombre){
     cout<< "\n NUMERO A INSERTAR: "; cin >> clave;
     cout<< "\n NOMBRE A INSERTAR: "; cin >> nombre;
}

void menu1(){
     cout<<"\n\t\tLISTA ENLAZADA SIMPLE\n\n";
     cout<<" 0. Crear nodo pasando clave y nombre" <<endl;
     cout<<" 1. INSERTAR AL INICIO               "<<endl;
     cout<<" 2. INSERTAR AL FINAL                "<<endl;
     cout<<" 3. INSERTAR EN UNA POSICION         "<<endl;
     cout<<" 4. REPORTAR LISTA                   "<<endl;
     cout<<" 5. BUSCAR ELEMENTO POR CLAVE        "<<endl;
     cout<<" 6. BUSCAR ELEMENTO POR NOMBRE       "<<endl;    
     cout<<" 7. ELIMINAR ELEMENTO 'V'            "<<endl;
     cout<<" 8. ELIMINAR ELEMENTOS CON VALOR 'V' "<<endl;
     cout<<" 9. SALIR                            "<<endl;
     cout<<"\n INGRESE OPCION: ";
}

/*                        Funcion Principal
---------------------------------------------------------------------*/
int main() {
     Tlista lista = NULL;
    int op;         // opcion del menu
    int _dato;      // elemenento a ingresar
    string nombre;  //nombre del elemento a ingresar
    int pos;        // posicion a insertar
     TNodo nodo = NULL;
     do{
          menu1();  
          cin >> op;
          switch(op) {
               case 0:
                    cout << "CREAR NODO" << endl;
                    pedir_datos(_dato, nombre);   
                    nodo = crearNodo(_dato, nombre); 
                    break;

               case 1:
                    pedir_datos(_dato, nombre);   
                    insertarInicio(*lista, _dato, nombre);
                    system("tput clear"); 
                    break;

               case 2:
                    pedir_datos(_dato, nombre);   
                    insertarFinal(lista, _dato, nombre );
                    system("tput clear"); 
                    break;

               case 3:
                    cout<< "\n NUMERO A INSERTAR: ";cin>> _dato;
                    cout<< " Posicion : ";       cin>> pos;
                    insertarElementoPosicion(lista, _dato, pos, nombre);
                    break;

               case 4:
                    cout << "\n\n MOSTRANDO LISTA\n\n";
                    reportarLista(lista);
                    borrarPantalla();
                    break;

               case 5: 
                    cout<<"\n Clave a buscar: "; cin >> _dato;
                    buscarElementoClave(lista, _dato);
                    break;

               case 6:
                    cout<<"\n Nombre a buscar: "; cin >> nombre;
                    if (!esVacia(lista)) {
                         Tlista elemento = buscarElementoNombre2(lista, nombre);
                         if (elemento != NULL) 
                              imprimirNodo(elemento);
                         else
                         cout << "No existe elemento en la lista con el nombre: " << nombre << endl;   
                    }    
                    else
                         cout << "La lista esta vacia" << endl;                 
                    break;

               case 7:
                    cout<<"\n Valor a eliminar: "; cin >> _dato;
                    eliminarElemento(lista, _dato);
                    break;

               case 8:
                    cout<<"\n Valor repetido a eliminar: "; cin >> _dato;
                    eliminaRepetidos(lista, _dato);
                    break;
               }

          cout<<endl<<endl;

     }while(op!=9);

     system("pause");
     return 0;
}