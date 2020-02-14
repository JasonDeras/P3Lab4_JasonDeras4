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

		string getUsuario();
		void setString(string);

		string getContraseña();
		void setContraseña(string);

		int getEdad();
		void setEdad(int);

		int getDinero();
		void setDinero(int);

		~Cliente();
};

#endif