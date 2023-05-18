using namespace std;

struct nodo{
       int clave;        // en este caso es un numero entero
        string nombre;
       struct nodo *proximo;
       struct nodo *anterior;
};

struct nodoCabeza{
    struct nodo *primeroLista;
    struct nodo *ultimoLista;
    int cantidadElementos;
};

typedef struct nodo *TNodo;
typedef struct nodoCabeza *TNodoCabeza;


TNodo crearNodo(int c, string n){
    TNodo nodo = new(struct nodo);
    nodo->clave = c;
    nodo->nombre = n;
    nodo->proximo = NULL; 
    nodo->anterior = NULL;
    return(nodo);
} 

TNodoCabeza crearLista(){
    TNodoCabeza nodoCabeza = new (struct nodoCabeza);
    nodoCabeza->primeroLista = NULL;
    nodoCabeza->ultimoLista = NULL;
    nodoCabeza->cantidadElementos = 0;
    return nodoCabeza;
}

void insertarPrimeraPosicion(TNodoCabeza &lista, int clave, string nombre) {
    TNodo nodo = crearNodo(clave, nombre);
    lista->cantidadElementos++;
    if (lista->primeroLista ==NULL) {
        lista->primeroLista = nodo;
        lista->ultimoLista = nodo;        
    }
    else {
        nodo->proximo = lista->primeroLista;
        lista->primeroLista = nodo;
        lista->primeroLista->proximo->anterior = nodo;   
    }
}

void insertarUltimaPosicion(TNodoCabeza &lista, int clave, string nombre) {
    TNodo nodo = crearNodo(clave, nombre);
    lista->cantidadElementos++;
    if (lista->primeroLista ==NULL) 
        lista->primeroLista = nodo;
    else {
        nodo->anterior = lista->ultimoLista;
        lista->ultimoLista->proximo= nodo;
    }
    lista->ultimoLista = nodo;
}

bool esVacia(TNodoCabeza &lista) {
    bool log = false;
    if (lista->primeroLista==NULL) log= true;
    return log;
} 
