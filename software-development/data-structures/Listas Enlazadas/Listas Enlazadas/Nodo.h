#pragma once
#include "Persona.h"

class Nodo {
private:
	Nodo* ptrNod;
	Persona* ptrPer;

public:
	Nodo(): ptrNod(NULL), ptrPer(NULL) {}
	Nodo(Persona& per, Nodo* nod) : ptrNod(nod), ptrPer((Persona*)&per) {}

	void setPersona(Persona& per) {
		if (ptrPer) delete ptrPer;
		ptrPer = (Persona*)&per;
	}
	void setSigNodo(Nodo* nod) {
		ptrNod = nod;
	}

	Persona* getPersona() { 
		return ptrPer; 
	}
	Nodo* getSigNodo() { 
			return ptrNod; 
	}

	virtual ~Nodo() {}

};