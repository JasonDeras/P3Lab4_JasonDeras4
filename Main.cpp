#include <iostream>
#include "Cliente.h"
#include "Libro.h"

using namespace std;

//Variables controladoras
Cliente ** lista_usuarios = new Cliente *[10];//arreglo de 10 usuarios
int cantidad_usuarios=0;

Libro ** lista_libros = new Libro *[10];//arreglo de 10 libros
int cantidad_libros=0;

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
        cin>>titulo;
        cout<<"Autor: ";
        getline(cin,autor);
        getline(cin,autor);
        cout<<"Publicacion: ";
        cin>>publicacion;
        cout<<"Precio: ";
        cin>>precio;
        cout<<"Estado: ";
        cin>>estado;
                  
        //agregarlo a la lista
        lista_libros [cantidad_libros] =new Libro(titulo,autor,publicacion,precio,estado);
        cantidad_libros++;         
        cout<<endl<<"Se agrego el libro perfectamente"<<endl;         
     }
     else{
        cout<<"Ya no hay espacio disponible en el arreglo para guardar libros"<<endl; 
    }//Fin del if que valida si estan lleno el arreglo de usuarios

}//Fin del metodo para agregar libros

void ModificarLibro(int posicion){
	
	if(cantidad_libros==0){
		cout<<"No se han agregado libros aun"<<endl<<endl;
	}else{

		string titulo;
		string autor;
		string publicacion;
		int precio;
		string estado;

        cout<<"Ingrese nuevos datos"<<endl<<endl;  
        cout<<"Titulo: ";
        cin>>titulo;
        cout<<"Autor: ";
        getline(cin,autor);
        getline(cin,autor);
        cout<<"Publicacion: ";
        cin>>publicacion;
        cout<<"Precio: ";
        cin>>precio;
        cout<<"Estado: ";
        cin>>estado;
                  
        //Modificarlo de la lista
        lista_libros [posicion]->setTitulo(titulo);
        lista_libros [posicion]->setAutor(autor);
        lista_libros [posicion]->setPublicacion(publicacion);
        lista_libros [posicion]->setPrecio(precio);
        lista_libros [posicion]->setEstado(estado);

	}//Fin del if que ve si hay libros en el arreglo

}//Fin del metodo para modificar un libro

void eliminarLibro(int posicion){

}//Fin del motodo para eliminar un libro

void EliminarRegistro(){

}//Fin del metodo para eliminar el registro de libros

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
        getline(cin,nombre);
        getline(cin,nombre);
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
   int usuario_menu=1;
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
   				int opcion2;
   				int usuario_admin=1;

   				cout<<"Ingrese el usuario: ";
   				cin>>usuario;
   				cout<<"Ingrese la contraseña: ";
   				cin>>contra;

   				if(usuario=="n.duron"&&contra=="sybase"){

   					opcion=menuAdmin();

   					do{
   						switch(opcion){

							case 1:{
								//Agregar Libro
								agregarLibro();
							break;}

							case 2:{
								//Modificar libro
								int posicion;
								cout<<"Ingrese una posicion: ";
								cin>>posicion;

								while(posicion<0|| posicion>10){
									cout<<"La posicion no puede ser mayor a 10 o menor que cero"<<endl;
									cout<<"Ingrese una posicion: ";
									cin>>posicion;
								}//Valida que la posicion sea valida

								ModificarLibro(posicion);

							break;}

							case 3:
								//Eliminar libro
							break;

							case 4:
								//Eliminar el registro de los libros
							break;

   							default:
   								cout<<"Opcion no valida"<<endl<<endl;
   							break;
   								
   						}//Fin del case de las opciones del usuario
   						cout<<"Volver al menu de admin [1.-Si/2.-No]: ";
   						cin>>usuario_admin;
   					}while(usuario_admin!=2);

   				}else{

   				}//Fin del if del login

   			break;}

   			case 2:{
   				AgregarUsuario();
   			break;}

   			default:
   				cout<<"Opcion no valida"<<endl<<endl;
   			break;

   		}//Fin del switch
   		cout<<"Volver al menu de login o registro [1.-Si,2.-No]: ";
   		cin>>usuario_menu;

	}while(usuario_menu!=2);
	delete[]lista_usuarios;
    delete[]lista_libros;

}//Fin del main