#include <iostream>
#include "Cliente.h"
#include "Libro.h"

using namespace std;

int menuAdmin(){

	int opcion;

	cout<<"Menu del administrador"<<endl;
	cout<<"1. Agregar libro"<<endl;
	cout<<"2. Modificar libro"<<endl;
	cout<<"3. Eliminar libro"<<endl;
	cout<<"4. Borrar registro de libros"<<endl;
	cout<<"Ingrese una opcion: ";
	cin>>opcion;
	cout<<"\n\n";
	return opcion;

}//Fin del metodo del menu

int menuCliente(){

	int opcion;

	cout<<"1. Comprar libro"<<endl;
	cout<<"2. Buscar por autor"<<endl;
	cout<<"3. Buscar por título"<<endl;	
	cout<<"4. Agregar dinero a mi cuenta"<<endl;
	cout<<"5. Restablecer contraseña"<<endl;
	cout<<"6. Borrar cuenta"<<endl;
	cout<<"Ingrese una opcion: ";
	cin>>opcion;
	cout<<"\n\n";

	return opcion;

}//Fin del menu del cliente



int main(){
	
	Cliente ** lista_usuarios = new Cliente* [10];//arreglo de 10 usuarios
	Libro ** lista_libros = new Libro * [10];//arreglo de 10 libros





}//Fin del main