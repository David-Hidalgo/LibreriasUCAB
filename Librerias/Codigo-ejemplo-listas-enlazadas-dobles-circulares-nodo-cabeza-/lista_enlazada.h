using namespace std;

struct nodo{
       int clave;        // en este caso es un numero entero
        string nombre;
       struct nodo *prox;
};
 

typedef struct nodo *Tlista;
typedef struct nodo *TNodo;

nodo *ultimo;  //PARA QUE SERVIRIA ESTE APUNTADOR?
nodo *primero;

/* SE PUEDE CREAR UN NODO ESPECIAL LLAMADO NODO CABEZA */
struct nodo_cabeza{
       nodo *ultimo;  //PARA QUE SERVIRIA ESTE APUNTADOR?
       nodo *primero;
        int cantidad;
};

TNodo crearNodo(int c, string n){
    TNodo nodo = new(struct nodo);
    nodo->clave = c;
    nodo->nombre = c;
    nodo->prox = NULL; 
    return(nodo);
} 

void insertarInicio(Tlista &lista, TNodo &nodo) {
    nodo->prox = lista;
    lista  = nodo;
}

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
        while(t->prox!=NULL) 
            t = t->prox;
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
    Tlista q, t;
    int i;
    q = new(struct nodo);
    q->clave = valor;
    q->nombre = nombre;

    if(pos==1) {
        q->prox = lista;
        lista = q;
    }
    else {
        int x = insertarAntesDespues();
        t = lista;
        for(i=1; t!=NULL; i++) {
            if(i==pos+x) {
                q->prox = t->prox;
                t->prox = q;
                return;
            }
            t = t->prox;
        }
    }
    cout<<"   Error...Posicion no encontrada..!"<<endl;
}

void imprimirElemento(Tlista elemento){
    cout<<"\n\n ELEMENTO..!"<< endl;
    cout<<"\n CLAVE  = "<< elemento->clave << endl;
    cout<<"\n NOMBRE = "<< elemento->nombre << endl;
}

bool existeElementoClave(Tlista lista, int clave){
    Tlista q;
    bool log = false;
    q = lista;
    while(q->prox != NULL) {
        if(q->clave==clave) {
            log = true;
            break;
        }
        q = q->prox;
    }
return(log);
}

bool existeElementoNombre(Tlista lista, string nombre){
    Tlista q;
    bool log = false;
    q = lista;
    while(q->prox != NULL) {
        if(q->nombre == nombre) {
            log = true;
            break;
        }
        q = q->prox;
    }
return(log);
}



Tlista buscarElementoClave(Tlista lista, int valor) {
    Tlista q = lista;
    while(q!=NULL) {
        if(q->clave==valor) {
            break;
        }
        q = q->prox;
    }
return(q);
}

void buscarElementoNombre(Tlista lista, string nombre)
{
    Tlista q = lista;
    int i = 1, band = 0;

    while (q != NULL)
    {
        if (q->nombre == nombre)
        {
            cout << endl
                << " Encontrada en posicion " << i << endl;
            band = 1;
        }
        q = q->prox;
        i++;
    }
    if (band == 0)
        cout << "\n\n Numero no encontrado..!" << endl;
}

Tlista buscarElementoNombre2(Tlista lista, string nombre) {
    Tlista q = lista;
    while(q!=NULL) {
        if(q->nombre==nombre) 
            break;
        q = q->prox;
    }
    return q;
}

void eliminarElemento(Tlista &lista, int valor)
{
    Tlista p, ant;
    p = lista;

    if(lista!=NULL) {
        while(p!=NULL) {
            if(p->clave==valor) {
                if(p==lista)
                    lista = lista->prox;
                else
                    ant->prox = p->prox;

                delete(p);
                return;
            }
            ant = p;
            p = p->prox;
        }
    }
    else
        cout<<" Lista vacia..!";
}

void eliminaRepetidos(Tlista &lista, int valor)
{
    Tlista q, ant;
    q = lista;
    ant = lista;

    while(q!=NULL) {
        if(q->clave==valor) {
            if(q==lista) // primero elemento
            {
                lista = lista->prox;
                delete(q);
                q = lista;
            }
            else {
                ant->prox = q->prox;
                delete(q);
                q = ant->prox;
            }
        }
        else {
            ant = q;
            q = q->prox;
        }

    }// fin del while

    cout<<"\n\n Valores eliminados..!"<<endl;
}