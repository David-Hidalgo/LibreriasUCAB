#include <iostream>

using namespace std;
struct nodo{
       int clave;        // en este caso es un numero entero
        string nombre;
       struct nodo *prox;
};

typedef struct nodo *Tlista;
nodo *ultimo;
nodo *primero;

bool esVacia(Tlista &lista) {
    bool log = false;
    if (lista==NULL) log= true;
    return log;
} 

void insertarInicio(Tlista &lista, int valor, string nombre)
{
    Tlista q;
    q = new(struct nodo);
    q->clave = valor;
    q->nombre = nombre;
    q->prox = lista;
    lista  = q;
}

void insertarFinal(Tlista &lista, int valor, string nombre) {
    Tlista t, q = new(struct nodo);

    q->clave  = valor;
    q->nombre = nombre;

    q->prox = NULL;

    if(lista==NULL) lista = q;

    else {
        t = lista;
        while(t->prox!=NULL) t = t->prox;
        t->prox = q;
    }
}

int insertarAntesDespues() {
    int _op, band;
    cout<<endl;
    cout<<"\t 1. Antes de la posicion           "<<endl;
    cout<<"\t 2. Despues de la posicion         "<<endl;
    cout<<"\n\t Opcion : "; cin>> _op;

    if(_op==1)
        band = -1;
    else
        band = 0;
    return band;
}

void insertarElementoPosicion(Tlista &lista, int valor, int pos, string nombre) {

}

void imprimirElemento(Tlista elemento){
    cout<<"\n\n ELEMENTO..!"<< endl;
    cout<<"\n CLAVE  = "<< elemento->clave << endl;
    cout<<"\n NOMBRE = "<< elemento->nombre << endl;
}

bool existeElementoClave(Tlista lista, int clave){
    Tlista q;
    bool log = false;

return(log);
}

bool existeElementoNombre(Tlista lista, string nombre){
    Tlista q;
    bool log = false;

return(log);
}

Tlista buscarElementoClave(Tlista lista, int valor) {
    Tlista q = lista;

return(q);
}

void buscarElementoNombre(Tlista lista, string nombre) {

}

void eliminarElemento(Tlista &lista, int valor)
{

}

void eliminaRepetidos(Tlista &lista, int valor)
{

}