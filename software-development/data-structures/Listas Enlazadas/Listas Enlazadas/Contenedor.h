#pragma once
#include "Nodo.h"
#include <exception>

class Contenedor {
private:
	Nodo* ppio;

public:
	Contenedor() {
		ppio = NULL;
	}
	Contenedor(Contenedor& con) {
		ppio = NULL;
		Nodo* PEx2 = con.ppio;
		while (PEx2 != NULL) {
			ingresaDeUltimo(*PEx2->getPersona());
			PEx2 = PEx2->getSigNodo();
		}
	}

	void ingresaDePrimero(Persona& per) {
		ppio = new Nodo(per, ppio);
	}
	void ingresaDeUltimo(Persona& per) {
		Nodo* PEx = ppio;
		Nodo* nuevo = NULL;

		if (PEx == NULL)
			ingresaDePrimero(per);
		else {
			while (PEx->getSigNodo() != NULL)
				PEx = PEx->getSigNodo();
			
			nuevo = new Nodo(per, NULL);
			PEx->setSigNodo(nuevo);
		}
	}

	Persona* getNodo(int n) {
		Nodo* pex = ppio;
		int contador = 1;
		if (pex == nullptr) {
			throw exception("Contenedor vacio");
		}
		else {
			while (contador < n && pex != nullptr) {
				pex = pex->getSigNodo();
				contador++;
			}
			if (pex == nullptr) {
				throw exception("Posicion invalida");
			}
			else {
				return pex->getPersona();
			}
		}
	}

	int cantidadDeNodos() {
		Nodo* PEx = ppio;
		int cantidad = 0;

		while (PEx != NULL) {
			cantidad++;
			PEx = PEx->getSigNodo();
		}

		return cantidad;
	}

	int sumaEdades() {
		Nodo* PEx = ppio;
		int suma = 0;

		while (PEx != NULL) {
			suma += PEx->getPersona()->getEdad();
			PEx = PEx->getSigNodo();
		}

		return suma;
	}
	
	double promedioEdad() {
		if (ppio == NULL)
			return 0;
		else
			return (double)sumaEdades() / cantidadDeNodos();
	}

	string personaMayor() {
		Persona* mayor = NULL;
		Nodo* PEx = ppio;
		stringstream s;

		if(PEx!=NULL) {
			mayor = PEx->getPersona();
			while (PEx != NULL) {
				if (PEx->getPersona()->getEdad() > mayor->getEdad())
					mayor = PEx->getPersona();
				PEx = PEx->getSigNodo();
			}

			s << mayor->toString() << endl;
		}

		return s.str();
	}

	int cantidadDePersonasMayoresA(int n) {
		int can = 0;
		Nodo* PEx = ppio;

		if (PEx != NULL) {
			while (PEx != NULL) {
				if (PEx->getPersona()->getEdad() > n)
					can++;
				PEx = PEx->getSigNodo();
			}
		}

		return can;
	}

	string imprimePersonasEdadParImpar() {
		Nodo* PEx = ppio;
		int impar = 0;
		int par = 0;
		stringstream s;

		if (PEx != NULL) {

			while (PEx != NULL) {
				if (PEx->getPersona()->getEdad() % 2 == 0)
					par++;
				PEx = PEx->getSigNodo();
			}

			PEx = ppio;

			while (PEx != NULL) {
				if (PEx->getPersona()->getEdad() % 2 != 0)
					impar++;
				PEx = PEx->getSigNodo();
			}
		}

		s << "Personas con edad par: " << par << endl;
		s << "Personas con edad impar: " << impar << endl;

		return s.str();
	}

	void creaPersonaAgregaFinal() {
		string cedula;
		string nombre;
		int edad;
		double salario;
		Persona* per = NULL;

		cout << "Cedula: "; cin >> cedula;
		cout << "Nombre: "; cin >> nombre;
		cout << "Edad: "; cin >> edad;
		cout << "Salario: "; cin >> salario;

		per = new Persona(cedula, nombre, edad, salario);
		ingresaDeUltimo(*per);
	}

	bool ingresaEnElLugar(int lug, Persona& per) {
		Nodo* nuevo = NULL;
		Nodo* PEx = ppio;
		int cont = 1;
		
		if (lug == 1) {
			ingresaDePrimero(per);
			return true;

		} else {
			if (PEx != NULL) {
				while (cont + 1 < lug && PEx != NULL) {
					cont++;
					PEx = PEx->getSigNodo();
				}
				if (PEx == NULL) {
					cout << "El lugar " << lug << " no es valido" << endl;
					return false;
				}
				if (cont + 1 == lug) {
					nuevo = new Nodo(per, PEx->getSigNodo());
					PEx->setSigNodo(nuevo);
					return true;
				}
			}
		}
		return false;
	}

