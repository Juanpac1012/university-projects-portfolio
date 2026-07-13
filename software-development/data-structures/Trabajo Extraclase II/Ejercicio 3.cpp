/* Hacer un programa en C++, utilizando Colas que contenga el siguiente menú:
1. Insertar un carácter a una cola
2. Eliminar todos los elementos de la cola
3. Salir*/

#include <iostream>
using namespace std;

// Estructura 
struct Nodo {
    char dato;
    Nodo* siguiente;
};

// Prototipos 
void menu();
void insertarElemento(Nodo*&, Nodo*&, char);
void eliminarCola(Nodo*&, Nodo*&);
void mostrarCola(Nodo*);
bool isVacia(Nodo*);

// Variables globales
Nodo* frente = NULL;
Nodo* fin = NULL;
int opcion;
char dato;

int main() {
    menu();
}

void menu() {
    do {
        cout << "---------------Menu colas----------------" << endl;
        cout << "1. Insertar un caracter a la cola" << endl;
        cout << "2. Eliminar todos los elementos de la cola" << endl;
        cout << "3. Mostrar cola" << endl;
        cout << "4. Salir" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese un caracter: ";
            cin >> dato;
            insertarElemento(frente, fin, dato);
            cout << endl;
            system("pause");
            break;
        case 2:
            eliminarCola(frente, fin);
            system("pause");
            break;
        case 3:
            mostrarCola(frente);
            system("pause");
            break;   
        case 4:
            cout << "Saliendo..." << endl;
            system("pause");
            break;
        default:
            cout << "Opcion invalida, intente de nuevo." << endl;
            system("pause");
            break;
        }
        system("cls");

    } while (opcion != 4);
}

void insertarElemento(Nodo*& frente, Nodo*& fin, char n) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    nuevoNodo->siguiente = NULL;

    if (isVacia(frente)) {
        frente = nuevoNodo;
    }
    else {
        fin->siguiente = nuevoNodo;
    }
    fin = nuevoNodo;
    cout << "Elemento " << n << " agregado a la cola." << endl;
}

void eliminarCola(Nodo*& frente, Nodo*& fin) {
    while (!isVacia(frente)) {
        Nodo* aux = frente;
        frente = frente->siguiente;
        delete aux;
    }
    fin = NULL;
    cout << "Todos los elementos han sido eliminados de la cola." << endl;
}

void mostrarCola(Nodo* frente){
    if (isVacia(frente)) {
        cout << "La cola esta vacia." << endl;
        return;
    }

    Nodo* aux = frente;
    cout << "Elementos en la cola: ";
    while (aux != NULL) {
        cout << aux->dato << " ";
        aux = aux->siguiente;
    }
    cout << endl;
}

bool isVacia(Nodo* frente) {
    if (frente == NULL)
    {
        return true;
    }
    else {
        return false;
    }
}
