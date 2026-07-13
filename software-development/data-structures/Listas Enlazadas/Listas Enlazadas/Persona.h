#pragma once
#include <iostream>
#include<sstream>
using namespace std;

class Persona {
private:
	string cedula;
	string nombre;
	int edad;
	double salario;

public:
	Persona() {
		cedula = "";
		nombre = "";
		edad = 0;
		salario = 0;
	}
	Persona(string ced, string nom, int ed, double sal) {
		cedula = ced;
		nombre = nom;
		edad = ed;
		salario = sal;
	}

	string getCedula() { return cedula; }
	string getNombre() { return nombre; }
	int getEdad() { return edad; }
	double getSalario() { return salario; }

	string toString() {
		stringstream s;

		s << "Cedula: " << cedula << endl;
		s << "Nombre: " << nombre << endl;
		s << "Edad: " << edad << endl;
		s << "Salario: " << salario << endl;

		return s.str();
	}

	virtual ~Persona() {}
};