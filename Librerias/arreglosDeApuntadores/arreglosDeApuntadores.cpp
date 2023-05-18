#include <iostream>
#include <string>
#include <sstream>  //para las funciones iss, noskipws, 
#include <cctype>
#include <iomanip>

using namespace std;

typedef struct {
  int codigo;
  string nombre;
  float sueldo;
} tRegistro;
typedef tRegistro *tRegPtr;

const int N = 1000;

// Array de punteros a registros:
typedef tRegPtr tArray[N];
typedef struct {
  tArray registros;
  int cont;
} tLista;

bool esNumerico(string str) {
  for (int i = 0; i < str.length(); i++)
    if (isdigit(str[i]) == false)
      return false;
  return true;
}

bool esEntero(string linea) {
	bool esEntero = true;
	int longitud = linea.size();
	
	if (longitud == 0) {
		esEntero = false;
	} else if (longitud == 1 && !isdigit(linea[0])) {
		esEntero = false;
	} else {
		int indice = 0;
		if (linea[0] == '+' || linea[0] == '-') {
			indice = 1;
		} else {
			indice = 0;
		}
		while (indice < longitud) {
			if (!isdigit(linea[indice])) {
				esEntero = false;
				break;
			}
			indice++;
		}
	}	
	return esEntero;	
}

bool soloEspacios(string str) {
    for (int i = 0; i < str.length(); i++)
        if (str[i] != ' ')
            return true;
    return false;
}

bool cadenaValida(string str){
    if (str.empty())
      return false;
    else
      if (soloEspacios(str))
        return true;
      else 
        return false;   
}

bool esFloatValido(string str) {
  bool log = true;
  int cont = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '.') {
      cont++;
      if (cont > 1) {
        log = false;
        break;
      }
    } else if (isdigit(str[i]) == false) {
      log = false;
      break;
    }
  }
  return log;
}

tRegistro nuevo(){
string codigo;
string sueldo;
string nombre;
bool log;

  cout << "**********************************" << endl;
  cout << "*    Agregar Datos Pers          *" << endl;
  cout << "**********************************" << endl;
  cout << "\n Coloque los datos de la persona que desea agregar" << endl;

  do {
    cout << "Código: ";
    getline(cin, codigo);
    // cin.ignore();
    log = esNumerico(codigo);
    if (!(log))
      cout << "El valor colocado debe contener solo números" << endl;
  } while(!(log));


  do{
    cout << "Nombre: ";
    getline(cin, nombre);
    log = cadenaValida(nombre);
    if (!(log))
      cout << "El nombre colocado no es valido" << endl;
  } while(!(log));
  
  do {
    cout << "Sueldo ejemplo 999.99:";
    getline(cin, sueldo);
    //cin.ignore();
    log = esFloatValido(sueldo);
    if (!(log))
        cout << "EL sueldo colocado no es valido" << endl;
  } while(!(log));

  tRegistro auxRegistro;
  auxRegistro.codigo = stoi(codigo);
  auxRegistro.nombre = nombre;
  auxRegistro.sueldo = stof(sueldo);
  return auxRegistro;
}

void imprimirListadoPersonas(tLista lista) {
    cout << left << setw(10) << "Persona" << setw(10) << "Codigo"
    << setw(20) << "Nombre"
    << setw(10) << "Sueldo"
    << endl;
  cout << "________________________________________" << endl;

  for (int i=0; i<=lista.cont; i++){ 
    cout << left << setw(10) << i+1 << setw(10) << lista.registros[i]->codigo
      << left << setw(20) << lista.registros[i]->nombre
      << left << setw(10) << lista.registros[i]->sueldo 
    << endl;
  }
}  

int main(){
  tLista lista;
  lista.cont = 0;
  lista.registros[lista.cont] = new tRegistro(nuevo());
  lista.cont++;
  lista.registros[lista.cont] = new tRegistro(nuevo());
  lista.cont++;
  lista.registros[lista.cont] = new tRegistro(nuevo());

  cout << "**********************************" << endl;
  cout << "* Reporte de todos las personas  *" << endl;
  cout << "**********************************" << endl;
  imprimirListadoPersonas(lista);     
}
