//Ejercicio 1 
//Juan Pablo Alvarado Carrillo
//Esteban Mayorga Castro


#include <iostream>
#include <string>
using namespace std;

// Estructuras
struct Nodo {
    string cliente;
    Nodo* siguiente;
};

// Prototipos
void menu();
void insertar(Nodo*&, Nodo*&, string);
void mostrarFrente(Nodo*);
void mostrarFinal(Nodo*);
void eliminar(Nodo*&, Nodo*&);
bool isVacia(Nodo*);

// Variables globales
int opcion;
string nombre;
Nodo* frente = NULL;
Nodo* fin = NULL;

int main()
{
    menu();
    return 0;
}

void menu()
{
    do {
        cout << "-------------------Menu Colas-------------------" << endl;
        cout << "1. Insertar un cliente a la cola" << endl;
        cout << "2. Mostrar cliente al frente de la cola" << endl;
        cout << "3. Mostrar cliente al final de la cola" << endl;
        cout << "4. Eliminar y mostrar todos los clientes de la cola" << endl;
        cout << "5. Salir" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "Seleccione una opcion: " << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Ingrese un nombre para agregar a la cola " << endl;
            cin >> nombre;
            insertar(frente, fin, nombre);
            break;
        case 2:
            mostrarFrente(frente);
            break;
        case 3:
            mostrarFinal(fin);
            break;
        case 4:
            eliminar(frente, fin);
            break;
        case 5:
            cout << "Saliendo...";
            break;
        default:
            cout << "Opcion incorrecta, intente de nuevo.";
        }

        system("pause");
        system("cls");
    } while (opcion != 5);
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

void mostrarFrente(Nodo* frente) {
    if (!isVacia(frente)) {
        cout << "Cliente al frente de la cola " << frente->cliente << "\n";
    }
    else {
        cout << "La cola esta vacia\n";
    }
}

void mostrarFinal(Nodo* fin) {
    if (fin != NULL) {
        cout << "Cliente al final de la cola: " << fin->cliente << "\n";
    }
    else {
        cout << "La cola esta vacia \n";
    }
}

void  eliminar(Nodo*& frente, Nodo*& fin) {
    while (!isVacia(frente)) {
        Nodo* aux = frente;
        cout << "Eliminando cliente: " << aux->cliente << endl;
        frente = frente->siguiente;
        delete aux;
    }
    fin = NULL;
    cout << "Todos los elementos han sido eliminados de la cola." << endl;
}

void insertar(Nodo*& frente, Nodo*& fin, string nombre) {

    Nodo* nuevoNodo = new Nodo();

    nuevoNodo->cliente = nombre;
    nuevoNodo->siguiente = NULL;


    if (isVacia(frente)) {
        frente = nuevoNodo;
    }
    else {
        fin->siguiente = nuevoNodo;
    }
    fin = nuevoNodo;

    cout << "El cliente \"" << nombre << "\" fue insertado con exito \n";
}

