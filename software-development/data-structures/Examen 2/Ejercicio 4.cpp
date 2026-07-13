//Ejercicio 1 
//Juan Pablo Alvarado Carrillo
//Esteban Mayorga Castro

#include <iostream>
#include <fstream>  
using namespace std;

//estructuras
struct Nodo {
    int dato;
    Nodo* siguiente;
};
//prototipos
void menu();
void insertar(Nodo*& pila, int n);
void mostrarCima(Nodo* pila);
void eliminarTodos(Nodo*& pila);
bool pilaVacia(Nodo* pila);
// Variables global 
Nodo* pila = NULL;
int opcion;
int numero;

int main() {
    menu();
    return 0;
}

void menu() {

    do {
        cout << "----------- Menu de la Pila -----------" << endl;
        cout << "1. Insertar un numero entero a la pila" << endl;
        cout << "2. Mostrar la cima de la pila" << endl;
        cout << "3. Eliminar y mostrar todos los elementos de la pila" << endl;
        cout << "4. Salir" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
       

        switch (opcion) {
        case 1:
            cout << "Ingrese un numero para insertar: ";
            cin >> numero;
            insertar(pila, numero);
            break;
        case 2:
            if (pilaVacia(pila))
                cout << "La pila esta vacia. No hay cima que mostrar." << endl;
            else
                mostrarCima(pila);
            break;
        case 3:
            if (pilaVacia(pila))
                cout << "La pila esta vacia. No hay elementos para eliminar." << endl;
            else {
                
                ofstream archivo("PILA.txt");
                if (archivo.is_open()) {
                    Nodo* aux = pila;
                    archivo << "Elementos de la pila:\n";
                    while (aux != NULL) {
                        archivo << aux->dato << "\n";
                        aux = aux->siguiente;
                    }
                    archivo.close();
                    cout << "Se genero el archivo PILA.txt con los elementos de la pila." << endl;
                }
                else {
                    cout << "No se pudo abrir el archivo PILA.txt para escritura." << endl;
                }
                
                eliminarTodos(pila);
            }
            break;
        case 4:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
        system("pause");
        system("cls");
    } while (opcion !=4);
}


void insertar(Nodo*& pila, int n) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
    cout << "Numero " << n << " insertado en la pila." << endl;
}


void mostrarCima(Nodo* pila) {
    cout << "La cima de la pila es: " << pila->dato << endl;
}


void eliminarTodos(Nodo*& pila) {
    cout << "Eliminando elementos de la pila:" << endl;
    while (pila != NULL) {
        cout << "Elemento eliminado: " << pila->dato << endl;
        Nodo* aux = pila;
        pila = pila->siguiente;
        delete aux;
    }
}

bool pilaVacia(Nodo* pila) {
    return (pila == NULL);
}