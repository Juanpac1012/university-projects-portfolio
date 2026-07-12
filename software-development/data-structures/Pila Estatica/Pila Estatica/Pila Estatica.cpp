// PilaEstatica.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <iostream>
using namespace std;
const int tamPila = 5;
struct Pila
{
	int tope;
	int elementos[tamPila];
};
struct Pila pila;

void Inicializar() {
	pila.tope = -1;
	for (int i = 0; i < tamPila; i++)
	{
		pila.elementos[i] = 0;
	}
}

bool isVacia() {
	return pila.tope == -1;
}
bool isLlena() {
	return pila.tope == tamPila - 1;
}
void Push(int n) {
	if (isLlena())
	{
		cout << "Pila llena" << endl;
	}
	else
	{
		pila.tope++;
		pila.elementos[pila.tope] = n;
	}
}

int Pop() {
	if (isVacia())
	{
		cout << "Pila vacia" << endl;
	}
	else
	{
		int temporal = pila.elementos[pila.tope];
		pila.elementos[pila.tope] = 0;
		pila.tope--;
	}
	return 0;
}

void mostrarDatos() {
	for (int i = 0; i <= pila.tope;i++)
	{
		cout << "Pila[" << i << "]:" << pila.elementos[i] << endl;
	}
}
int main()
{
	Inicializar();
	Push(1);
	Push(2);
	Push(3);
	Push(4);
	Push(5);

	Pop();
	Pop();
	Pop();
	Pop();
	Pop();
	Pop();
	mostrarDatos();
	return 0;
}

