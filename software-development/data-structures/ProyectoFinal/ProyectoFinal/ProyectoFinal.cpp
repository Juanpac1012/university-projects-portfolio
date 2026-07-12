// JuegoAhorcado.cpp : Ahorcado con pila y control de historial/deshacer
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

// ESTRUCTURAS
struct Nodo {
    char letra;
    Nodo* siguiente;
};

// PROTOTIPOS DE FUNCIONES
// Funciones de pila
void push(Nodo*&, char);
char pop(Nodo*&);
bool contiene(Nodo*, char);
string obtenerComoCadena(Nodo*);
void mostrarHistorial(Nodo*);

// Funciones del juego
void imprimirMensaje(string, bool = true, bool = true);
void dibujar(int = 0);
void imprimirLetras(string, char, char);
void imprimirLetrasDisponibles(Nodo*);
bool imprimirPalabraRevisarVic(string, Nodo*);
string leerPalabraRandom(string);
int IntentosRestantes(string, Nodo*);


// VARIABLES GLOBALES 

int main()
{
    srand(time(0));
    Nodo* pila = NULL;
    string palabraAdivinar = leerPalabraRandom("palabras.txt");
    int intentos = 0;
    bool ganado = false;

    do {
        system("cls");
        imprimirMensaje("AHORCADO");
        dibujar(intentos);
        imprimirLetrasDisponibles(pila);
        imprimirMensaje("Adivine la palabra");

        ganado = imprimirPalabraRevisarVic(palabraAdivinar, pila);
        if (ganado) break;

        cout << "> (Ingrese letra, * para historial, # para deshacer): ";
        char letra;
        cin >> letra;
        letra = toupper(letra);

        switch (letra) {
        case '*':
            mostrarHistorial(pila);
            system("pause");
            continue;
        case '#': {
            char borrado = pop(pila);
            if (borrado != 0) {
                cout << "Se elimino: " << borrado << endl;
            }
            else {
                cout << "Nada que deshacer" << endl;
            }
            system("pause");
            continue;
        }
        }

        if (!contiene(pila, letra)) {
            push(pila, letra);
        }

        intentos = IntentosRestantes(palabraAdivinar, pila);

    } while (intentos < 10);

    if (ganado)
        imprimirMensaje("?GANASTE!");
    else {
        imprimirMensaje("?HAS PERDIDO!");
        imprimirMensaje("La palabra era: " + palabraAdivinar);
    }

    system("pause");
    getchar();
    return 0;
}


// FUNCIONES DE PILA
void push(Nodo*& pila, char letra) {
    Nodo* nuevo = new Nodo{ letra, pila };
    pila = nuevo;
}

char pop(Nodo*& pila) {
    if (!pila) return 0;
    Nodo* temp = pila;
    char letra = temp->letra;
    pila = pila->siguiente;
    delete temp;
    return letra;
}

bool contiene(Nodo* pila, char letra) {
    while (pila) {
        if (pila->letra == letra) return true;
        pila = pila->siguiente;
    }
    return false;
}

string obtenerComoCadena(Nodo* pila) {
    string letras;
    Nodo* actual = pila;
    while (actual) {
        letras += actual->letra;
        actual = actual->siguiente;
    }
    return letras;
}

void mostrarHistorial(Nodo* pila) {
    cout << "Historial de letras (ultima primero): ";
    while (pila) {
        cout << pila->letra << " ";
        pila = pila->siguiente;
    }
    cout << endl;
}


// FUNCIONES DEL JUEGO
void imprimirMensaje(string mensaje, bool imprimirInicio, bool imprimirFin)
{
    if (imprimirInicio) {
        cout << "+---------------------------------+" << endl;
        cout << "|";
    }
    else {
        cout << "|";
    }

    bool frente = true;
    for (int i = mensaje.length(); i < 33; i++) {
        if (frente)
            mensaje = " " + mensaje;
        else
            mensaje = mensaje + " ";
        frente = !frente;
    }

    cout << mensaje;
    if (imprimirFin) {
        cout << "|" << endl;
        cout << "+---------------------------------+" << endl;
    }
    else {
        cout << "|" << endl;
    }
}

void dibujar(int intentos)
{
    if (intentos >= 1) imprimirMensaje("|", false, false); else imprimirMensaje("", false, false);
    if (intentos >= 2) imprimirMensaje("|", false, false); else imprimirMensaje("", false, false);
    if (intentos >= 3) imprimirMensaje("O", false, false); else imprimirMensaje("", false, false);
    if (intentos == 4) imprimirMensaje("/  ", false, false);
    if (intentos == 5) imprimirMensaje("/| ", false, false);
    if (intentos >= 6) imprimirMensaje("/|\\", false, false); else imprimirMensaje("", false, false);
    if (intentos >= 7) imprimirMensaje("|", false, false); else imprimirMensaje("", false, false);
    if (intentos == 8) imprimirMensaje("/", false, false);
    if (intentos >= 9) imprimirMensaje("/ \\", false, false); else imprimirMensaje("", false, false);
}


void imprimirLetras(string tomadas, char from, char to)
{
    string s;
    for (char i = from; i <= to; i++) {
        if (tomadas.find(i) == string::npos) {
            s += i;
            s += " ";
        }
        else {
            s += "   ";
        }
    }
    imprimirMensaje(s, false, false);
}

void imprimirLetrasDisponibles(Nodo* pila)
{
    string letrasUsadas = obtenerComoCadena(pila);
    imprimirMensaje("Letras disponibles");
    imprimirLetras(letrasUsadas, 'A', 'M');
    imprimirLetras(letrasUsadas, 'N', 'Z');
}

bool imprimirPalabraRevisarVic(string palabra, Nodo* pila)
{
    bool gano = true;
    string s;
    for (int i = 0; i < palabra.length(); i++) {
        if (!contiene(pila, palabra[i])) {
            gano = false;
            s += "_ ";
        }
        else {
            s += palabra[i];
            s += " ";
        }
    }
    imprimirMensaje(s, false);
    return gano;
}

string leerPalabraRandom(string ruta)
{
    string palabra;
    vector<string> lineas;
    ifstream lector(ruta);
    if (lector.is_open()) {
        while (getline(lector, palabra))
            lineas.push_back(palabra);
        int lineaAleatoria = rand() % lineas.size();
        palabra = lineas.at(lineaAleatoria);
        lector.close();
    }

    for (int i = 0; i < palabra.length(); i++) {
        palabra[i] = toupper(palabra[i]);
    }

    return palabra;
}

int IntentosRestantes(string palabra, Nodo* pila)
{
    int errores = 0;
    Nodo* actual = pila;
    while (actual) {
        if (palabra.find(actual->letra) == string::npos)
            errores++;
        actual = actual->siguiente;
    }
    return errores;
}
