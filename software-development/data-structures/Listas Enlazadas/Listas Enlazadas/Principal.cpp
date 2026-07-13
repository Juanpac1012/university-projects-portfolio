#include "Contenedor.h"

int main() {
	Contenedor* con = new Contenedor();
	Persona* per1 = new Persona("111", "Laura", 41, 10000);
	Persona* per2 = new Persona("222", "Laura", 42, 10000);
	Persona* per3 = new Persona("333", "Laura", 41, 10000);
	Persona* per4 = new Persona("444", "Laura", 44, 10000);
	Persona* per5 = new Persona("555", "Laura", 41, 10000);
	Persona* per6 = new Persona("666", "Laura", 46, 10000);
	
	con->ingresaDeUltimo(*per1);
	con->ingresaDeUltimo(*per2);
	con->ingresaDeUltimo(*per3);
	con->ingresaDeUltimo(*per4);
	con->ingresaDePrimero(*per5);
	con->ingresaEnElLugar(3, *per6);

	cout << con->toString() << endl;
	try {
		cout << con->getNodo(6)->toString();
	}
	catch (exception e) {
		cerr << e.what() << endl;
	}
	
	////con->eliminarPersonaConCedula("333");
	////con->eliminarUltimo();
	////cout << con->toString();
	////cout << con->personaMayor();
	////cout << con->cantidadDeNodos();

	////cout << con->cantidadDePersonasMayoresA(41) << endl;
	//cout << con->imprimePersonasEdadParImpar() << endl;
	////con->eliminarNodoNumero(6);
	//con->eliminaEdades(41);
	//cout << endl;
	//cout << "-----------------------------------" << endl << endl;
	//cout << con->toString();

	//delete con;
	//system("pause");
	return 0;
}