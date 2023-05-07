#include <iostream>
#include <string>

using namespace std;
//función para saber si un string es un número entero
bool isInteger(string str) {
    int i = 0;
    for ( i < str.length(); i++;) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}
//función para saber si son solo espacios
bool soloEspacios(string str) {
    for (int i = 0; i < str.length(); i++)
        if (str[i] != ' ')
            return true;
    return false;
}