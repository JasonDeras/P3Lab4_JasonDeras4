#include <iostream>
#include "Cliente.h"
#include "Libro.h"

using namespace std;

//Variables controladoras
Cliente ** lista_usuarios = new Cliente *[10];//arreglo de 10 usuarios
int cantidad_usuarios=0;

Libro ** lista_libros = new Libro *[10];//arreglo de 10 libros
int cantiad_libros=0;

int menuAdmin(){

	int opcion;

	cout<<"Menu del administrador"<<endl;
	cout<<"1. Agregar libro"<<endl;
	cout<<"2. Modificar libro"<<endl;
	cout<<"3. Eliminar libro"<<endl;
	cout<<"4. Borrar registro de libros"<<endl;
	cout<<"5. Salir"<<endl;
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

//Opciones del Administrador
void agregarLibro(){

    if(cantidad_libros<10){

     	string titulo;
		string autor;
		string publicacion;
		int precio;
		string estado;

        cout<<"Ingrese nuevo libro"<<endl<<endl;  
        cout<<"Titulo: ";
        cin>>tirulo;
        cout<<"Autor: ";
        cin>>autor;
        cout<<"Publicacion: ";
        cin>>publicacion;
        cout<<"Precio: ";
        cin>>precio;
        cout<<"Estado: ";
        cin>>estado;
                  
        //agregarlo a la lista
        lista_libros [cantidad_libros] =new Libro(titulo,autor,publicacion,precio,estado);
        cantidad_lirbos++;         
        cout<<endl<<"Se agrego el libro perfectamente"<<endl;         
     }
     else{
        cout<<"Ya no hay espacio disponible en el arreglo para guardar libros"<<endl; 
    }//Fin del if que valida si estan lleno el arreglo de usuarios

}//Fin del metodo para agregar libros

void ModificarLibro();
int buscarLibro(int);
void eliminarLibro();

//Void Agregar Usuarios
void AgregarUsuario(){

    if(cantidad_usuarios<10){

     	string usuario;
     	string contrasenia;
     	string nombre;
     	int edad;
     	int dinero;

        cout<<"Ingrese nuevo cliente"<<endl<<endl;  
        cout<<"Usuario: ";
        cin>>usuario;
        cout<<"Contraseña: ";
        cin>>contrasenia;
        cout<<"Nombre: ";
        cin>>nombre;
        cout<<"Edad: ";
        cin>>edad;
        cout<<"Dinero: ";
        cin>>dinero;
                  
        //agregarlo a la lista
        lista_usuarios [cantidad_usuarios] =new Cliente(usuario,contrasenia,nombre,edad,dinero);
        cantidad_usuarios++;         
        cout<<endl<<"Se agrego el usuario perfectamente"<<endl;         
     }
     else{
        cout<<"Ya no hay espacio disponible en el arreglo para guardar usuarios"<<endl; 
    }//Fin del if que valida si estan lleno el arreglo de usuarios

}//Fin del Metodo para agregar usuario

int main(){
	
	

	lista_usuarios[cantidad_usuarios]=new Cliente("n.duron","sybase","Nicolle Duron",20,1000);

	/*
        cout<<lista_usuarios[cantidad_usuarios]->getUsuario()<<endl
        <<lista_usuarios[cantidad_usuarios]->getContra()<<endl
        <<lista_usuarios[cantidad_usuarios]->getNombre()<<endl
        <<lista_usuarios[cantidad_usuarios]->getEdad()<<endl
        <<lista_usuarios[cantidad_usuarios]->getDinero()<<endl;    
    */
   delete[]lista_usuarios;
   delete[]lista_libros;

   int opcion;
   do{
   		cout<<"1. Login"<<endl;
   		cout<<"2. Registrarse"<<endl;
   		cout<<"3. Salir"<<endl;
   		cout<<"Ingrese una opcion: ";
   		cin>>opcion;
   		cout<<endl;

   		switch(opcion){

   			case 1:{
   				
   				string usuario;
   				string contra;

   				cout<<"Ingrese el usuario: ";
   				cin>>usuario;
   				cout<<"Ingrese la contraseña: ";
   				cin>>contra;

   				if(usuario=="n.duron"&&contra=="sybase"){

   					cout<<"Entro el admin";

   				}else{

   				}//Fin del if del login

   			break;}

   			case 2:{
   				AgregarUsuario();
   			break;}

   			default:
   				cout<<"Opcion no valida"<<endl;
   			break;

   		}//Fin del switch

	}while(opcion!=3);

}//Fin del main