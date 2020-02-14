#include "Cliente.h"

#include <typeinfo>

using namespace std;

Cliente::Cliente(){
	
	usuario="";
	contrasenia="";
	nombre="";
	edad=0;
	dinero=0;

}

Cliente::Cliente(string p_usuario,string p_contrasenia,string p_nombre ,int p_edad, int p_dinero){
	this->usuario=p_usuario;
	this->contrasenia=p_contrasenia;
	this->nombre=p_nombre;
	this->edad=p_edad;
	this->dinero=p_dinero;
}

string Cliente::getUsuario(){
	return usuario;
}

void Cliente::setUsuario(string p_usuario){
	this->usuario=p_usuario;
}

string Cliente::getContra(){
	return contrasenia;
}

void Cliente::setContra(string p_contrasenia){
	this->contrasenia=p_contrasenia;
}

string Cliente::getNombre(){
	return nombre;
}

void Cliente::setNombre(string p_nombre){
	this->nombre=p_nombre;
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
	this->dinero=p_dinero;
}

void Cliente::toString(){
	
	cout<<"Usuario: "<<usuario<<endl;
	cout<<"Contraseña: "<<contrasenia<<endl;
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
	cout<<"Dinero: "<<dinero<<endl;
	
}

Cliente::~Cliente(){
	
}