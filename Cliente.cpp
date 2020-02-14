#include "Cliente.h"

#include <typeinfo>

using namespace std;

Cliente::Cliente(){
	
		usuario="";
		contraseña="";
		edad=0;
		dinero=0;
}

Cliente::Cliente(string p_usuario,string p_contraseña,int p_edad, int p_dinero){
	this->usuario=p_usuario;
	this->contraseña=p_contraseña;
	this->edad=p_edad;
	this->dinero=p_dinero;
}

string Cliente::getUsuario(){
	return usuario;
}

void Cliente::setUsuario(string p_usuario){
	this->usuario=p_usuario;
}

string Cliente::getContraseña(){
	return contraseña;
}

void Cliente::setContraseña(string p_contraseña){
	this->contraseña=p_contraseña;
}

int Cliente::getEdad(){
	return edad;
}

void Cliente::setEdad(int p_edad){
	this->edad=p_edad;
}

int Cliente::getDinero(){
	return dinero;
}

void Cliente::setDinero(int p_dinero){
	this->dinero=p_dinero
}

Cliente::~Cliente(){
	
}