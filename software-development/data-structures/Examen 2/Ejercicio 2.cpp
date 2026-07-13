//Ejercicio 2
//Juan Pablo Alvarado Carrillo
//Esteban Mayorga Castro

#include <iostream>
using namespace std;

// Estructura 
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Prototipos 
void menu();
void insertarElemento(Nodo*& lista, int n);
void mostrarLista(Nodo* lista);
void buscarElemento(Nodo*& lista, int n);
void eliminaElemento(Nodo*& lista, int n);
int calcularOperacionMatematica(Nodo* lista);

// Variables globales
int opcion;
int dato;
Nodo* lista = NULL;

int main() {
    menu();
    return 0;
}

void menu() {
    do {
        cout << "------------Menu Listas------------" << endl;
        cout << "1. Insertar elementos a la lista" << endl;
        cout << "2. Mostrar elementos de la lista" << endl;
        cout << "3. Buscar un elemento en la lista" << endl;
        cout << "4. Eliminar un elemento en la lista" << endl;
        cout << "5. Calcular operacion matematica" << endl;
        cout << "6. Salir" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Seleccione una opcion: " << endl;
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese un numero para agregar a la lista: ";
            cin >> dato;
            insertarElemento(lista, dato);
            break;
        case 2:
            mostrarLista(lista);
            break;
        case 3:

            if (lista == NULL) {
                cout << "La lista esta vacia. No se puede buscar un elemento." << endl;
            }
            else {
                cout << "Ingrese un numero para buscar en la lista: ";
                cin >> dato;
                buscarElemento(lista, dato);
            }
            break;
        case 4:

            if (lista == NULL) {
                cout << "La lista esta vacia. No hay elementos para eliminar." << endl;
            }
            else {
                cout << "Ingrese un numero para eliminar en la lista: ";
                cin >> dato;
                eliminaElemento(lista, dato);
            }
            break;
        case 5:
            cout << "El resultado de la operacion matematica es: "
                << calcularOperacionMatematica(lista) << endl;
            break;
        case 6:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida!" << endl;
        }
        system("pause");
        system("cls");
    } while (opcion != 6);
}


void insertarElemento(Nodo*& lista, int n) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    Nodo* aux1 = lista;
    Nodo* aux2 = NULL;

    while ((aux1 != NULL) && (aux1->dato < n)) {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if (aux1 == lista) {       
        lista = nuevoNodo;
    }
    else {
        aux2->siguiente = nuevoNodo;     
    }
    nuevoNodo->siguiente = aux1;
}

void mostrarLista(Nodo* lista) {
    Nodo* actual = new Nodo();
    actual = lista;
    if (lista != NULL) {
        while (actual != NULL) {
            cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }
        cout << "NULL" << endl;
    }
    else {
        cout << "La lista esta vacia." << endl;
    }
}

void buscarElemento(Nodo*& lista, int n) {
    bool encontrado = false;
    Nodo* actual = new Nodo();
    actual = lista;
    while (actual != NULL) {
        if (actual->dato == n) {
            encontrado = true;
        
        }
        actual = actual->siguiente;
    }
    if (encontrado)
        cout << "El elemento " << n << " si existe en la lista" << endl;
    else
        cout << "El elemento " << n << " no existe en la lista" << endl;
}


void eliminaElemento(Nodo*& lista, int n) {
    if (lista != NULL) {
        Nodo* auxBorrar = lista;
        Nodo* anterior = NULL;
        while (auxBorrar != NULL && auxBorrar->dato != n) {
            anterior = auxBorrar;
            auxBorrar = auxBorrar->siguiente;
        }
        if (auxBorrar == NULL) {
            cout << "El elemento " << n << " no existe" << endl;
        }
        else if (anterior == NULL) {
            lista = lista->siguiente;
            delete auxBorrar;
            cout << "El elemento " << n << " se elimino con exito" << endl;
        }
        else {
            anterior->siguiente = auxBorrar->siguiente;
            delete auxBorrar;
            cout << "El elemento " << n << " eliminado" << endl;
        }
    }
    else {
        cout << "Lista vacia, no hay elementos para borrar" << endl;
    }
}


int calcularOperacionMatematica(Nodo* lista) {
    int resultado = 0;
    int posicion = 1;
    Nodo* actual = lista;

    while (actual != NULL) {
        int valorPotencia = 1;

        for (int i = 0; i < posicion; i++) {
            valorPotencia *= actual->dato;
        }
        resultado += valorPotencia;
        posicion++;
        actual = actual->siguiente;
    }
    return resultado;
}


