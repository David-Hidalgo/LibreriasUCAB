#include <stdio.h>
#include <stdlib.h>
/* Estructura principal = lista */
struct lista{
	int valor;
	lista *prx;};
/* Rutinas base */
void burbuja(lista **p);
// metodo de ordenamiento

void insercion(lista **p);
// metodo de ordenamiento

void borrartodo(lista **p);
// borra por completo una lista

void voltear(lista **p);
// voltea la lista (con lista auxiliar)

void voltear2(lista **p);
// voltea la lista 2da forma (sin auxiliares)

void pospar (lista **p);
// elimina los elementos en posicion par

void separadig (lista *p);
// separa cada numero mayor a 9 en digitos separados

int cuenta (lista *p);
// cuenta los elementos

void elimina (lista **p, int x);
// elimina la primera ocurrencia de un elemento

void primos(lista **p);

void elimrep (lista *p);
// elimina los elementos repetidos

int busca (lista *p, int x);
// busca un elemento X en la lista

int cuentarep (lista *p, int x);
// cuenta cuantas veces se encuentra un elemento

void elimult (lista **p, int x);
// elimina la ultima ocurrencia de un elemento

void swap (int *x, int *y);
// procedimiento importante segun el problema a resolver

void insertarCabeza(lista **p, int x);
// inserta x por cabeza de la lista

void insertarfinal(lista **p, int x);
// insertar x por cola de la lista

void insertarPreciso(lista **p, int x, int a);
// insertar x por cola de la lista

void muestra(lista *p);
// muestra la lista por pantalla


