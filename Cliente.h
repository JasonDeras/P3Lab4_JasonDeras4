#include <typeinfo>
#include <string>

using namespace std;

#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente{
	
	private: 

		string usuario;
		string contraseña;
		int edad;
		int dinero;

	public: 

		Cliente();
		Cliente(string, string, int, int);

		string getUsuario();
		void setUsuario(string);

		string getContraseña();
		void setContraseña(string);

		int getEdad();
		void setEdad(int);

		int getDinero();
		void setDinero(int);

		~Cliente();
};

#endif