// PunterosMatriz.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

//prototipos funcion
void pedirNotas();
void mostrarNotas();
//variable global 
int numCalificacion, * notas;

int main() 
{
	pedirNotas();
	mostrarNotas();
	return 0;
}

void pedirNotas()
{
	cout << "Digite el numero de calificaciones: " << endl;
	cin >> numCalificacion;

	notas = new int[numCalificacion]; //vector dinamico, notas sin * porque es para almacenar la direccion

	for (int i = 0; i < numCalificacion; i++)
	{
		cout << "Ingrese la nota " << i << endl;
		cin >> notas[i];
	}

	system("pause");
}

void mostrarNotas()
{
	system("cls");
	cout << "---------------------" << endl;
	cout << "----Mostrar notas----" << endl;
	cout << "---------------------" << endl;
	for (int i = 0; i < numCalificacion; i++)
	{
		cout << "Notas #" << i + 1 << ": " << notas[i];
	}
}
