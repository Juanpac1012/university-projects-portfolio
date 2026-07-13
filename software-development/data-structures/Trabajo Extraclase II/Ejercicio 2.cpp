/*Desarrolle una aplicación en C++ utilizando las siguientes instrucciones: Crear
una lista que almacene "n" números reales y calcular la suma de todos los
elementos de dicha lista. Además, la aplicación debe contar con las operaciones
básicas de una lista*/

#include <iostream>
using namespace std;


//Estructuras
struct Nodo
{
    int dato;
    Nodo* siguiente;
};
//Prototipos
void menu();
void insertarElemento(Nodo*&, int);
void mostrarLista(Nodo*);
void buscarElemento(Nodo*&, int);
void eliminaElemento(Nodo*&, int);
int calcularSuma(Nodo*);
//Variables globales
int opcion;
int dato;
int suma = 0;
Nodo* lista = NULL;

int main()
{
    menu();
    return 0;
}

void menu()
{
    do {
        cout << "------------Menu Listas------------" << endl;
        cout << "1. Insertar elementos a la lista" << endl;
        cout << "2. Mostrar elementos de la lista" << endl;
        cout << "3. Buscar un elemento en la lista" << endl;
        cout << "4. Eliminar un elemento en la lista" << endl;
        cout << "5. Calcular suma" << endl;
        cout << "6. Salir" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Seleccione una opcion: " << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Ingrese un numero para agregar a la lista " << endl;
            cin >> dato;
            insertarElemento(lista, dato);
            break;
        case 2:
            mostrarLista(lista);
            break;
        case 3:
            cout << "Ingrese un numero para buscar en la lista " << endl;
            cin >> dato;
            buscarElemento(lista, dato);
            break;
        case 4:
            cout << "Ingrese un numero para eliminar en la lista " << endl;
            cin >> dato;
            eliminaElemento(lista, dato);
            break;
        case 5:
            cout << "La suma de los elementos en la lista es: " << calcularSuma(lista) << endl;
            break;
        case 6:
            cout << "Saliendo...";
            break;
        default:
            cout << "Opcion invalida!";
        }

        system("pause");
        system("cls");
    } while (opcion != 6);
}

void insertarElemento(Nodo*& lista, int n)
{
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    Nodo* aux1 = lista;
    Nodo* aux2 = NULL; //revisar

    while ((aux1 != NULL) && (aux1->dato < n))
    {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        aux2->siguiente = nuevoNodo;
    }

    nuevoNodo->siguiente = aux1;
}

void mostrarLista(Nodo*) {
    Nodo* actual = new Nodo();
    actual = lista;
    if (lista != NULL) {
      while (actual != NULL)
      {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
      }
    }
    else {
        cout << "La lista esta vacia." << endl;
    }
}

void buscarElemento(Nodo*& lista, int n)
{
    bool encontrado = false;
    Nodo* actual = new Nodo();
    actual = lista;

    while ((actual != NULL) && (actual->dato <= n)) {
        if (actual->dato == n) {
            encontrado = true;
        }
        actual = actual->siguiente;
    }
    if (encontrado) {
        cout << "El elemento " << n << " , si exite en la lista" << endl;
    }
    else
    {
        cout << "El elemento " << n << " , no exite en la lista" << endl;
    }
}

void eliminaElemento(Nodo*& lista, int n)
{
    if (lista != NULL) {
        Nodo* aux_Borrar;
        Nodo* anterior = NULL;

        aux_Borrar = lista;

        while ((aux_Borrar != NULL) && (aux_Borrar->dato != n)) {
            anterior = aux_Borrar;
            aux_Borrar = aux_Borrar->siguiente;
        }

        if (aux_Borrar == NULL) {
            cout << "El elemento " << n << " no existe" << endl;
        }
        else if (anterior == NULL) {
            lista = lista->siguiente;
            delete aux_Borrar;
            cout << "El elemento " << n << " se elimino con exito" << endl;
        }
        else {
            anterior->siguiente = aux_Borrar->siguiente;
            delete aux_Borrar;
            cout << "El elemento " << n << " eliminado" << endl;
        }
    }
    else {
        cout << "Lista vacia , no hay elementos para borrar" << endl;
    }
}

int calcularSuma(Nodo* lista)
{
    int suma = 0;
    Nodo* actual = lista;

    while (actual != NULL)
    {
        suma += actual->dato;
        actual = actual->siguiente;
    }

    return suma;
}