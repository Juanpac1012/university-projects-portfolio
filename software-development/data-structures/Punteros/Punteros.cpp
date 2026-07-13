// Punteros.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

int main()
{
    //caso A
    int numero;
    numero = 20;
    cout << "El valor de numero es: " << numero <<  endl;
    cout << "La direccion de memoria es: " << &numero << endl;

    //caso B
    int* dirNum; //puntero
    dirNum = &numero; //solo quiero guardar la direccion 

    cout << "El valor de numero es: " << *dirNum << endl;
    cout << "La direccion de memoria es: " << dirNum << endl;
    //caso c

    system("pause");
    return 0;
}