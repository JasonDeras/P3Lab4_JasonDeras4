#include "Libro.h"

#include <typeinfo>

using namespace std;

Libro::Libro(){
	
	titulo="";
	autor="";
	publicacion="";
	precio=0;
	estado="";
}

Libro::Libro(string p_titulo, string p_autor, string p_publicacion, int p_precio, string p_estado){
	this->titulo=p_titulo;
	this->autor=p_autor;
	this->publicacion=p_publicacion;
	this->precio=p_precio;
	this->estado=p_estado;
}

string Libro::getTitulo(){
	return titulo;
}

void Libro::setTitulo(string p_titulo){
	this->titulo=p_titulo;
}

string Libro::getAutor(){
	return autor;
}

void Libro::setAutor(string p_autor){
	this->autor=p_autor;
}

string Libro::getPublicacion(){
	return publicacion;
}

void Libro::setPublicacion(string p_publicacion){
	this->publicacion=p_publicacion;
}

int Libro::getPrecio(){
	return precio;
}

void Libro::setPrecio(int p_precio){
	this->precio=p_precio;
}

string Libro::getEstado(){
	return estado;
}

void Libro::setEstado(string p_estado){
	this->estado=p_estado;
}
Libro::~Libro(){
	
}