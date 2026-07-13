/*Crear un programa con el cual podamos guardar el nombre del articulo y el
nombre de la empresa proveedora de diferentes productos de una tienda
electrónica sin perder ninguno de ellos. Utilice una matriz dinámica con
punteros, el cual el usuario defina el tamaño de registros que desea registrar.*/

#include <string>
#include <iostream>
using namespace std;
//estructuras
//prototipos
void pedirDatos();
void mostrarDatos();
void limpiarMemoria();
void menu();
//variables globales
int numRegistros;
string** registros;

int main()
{
    menu();
    limpiarMemoria();
    return 0;
}

void pedirDatos()
{
    cout << "Cuantos registros quiere realizar" << endl;
    cin >> numRegistros;

    registros = new string * [numRegistros];
    for (int i = 0; i < numRegistros; i++)  //filas
    {
        registros[i] = new string[2]; // dos columnas: nombre del artículo y proveedor
    }

    cout << "Ingrese los datos de los registros: " << endl;
    while (getchar() != '\n'); // Limpiar el buffer

    for (int i = 0; i < numRegistros; i++)
    {
        system("cls");
        cout << "------- Registro #" << i + 1 << " -------" << endl;

        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                cout << "Articulo: " << endl;
                getline(cin, *(*(registros + i) + j));
            }
            else
            {
                cout << "Proveedor: " << endl;
                getline(cin, *(*(registros + i) + j));
            }
        }
    }
}

void mostrarDatos()
{
    system("cls");
    cout << "\tLista de registros" << endl;

    for (int i = 0; i < numRegistros; i++)
    {
        cout << "------------------------------------" << endl;
        cout << "Producto #" << i + 1 << endl;
        cout << "\tNombre del articulo: " << *(*(registros + i) + 0) << endl;
        cout << "\tProveedor: " << *(*(registros + i) + 1) << endl;
        cout << "------------------------------------" << endl;
    }
}

void limpiarMemoria()
{
    for (int i = 0; i < numRegistros; i++)
    {
        delete[] registros[i];
    }
    delete[] registros;
}

void menu()
{
    int opcion;
    do {
        cout << "--------------- Menu ---------------" << endl;
        cout << "1. Registrar productos" << endl;
        cout << "2. Mostrar productos registrados" << endl;
        cout << "3. Salir" << endl;
        cout << "------------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            pedirDatos(); 
            break;
        case 2:
            mostrarDatos(); 
            break;
        case 3:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente nuevamente." << endl;
        }

        system("pause");
        system("cls");

    } while (opcion != 3);  
}