	bool eliminarUltimo() {
		Nodo* borrado = NULL;
		Nodo* PEx = ppio;

		if (PEx != NULL) {
			while (PEx->getSigNodo()->getSigNodo() != NULL) {
				PEx = PEx->getSigNodo();
			}

			if (PEx->getSigNodo()) {
				borrado = PEx->getSigNodo();
				PEx->setSigNodo(NULL);
				delete borrado->getPersona();
				delete borrado;
			}

			return true;
		}
		return false;
	}

	bool eliminarPersonaConCedula(string ced) {
		Nodo* PEx = ppio;
		Nodo* borrado = NULL;
		bool encontrado = false;

		if (PEx != NULL) {
			if (PEx->getPersona()->getCedula() == ced) {
				borrado = ppio;
				ppio = borrado->getSigNodo();
				delete borrado->getPersona();
				delete borrado;
				return true;
			} else 
			{
				while (PEx->getSigNodo() != NULL && !encontrado) {
					if (PEx->getSigNodo()->getPersona()->getCedula() != ced)
						PEx = PEx->getSigNodo();
					else
						encontrado = true;
				}

				if (PEx->getSigNodo() != NULL) {
					borrado = PEx->getSigNodo();
					PEx->setSigNodo(borrado->getSigNodo());
					delete borrado->getPersona();
					delete borrado;
					return true;
				} else
					return false;
			}
		}
		return false;
	}

	bool eliminarNodoNumero(int n) {
		Nodo* borrado = NULL;
		Nodo* PEx = ppio;
		int cont = 1;

		if (PEx != NULL) {
			if (n == 1) {
				borrado = ppio;
				ppio = borrado->getSigNodo();
				delete borrado->getPersona();
				delete borrado;
			}
			else {
				while (cont + 1 < n && PEx->getSigNodo() != NULL) {
					cont++;
					PEx = PEx->getSigNodo();
				}
				if (PEx->getSigNodo() != NULL) {
					borrado = PEx->getSigNodo();
					PEx->setSigNodo(borrado->getSigNodo());
					delete borrado->getPersona();
					delete borrado;
					return true;
				}
				else
					return false;
			}
		}
		return false;
	}

	/*void eliminaEdades(int n) {
		Nodo* PEx = ppio;
		Nodo* borrado = NULL;

		if (PEx != NULL) {
			if (PEx->getPersona()->getEdad() == n) {
				borrado = ppio;
				ppio = borrado->getSigNodo();
				delete borrado->getPersona();
				delete borrado;
				PEx = ppio;
			}

			while (PEx != NULL) {
				if (PEx->getPersona()->getEdad() == n) {
					borrado = PEx->getSigNodo();
					PEx->setSigNodo(borrado->getSigNodo());
					delete borrado->getPersona();
					delete borrado;
				}
				else
					PEx = PEx->getSigNodo();
			}
		}
	}*/

	void eliminaEdades(int ed) {
		Nodo* PEx = ppio;
		Nodo* borrado = NULL;
		Nodo* anterior = NULL;

		// Elimina nodos al inicio de la lista que cumplen con la edad
		while (PEx != NULL && PEx->getPersona()->getEdad() == ed) {
			borrado = PEx;
			PEx = PEx->getSigNodo();
			delete borrado->getPersona();
			delete borrado;
		}

		ppio = PEx;  // Actualiza ppio después de eliminar los nodos iniciales

		// Elimina nodos intermedios y finales
		while (PEx != NULL) {
			if (PEx->getPersona()->getEdad() == ed) {
				borrado = PEx;
				PEx = PEx->getSigNodo();
				delete borrado->getPersona();
				delete borrado;
				if (anterior != NULL) {
					anterior->setSigNodo(PEx);  // Actualiza el puntero del nodo anterior
				}
			}
			else {
				anterior = PEx;
				PEx = PEx->getSigNodo();
			}
		}
	}



	string toString() {
		stringstream s;
		Nodo* PEx = ppio;

		while (PEx != NULL) {
			s << PEx->getPersona()->toString() << endl;
			PEx = PEx->getSigNodo();
		}

		return s.str();
	}

	virtual ~Contenedor() {
		Nodo* borrado = ppio;

		while (borrado != NULL) {
			ppio = borrado->getSigNodo();
			delete borrado->getPersona();
			delete borrado;
			borrado = ppio;
		}
	}
};