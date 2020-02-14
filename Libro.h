#include <typeinfo>
#include <string>

using namespace std;

#ifndef LIBRO_H
#define LIBRO_H

class Libro{
	
	private: 

		string titulo;
		string autor;
		string publicacion;
		int precio;
		string estado;

	public: 

		Libro();
		Libro(string, string, string, int ,string;

		string getTitulo();
		void settitulo(string);

		string getAutor();
		void setAutor(string);

		strin getPublicacion();
		void setPublicacion(string);

		int getPrecio();
		void setPrecio(int);

		string getEstado();
		void setEstado(string);
		
		~Libro();
};

#endif