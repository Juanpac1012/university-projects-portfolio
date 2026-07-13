//Ejercicio 1 
//Juan Pablo Alvarado Carrillo
//Esteban Mayorga Castro

#include <iostream>
using namespace std;

//estructuras
//prototipos
void menu();
void rellenerMatriz();
void mostrarMatriz();
void sumarDiagonalSecundaria();
void sumarDiagonalPrincipal();
void sumarTotal();
//variables globales
int filas, columnas, opcion, suma = 0;
int** matriz;
bool matrizLlena = false;
int main()
{
    menu();
    return 0;
}

void menu()
{
    do {
        cout << "Ingrese la cantidad de filas: " << endl;
        cin >> filas;
        cout << "Ingrese la cantidad de columnas: " << endl;
        cin >> columnas;

        if (filas != columnas) 
        {
            cout << "La matriz debe ser cuadrada (filas = columnas). Intente de nuevo" << endl;
        }
        system("pause");
		system("cls");

    } while (filas != columnas);
    
    matriz = new int* [filas];
    for (int i = 0; i < filas; i++)
    {
        matriz[i] = new int[columnas];
    }

    do
    {
        cout << "-----------------Menu-----------------" << endl;
        cout << "1. Rellenar matriz" << endl;
        cout << "2. Mostrar matriz" << endl;
        cout << "3. Sumar diagonal principal" << endl;
        cout << "4. Sumar diagonal secundaria" << endl;
        cout << "5. Suma total de todos los elementos" << endl;
        cout << "6. Salir" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Seleccione una opcion: " << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            rellenerMatriz();
            break;
        case 2:
            mostrarMatriz();
            break;
        case 3:
            sumarDiagonalPrincipal();
            break;
        case 4:
            sumarDiagonalSecundaria();
            break;
        case 5:
            sumarTotal();
            break;
        case 6:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion incorrecta. Intente de nuevo" << endl;
        }

        system("pause");
        system("cls");
    } while (opcion != 6);
}

void rellenerMatriz()
{
    cout << "Ingrese los datos de la matriz: " << endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << "Ingrese el elemento [" << i << "][" << j << "]: ";
            cin >> *(*(matriz + i) + j);
        }
    }
	matrizLlena = true; 
}

void mostrarMatriz()
{
    if (!matrizLlena) {
        cout << "Primero debe rellenar la matriz." << endl;
        return;
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "[" << *(*(matriz + i) + j) << "]";
        }
        cout << endl;
    }
}

void sumarDiagonalSecundaria()
{
    if (!matrizLlena) {
        cout << "Primero debe rellenar la matriz." << endl;
        return;
    }
    suma = 0;
    cout << "Matriz con diagonal secundaria:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (i + j == filas - 1) {
                cout << "[" << *(*(matriz + i) + j) << "]";
                suma += *(*(matriz + i) + j);
            }
            else {
                cout << "[0]";
            }
        }
        cout << endl;
    }
    cout << "Suma de la diagonal secundaria: " << suma << endl;

}

void sumarDiagonalPrincipal()
{
    suma = 0;
    if (!matrizLlena) {
        cout << "Primero debe rellenar la matriz." << endl;
        return;
    }
    cout << "Matriz con diagonal principal:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (i == j) {
                cout << "[" << *(*(matriz + i) + j) << "]";
                suma += *(*(matriz + i) + j);
            }
            else {
                cout << "[0]";
            }
        }
        cout << endl;
    }
    cout << "Suma de la diagonal principal: " << suma << endl;
}

void sumarTotal()
{
    suma = 0;
    if (!matrizLlena) {
        cout << "Primero debe rellenar la matriz." << endl;
        return;
    }
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            suma += *(*(matriz + i) + j);
        }
    }
    cout << "Suma total de todos los elementos: " << suma << endl;
}
