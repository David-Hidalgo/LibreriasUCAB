#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "lista_enlazada_doble_nodo_cabeza.h"

using namespace std;
 
void reportarLista(TNodoCabeza lista) {
    char tecla;
     int i = 0;
     TNodo nodo = lista->primeroLista;
     if (!esVacia(lista)){
         cout << "Cantidad de elementos = " << lista->cantidadElementos <<endl;
         while(nodo != NULL) {
              cout <<' '<< i+1 <<") " << nodo->clave << "=" << nodo->nombre << endl;
              nodo = nodo->proximo;
              i++;
         }
      }   
       else{
            cout <<"LA LISTA ESTA VACIA " << endl;
       }
    cout<< "\n PRESIONE CUALQUIER LETRA "; cin >> tecla;
}

void borrarPantalla(){
  cout << "\x1B[2J"; // Clear the screen
cout << "\x1B[0;0H"; // place cursor at home position  
}

void pedirclaves(int &clave, string &nombre){
   cout<< "\n NUMERO A INSERTAR: "; cin >> clave;
   cout<< "\n NOMBRE A INSERTAR: "; cin >> nombre;
}

void menu1(){
    cout<<"\n\t\tLISTA ENLAZADA SIMPLE\n\n";
    cout<<" 1. INSERTAR AL INICIO               "<<endl;
    cout<<" 2. INSERTAR AL FINAL                "<<endl;
    cout<<" 3. INSERTAR EN UNA POSICION         "<<endl;
    cout<<" 4. BUSCAR ELEMENTO POR CLAVE        "<<endl;
    cout<<" 5. BUSCAR ELEMENTO POR NOMBRE       "<<endl;    
    cout<<" 6. ELIMINAR ELEMENTO POR CLAVE      "<<endl;
    cout<<" 7. ELIMINAR ELEMENTOS POR NOMBRE    "<<endl;
    cout<<" 8. REPORTAR LISTA                   "<<endl;
    cout<<" 9. SALIR                            "<<endl;
    cout<<"\n INGRESE OPCION: ";
}
 
/*                        Funcion Principal
---------------------------------------------------------------------*/
int main() {

    TNodoCabeza lista = crearLista(); //cambia esta lista por TNodoCabeza lista =NULL;
    char tecla;
    int op;         // opcion del menu
    int clave;      // elemenento a ingresar
    string nombre;  //nombre del elemento a ingresar
    int pos;        // posicion a insertar
    TNodo nodo = NULL;
    //system("color 1");
    system("tput clear"); 
    do{
        menu1();  cin>> op;
        switch(op) {
            case 1:
                cout << "\n\n**********INSERTANDO ELEMENTO PRIMERA POSICION************\n\n";
                 pedirclaves(clave, nombre);   
                 insertarPrimeraPosicion(lista, clave, nombre);
                 cout << "ELEMENTO: Clave = "<<clave<< " NOMBRE = " << nombre << " CREADO EXITOSAMENTE" <<endl;
                 cout<< "\n PRESIONE CUALQUIER LETRA "; cin >> tecla;    
                 system("tput clear"); 
                 break;

            case 2:
                cout << "\n\n**********ELIMINANDO ELEMENTO ULTIMA POSICION************\n\n";            
                 pedirclaves(clave, nombre);   
                 insertarUltimaPosicion(lista, clave, nombre );
                 cout << "ELEMENTO: Clave = "<<clave<< " NOMBRE = " << nombre << " ELIMINADO EXITOSAMENTE" <<endl;
                    cout<< "\n PRESIONE CUALQUIER LETRA "; cin >> tecla;
                 system("tput clear"); 
                 break;
  /*
            case 3:
                 cout<< "\n NUMERO A INSERTAR: ";cin>> clave;
                 cout<< " Posicion : ";       cin>> pos;
                 insertarElementoPosicion(lista, clave, pos, nombre);
                 break;
 */
            case 8:
                 cout << "\n\n**********MOSTRANDO LISTA************\n\n";
                 reportarLista(lista);
                 borrarPantalla();
                 break;
 /*
            case 5: 
                 cout<<"\n Clave a buscar: "; cin >> clave;
                 buscarElementoClave(lista, clave);
                 break;

            case 6:
                 cout<<"\n Nombre a buscar: "; cin >> nombre;
                 buscarElementoNombre(lista, nombre);
                 break;

            case 7:
                cout<<"\n Valor a eliminar: "; cin >> clave;
                eliminarElemento(lista, clave);
                break;
 
            case 8:
                cout<<"\n Valor repetido a eliminar: "; cin >> clave;
                eliminaRepetidos(lista, clave);
                break;
*/
            }
 
        cout<<endl<<endl;

    }while(op!=9);
 
   system("pause");
   return 0;
}