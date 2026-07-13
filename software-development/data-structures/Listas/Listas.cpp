// Listas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
//estructuras
struct Nodo
{
    int dato;
    Nodo* siguiente;
};
//prototipos
void insertarLista(Nodo*&, int);
void mostrarLista(Nodo*);
void buscarEleme(Nodo*&, int);
void eliminarElemento(Nodo*&, int);
void eliminarLista(Nodo*&, int&);
void menu();
//variables globales
int opcion, dato;
Nodo* lista = NULL;
int main()
{
    menu();
    return 0;
}

void insertarLista(Nodo*& lista, int n)
{
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    //CREAR DOS NODOS AUXILIARES Y ASIGNAR LISTA AL PRIMERO DE ELLOS
    Nodo* aux1 = lista;
    Nodo* aux2 = NULL;
    //3 posibles escenarios , estan en la presentacuin
    while ((aux1 != NULL) && (aux1->dato < n)) {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if (lista == aux1) { //va a estar de primero
        //no entra al while
        lista = nuevoNodo;
    }
    else {
        //ingresa al while
        aux2->siguiente = nuevoNodo;
    }
    cout << "Elemento " << n <<  " insertado con exito" << endl;
    nuevoNodo->siguiente = aux1;
}

void mostrarLista(Nodo*) {
    //Crear un nuevo nodo (actual)
    Nodo* actual = new Nodo();
    //Igualar ese nuevo nodo (actual) a la lista
    actual = lista;
    // Recorrer la lista de inicio a fin
    while (actual != NULL) {
        cout << actual->dato << "->" ;
        actual = actual->siguiente;
    }
}

void buscarEleme(Nodo*& lista, int n)
{
    bool encontrado;
    //Crear un nuevo nodo (actual)
    Nodo* actual = new Nodo();
    //Igualar ese nuevo nodo (actual) a la lista
    actual = lista;
    // Recorrer la lista de inicio a fin y buscar el elemento
    while ((actual != NULL)&&(actual->dato <=n)){
        if (actual->dato == n) {
            encontrado = true;

        }
        actual = actual->siguiente;
    }
    if (encontrado = true) {
        cout << "El elemento "<< n<<" , si exite en la lista" << endl;
    }
    else
    {
        cout << "El elemento " << n << " , no exite en la lista" << endl;
    }
}

void eliminarElemento(Nodo*& lista, int n)
{
    if (lista != NULL) {
        Nodo* aux_Borrar;
        Nodo* anterior = NULL;

        aux_Borrar = lista;

        while ((aux_Borrar != NULL) && (aux_Borrar->dato)) {
            anterior = aux_Borrar;
            aux_Borrar = aux_Borrar->siguiente;
        }

        if (aux_Borrar == NULL) {
            cout << "El elemento " <<n<<" no existe" << endl;
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

void eliminarLista(Nodo*& lista, int& n)
{
    Nodo* aux = lista;
    n = aux->dato;
    lista = aux->siguiente;

    delete aux;
}

void menu()
{
    do
    { 
    cout << "-------Menu Listas-------" << endl;
    cout << "1.Insertar " << endl;
    cout << "2.Mostrar" << endl;
    cout << "3.Buscar un elemento" << endl;
    cout << "4.Eliminar" << endl;
    cout << "6.Salir" << endl;
    cout << "Seleccione una opcion: " << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        cout << "Ingrese un dato: " << endl;
        cin >> dato;
        insertarLista(lista,dato);
        break;
    case 2:
        cout << "Mostrando lista..." << endl;
        mostrarLista(lista);
        break;
    case 3:
        cout << "Ingrese elemento a buscar" << endl;
        cin >> dato;
        buscarEleme(lista,dato);
        break;
    case 4:
        cout << "Ingrese un numero para eliminar" << endl;
        cin >> dato;
        eliminarElemento(lista, dato);
        break;
    case 5:
        break;
    default:
        break;
    }
    system("pause");
    system("cls");
    } while (opcion != 6);
}

