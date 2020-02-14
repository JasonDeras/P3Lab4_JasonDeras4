#include <typeinfo>
#include <string>

using namespace std;

#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente{
	
	private: 

		string usuario;
		string contrasenia;
		string nombre;
		int edad;
		int dinero;

	public: 

		Cliente();
		Cliente(string, string, string, int, int);

		string getUsuario();
		void setUsuario(string);

		string getContra();
		void setContra(string);

		string getNombre();
		void setNombre(string);

		int getEdad();
		void setEdad(int);

		int getDinero();
		void setDinero(int);

		~Cliente();
};

#endif