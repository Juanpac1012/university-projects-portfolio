#include <iostream>
using namespace std;

// Estructura del Nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Prototipos
void push(Nodo*&, int);
void pop(Nodo*&, int&);
int top(Nodo*);
bool isEmpty(Nodo*);
int size(Nodo*);
void mostrarPares(Nodo*);
void mostrarPila(Nodo*);
void menu(Nodo*&);

int main() {
    Nodo* pila = NULL;  // Se inicializa la pila vacia
    menu(pila);
    return 0;
}

void menu(Nodo*& pila) {
    int opcion, valor;
    do {
        cout << "---------- MENU PILA ----------\n";
        cout << "1. Insertar elemento (Push)\n";
        cout << "2. Eliminar elemento (Pop)\n";
        cout << "3. Mostrar tope\n";
        cout << "4. Verificar si esta vacia\n";
        cout << "5. Mostrar tamano de la pila\n";
        cout << "6. Mostrar elementos pares\n";
        cout << "7. Mostrar toda la pila\n";
        cout << "8. Salir\n";
        cout << "------------------------------ \n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese el valor a agregar: ";
            cin >> valor;
            push(pila, valor);
            break;
        case 2:
            if (!isEmpty(pila)) {
                pop(pila, valor);
                cout << "Elemento " << valor << " eliminado de la pila.\n";
            }
            else {
                cout << "La pila esta vacia, no se puede eliminar elementos.\n";
            }
            break;
        case 3:
            if (!isEmpty(pila)) {
                cout << "Elemento en el tope: " << top(pila) << "\n";
            }
            else {
                cout << "La pila esta vacia, no hay tope.\n";
            }
            break;
        case 4:
            if (isEmpty(pila)) {
                cout << "La pila esta vacia.\n";
            }
            else {
                cout << "La pila NO esta vacia.\n";
            }
            break;
        case 5:
            cout << "Tamano de la pila: " << size(pila) << " elementos.\n";
            break;
        case 6:
            if (!isEmpty(pila)) {
                mostrarPares(pila);
            }
            else {
                cout << "La pila esta vacia, no hay elementos pares.\n";
            }
            break;
        case 7:
            if (!isEmpty(pila)) {
                mostrarPila(pila);
            }
            else {
                cout << "La pila esta vacia.\n";
            }
            break;
        case 8:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Ingrese otra opcion\n";
        }

        system("pause");
        system("cls");
    } while (opcion != 8);
}

void push(Nodo*& tope, int n) {
    Nodo* nuevo = new Nodo(); //se crea espacio en memoria para un nuevo nodo
    nuevo->dato = n; // Se asigna el dato
    nuevo->siguiente = tope; // El nuevo nodo apunta al anterior tope
    tope = nuevo;   // El nuevo nodo ahora es el tope de la pila
    cout << "Elemento " << n << " agregado a la pila.\n";
}

void pop(Nodo*& tope, int& n) {
    if (tope == NULL) {
        cout << "La pila esta vacia, no se puede eliminar elementos.\n";
        return;
    }
    Nodo* temp = tope; // Se guarda el nodo a eliminar en una variable temporal
    n = tope->dato;  // Se extrae el valor del nodo
    tope = tope->siguiente;  // Se actualiza el tope de la pila
    delete temp;  // Se libera la memoria del nodo eliminado
}

int top(Nodo* tope) {
    if (tope == NULL) {
        cout << "La pila esta vacia.\n";
        return -1;
    }
    return tope->dato;
}

bool isEmpty(Nodo* tope) {
    return tope == NULL;
}

int size(Nodo* tope) {
    int contador = 0;
    while (tope) {
        contador++; // Se cuenta cada nodo en la pila
        tope = tope->siguiente; // Se avanza al siguiente nodo
    }
    return contador;
}

void mostrarPares(Nodo* tope) {
    cout << "Elementos pares en la pila: ";
    bool hayPares = false;
    while (tope) {
        if (tope->dato % 2 == 0) { // Verifica si el elemento es par
            cout << tope->dato << " ";
            hayPares = true;
        }
        tope = tope->siguiente; // Se avanza al siguiente nodo
    }
    if (!hayPares) {
        cout << "No hay elementos pares en la pila.";
    }
    cout << endl;
}

void mostrarPila(Nodo* tope) {
    cout << "Elementos en la pila: ";
    if (tope == NULL) {
        cout << "La pila esta vacia.";
    }
    else {
        while (tope) {
            cout << tope->dato << " "; // Muestra el valor del nodo actual
            tope = tope->siguiente;  // Se avanza al siguiente nodo
        }
    }
    cout << endl;
}