/*
void muestra(lista *p);
// muestra la lista por pantalla

void insertarCabeza(lista **p, int x);
// inserta x por cabeza de la lista

void insertarfinal(lista **p, int x);
// insertar x por cola de la lista

void swap (int *x, int *y);
// procedimiento importante segun el problema a resolver

int busca (lista *p, int x);
// busca un elemento X en la lista
*/
int main ( ){
	lista * p=NULL;
	lista * s=NULL;
	int a = 0,x = 0, op=-1, m=0;
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	insertarCabeza (&p, ++m);
	
	


	while (op!=0){
		printf (" \n\n\t\tMENU DE LISTAS \n\n");
		printf ("\t1. AGREGA dato por cabeza lista\n");
		printf ("\t2. MUESTRA lista \n");
		printf ("\t3. AGREGA dato por cola lista\n");
		printf ("\t4. BUSCA elemento\n");
		printf ("\t5. CUENTA sus elementos\n");
		printf ("\t6. ORDENA por BURBUJA\n");
		printf ("\t7. ORDENA por INSERCION\n");
		printf ("\t8. ELIMINA dato en lista\n");
		printf ("\t9. ELIMINA elementos repetidos\n");
		printf ("\t10. VOLTEAR lista\n");
		printf ("\t11. SEPARE CADA NUMERO MAYOR A 9 EN DIGITOS SEPARADOS\n");
		printf ("\t12. ELIMINA elementos en posicion PAR \n");
		printf ("\t13. CUENTA cuantas veces se repite el elemento\n");
		printf ("\t14. ELIMINA ultima ocurrencia de un numero\n");
		printf ("\t15. AGREGAR dato exacto\n");
		printf ("\t0. Salir\n\n");
		printf ("\tIndique su opcion (0-5)\t-> ");
		scanf ("%d", &op);
		system("cls");
		printf("\n Opcion %i ",op);
		switch (op){
			case 1: 
				printf("\n Agregar dato por cabeza de lista\n\n\n");
				printf("\t\tIndique numero a insertar por la Cabeza = ");
				scanf("%d",&x);
				insertarCabeza(&p,x);
				printf("\n\t EL ELEMENTO FUE AGREGADO EXITOSAMENTE\n\n");
				muestra(p);
				break;
			case 2: printf ("\n Mostrar lista \n\n\n");muestra(p);
				break;
     		case 3: printf ("\n AGREGA dato por cola lista\n");
				printf("\t\tIndique numero a insertar por la Cola = ");
				scanf("%d",&x);
				insertarfinal(&p,x);
				printf("\n\t EL ELEMENTO FUE AGREGADO EXITOSAMENTE\n\n");
				muestra(p);
				break;
			case 4: printf ("\n BUSCA elemento\n");
					printf("\n\tIndique numero a buscar en la lista = ");
					scanf("%d",&x);
					busca(p, x);
					if (busca(p, x) == 1){
						printf("\n\tEL ELEMENTO FUE ENCONTRADO\n");

					}else
						printf("\n\tEL ELEMENTO NO FUE ENCONTRADO\n");
				break;
			case 5: printf ("\n CUENTA sus elementos\n");
					printf ("\n\t LA LISTA TIENE %i ELEMENTOS\n", cuenta(p));	
				break;
			case 6: printf ("\n ORDENAR por BURBUJA \n");
					printf("\n\t ANTES: \n");
					muestra(p);
					burbuja(&p);
					printf("\n\n\t ORDENADO POR BURBUJA EXITOSAMENTE");
					printf("\n\n\t RESULTADO:");
					muestra(p);
				break;
			case 7: printf ("\n ORDENAR POR INSERCION \n");
					printf("\n\t ANTES: \n");
					muestra(p);
					insercion(&p);
					printf("\n\n\t ORDENADO POR INSERCION EXITOSAMENTE");
					printf("\n\n\t RESULTADO:");
					muestra(p);
				break;
			case 8: printf ("\n ELIMINA dato en lista\n");
					printf("\n\tIndique numero a eliminar en la lista = ");
					scanf("%d",&x);
					printf("\n\t ANTES: \n");
					muestra(p);
					elimina(&p, x);
					printf("\n\n\t RESULTADO:");
					muestra(p);
				break;
			case 9: printf ("\n ELIMINA elementos repetidos\n");
					printf("\n\t ANTES: \n");
					muestra(p);
					elimrep(p);
					printf("\n\n\t REPETIDOS ELIMINADOS EXITOSAMENTE");
					printf("\n\n\t RESULTADO:");
					muestra(p);
				break;
			case 10: printf ("\n VOLTEAR lista\n");
					printf("\n\t ANTES: \n");
					muestra(p);
					voltear2(&p);
					printf("\n\n\t\t LISTA VOLTEADA EXITOSAMENTE \n");
					printf("\n\n\t RESULTADO:");
					muestra(p);
				break; 
			case 11: printf ("\n SEPARE CADA NUMERO MAYOR A 9 EN DIGITOS SEPARADOS\n");
					printf("\n\t ANTES: \n");
					muestra(p);
					separadig(p);
					printf("\n\n\t\t LISTA VOLTEADA EXITOSAMENTE \n");
					printf("\n\n\t RESULTADO:");
					muestra(p);
				break;
			case 12: printf ("\n ELIMINA elementos en posicion PAR \n");
					printf("\n\t ANTES: \n");
					muestra(p);
					pospar(&p);
					printf("\n\n\t\t LISTA MODIFICADA EXITOSAMENTE \n");
					printf("\n\n\t RESULTADO:");
					muestra(p);
				break;
			case 13: printf ("\nCONTAR CUANTAS VECES SE ENCUENTRA UN ELEMENTO\n");
					printf("\n\t Indique numero a buscar en la lista = ");
					scanf("%d",&x);
					if (cuentarep(p, x)){
						printf ("\n\t EL ELEMENTO SI SE ENCUENTRA Y SE REPITE %i VEZ(CES)", cuentarep(p, x));
						}
					else{
						printf ("\n\t EL ELEMENTO NO SE ENCUENTRA");
					}
					break;
			case 14: printf("\n ELIMINA LA ULTIMA OCURRENCIA DE UN NUMERO");
					printf("\n\t Indique numero a buscar y eliminar en la lista = ");
					scanf("%d",&x);
					printf("\n\t ANTES: \n");
					muestra(p);
					elimult(&p, x);
					printf("\n\n\t\t ULTIMA OCURRENCIA DEL NUMERO %i FUE ELIMINADO EXITOSAMENTE \n", x);
					printf("\n\n\t RESULTADO:");
					muestra(p);
			case 15: printf ("\n AGREGA dato exacto \n");
				printf("\t\tIndique numero a insertar = ");
				scanf("%d",&x);
				muestra(p);
				printf("\t\tIndique numero a buscar de la lista = ");
				scanf("%d",&a);
				insertarPreciso(&p,x,a);
				printf("\n\t EL ELEMENTO FUE AGREGADO EXITOSAMENTE\n\n");
				muestra(p);
				break;  
			case 16: {
				printf ("\n ELIMINA elementos primos\n");
					printf("\n\t ANTES: \n");
				muestra(p);
				primos(&p);
				printf("\n\n\t PRIMOS ELIMINADOS EXITOSAMENTE");
					printf("\n\n\t RESULTADO:");
				muestra(p);
				break;
				}
		};
	printf("\n\n");
	if (op) system("pause");
	system("cls");
	};
	return 0;
}


void primos(lista **p){
  lista *aux= *p ,  *t;
	int EsPrimo = 1;
	while ((aux)&&(aux->prx != NULL)){
        t= aux->prx;
				EsPrimo = 1;
     for(int i = 2; i< t->valor;i++) {if(t->valor %i==0){EsPrimo = 0;}};       
		 if(EsPrimo){
          aux->prx= t->prx;
					delete t; }else{aux = aux->prx;}
	}
}



void burbuja(lista **p){
	lista *ax=*p, *t=*p;
	int s;
	
	while((ax)&&(ax->prx != NULL)){
		t= ax->prx;
		
		while (t!=NULL){
			if(ax->valor > t->valor){
				s=t->valor;
				t->valor=ax->valor;
				ax->valor=s;
			}
			t=t->prx;
		}
		ax=ax->prx;
		t=ax->prx;
		
	}
	
}

