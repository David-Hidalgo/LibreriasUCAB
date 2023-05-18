#include <iostream>
#include <string>
#include "esNumero.h"
using namespace std;

int main()
{
    string name;
    cout << "What is your name? ";
    cin >> name;
    cout << "Hello, " << name << ", nice to meet you!" << endl;
    cout << "Is your name a number? " << isInteger(name) << endl;
    cout << "Is your name only spaces? " << noSoloEspacios(name) << endl;
}