void insercion(lista **p){
	lista *ax=*p, *t=*p; 
	int temp;
	while (ax->prx!=NULL){
		t=ax->prx;		
		while (t!=NULL){							
			if(ax->valor > t->valor){ // "< de Mayor a menor" y "> de menor a mayor"
				temp = ax->valor;
				ax->valor=t->valor;
				t->valor=temp;
			}
			t=t->prx;
		}
	ax=ax->prx;	
	}
}

void insertarCabeza(lista **p, int x){
// inserta x por cabeza de la lista
	lista *t = new lista;
	t->valor = x;
	t->prx = *p;
	*p= t;
}	

void muestra(lista *p){
// muestra la lista por pantalla
	lista *t = p;
	printf("\n\n\n\t\t");
	while (t){
		printf("[%d]->",t->valor);
		t = t->prx;
		};
	printf("NULL\n\n");
	};

void borrartodo(lista **p){
	lista *ax=*p;
	while(*p){
		*p= (*p)->prx;
		delete ax;
		ax= *p;
	}
}

void voltear (lista **p){
	lista *t = NULL, *ax=*p, *temp;
	while(ax){
		insertarCabeza(&t, ax->valor);
		ax=ax->prx;
	}
	temp=*p;
	*p=t;
	borrartodo(&temp);
}

void voltear2 (lista **p){
	lista *t = *p, *ax;
	while((t)&&(t->prx)){
		ax=t->prx;
		t->prx=ax->prx;
		ax->prx=*p;
		*p=ax;
	}
}

void pospar (lista **p){
	lista *t=*p, *ax;
	while ((t)&&(t->prx)){
		ax = t->prx;
		t = t->prx->prx;
		delete ax;
	}
	t = t->prx;
}

void separadig (lista *p){
	lista *t = p, *ax;
	while (t){
		while (t->valor > 9){
			ax = new lista;
			ax->valor = t->valor%10;
			t->valor = t->valor/10;
			ax->prx = t->prx;
			t->prx = ax;
		}
		t = t->prx;
	}
}

void elimrep (lista *p){
	lista *t = p, *ax, *temp;
	while ((t)&&(t->prx)){
		ax = t;
		while (ax->prx){
			if (t->valor == ax->prx->valor){
				temp = ax->prx;
				ax->prx = temp->prx;
				delete temp;
			}
			else
				ax = ax->prx;
		}
		t = t->prx;
	}
}

int cuenta (lista *p){
	int cont=0;
	lista *t = p;
	while(t){
		t=t->prx;
		cont++;
	}
	return cont;
}

int busca (lista *p, int x){
	lista *t = p;
	while ((t)&&(t->valor == x)){
		t = t->prx;
	}
	return (t!=NULL);
}



//REVISAR ESTE PROCEDIMIENTO DEBIDO A QUE "EXPLOTA" AL TRATAR 
//DE ELIMINAR ELEMENTOS QUE TIENEN OTRAS OCURRENCIAS
void elimina (lista **p, int x){
	lista *t = *p, *ax;
	int c=0;
	if (t){
		if (t->valor == x){
			*p = (*p)->prx;
			delete t;
			c++;
		}
		else
			while ((t->prx)&&(t->prx->valor != x))
				t = t->prx;
				if (t->prx){
					ax = t->prx;
					t->prx = t->prx->prx;
					delete ax;
					c++;
		}
	}
	
	if  (c == 0){
		printf ("\n\t EL ELEMENTO NO SE ENCUENTRA EN LA LISTA\n\n");
	}else
		printf ("\n\t EL ELEMENTO FUE ELIMINADO CORRECTAMENTE\n\n");
}

int cuentarep (lista *p, int x){
	lista *t = p;
	int cont = 0;
	while (t){
		if(t->valor == x){
			cont++;
		}
		t = t->prx;
	}
	return cont;
}

void elimult (lista **p, int x){
	lista *ax = *p, *ul = ax, *t;
	if (ax){
		if (ax->valor == x){
			ul = ax; t = NULL;
		}
		while (ax->prx){
			if (ax->prx->valor == x){
				ul = ax->prx; t = ax;
			}
			ax = ax->prx;
		}
		if ((!t)&&(ax->valor == x)){
			*p=(*p)->prx; delete ax;
		}else{
			if ((ul)&&(ul->valor == x)){
				t->prx = ul->prx;
				delete ul;
			}
		}
	}
}

void insertarfinal(lista **p, int x){
	lista *t = *p;
	while ((t)&&(t->prx))t=t->prx;
	lista *aux = new lista;
	aux->valor = x;

	aux->prx = t->prx;
	t->prx = aux;
}

void insertarPreciso(lista **p, int x, int a){
	lista *t = *p;
	while ((t)&&(t->valor != a))t=t->prx;
	lista *aux = new lista;
	aux->valor = x;
	aux->prx = t->prx;
	t->prx = aux;
}



void swap (int *x, int *y){
	int c = *x;
	*x = *y;
	*y = c;
}
