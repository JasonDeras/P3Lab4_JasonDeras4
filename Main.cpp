#include <iostream>
#include "Cliente.h"
#include "Libro.h"

#include <cstring>
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
	cout<<"7. Salir"<<endl;
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

}//Fin del metodo para modificar un libro

void eliminarLibro(int posicion){
	lista_libros[posicion]->~Libro();
}//Fin del motodo para eliminar un libro

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


//Opciones cliente

void Compra(int cliente){

	int posicion;

	//Ordenando nombres
	cout<<"Libros Disponibles"<<endl;
	for(int i=0;i<cantidad_libros;i++){
		if(lista_libros[i]->getEstado()=="disponible"){
			cout<<"Libro numero: "<<i<<endl
			<<"Titulo: "<<lista_libros[i]->getTitulo()<<endl
			<<"Autor: "<<lista_libros[i]->getAutor()<<endl
			<<"Año de Publicacion: "<<lista_libros[i]->getPublicacion()<<endl
			<<"Precio: "<<lista_libros[i]->getPrecio()<<endl
			<<"Estado: "<<lista_libros[i]->getEstado()<<endl;
		}//Estado Disponible

	}//Fin del for 

	cout<<"Ingrese la posicion del libro a comprar: ";
	cin>>posicion;

	while(posicion>10 || posicion<0){
		cout<<"Posicion del libro no valida";
		cout<<"Ingrese una posicion: ";
		cin>>posicion;
	}//Valida la posicion del libro

	if(lista_libros[posicion]->getPrecio()<=lista_usuarios[cliente]->getDinero()){

		lista_usuarios[cliente]->setDinero(lista_usuarios[cliente]->getDinero()-lista_libros[posicion]->getPrecio());
		lista_libros[posicion]->setEstado("comprado");

	}else{
		cout<<"No tiene el dinero necesario para comprar el libro"<<endl<<endl;
	}//Valida si lo puede comprar

}//Fin del metodo de la compra

void Buscar_Autor(){

	string autor;
	cout<<"Ingrese el autor del libro a buscar: ";
	getline(cin,autor);
	getline(cin,autor);

	for(int i=0;i<cantidad_libros;i++){

		if(lista_libros[i]->getAutor()==autor){
			cout<<"Encontrado"<<endl;
			cout<<"Libro numero: "<<i<<endl
			<<"Titulo: "<<lista_libros[i]->getTitulo()<<endl
			<<"Autor: "<<lista_libros[i]->getAutor()<<endl
			<<"Año de Publicacion: "<<lista_libros[i]->getPublicacion()<<endl
			<<"Precio: "<<lista_libros[i]->getPrecio()<<endl
			<<"Estado: "<<lista_libros[i]->getEstado()<<endl;

			break;
		}else{
			cout<<"No lo encontro"<<endl<<endl;
		}
	}//Fin del for

}//Fin del metodo de la busqueda de autor

void Buscar_Titulo(){

	string titulo;
	cout<<"Ingrese el titulo del libro a buscar: ";
	getline(cin,titulo);
	getline(cin,titulo);

	for(int i=0;i<cantidad_libros;i++){

		if(lista_libros[i]->getTitulo()==titulo){
			cout<<"Encontrado"<<endl;
			cout<<"Libro numero: "<<i<<endl
			<<"Titulo: "<<lista_libros[i]->getTitulo()<<endl
			<<"Autor: "<<lista_libros[i]->getAutor()<<endl
			<<"Año de Publicacion: "<<lista_libros[i]->getPublicacion()<<endl
			<<"Precio: "<<lista_libros[i]->getPrecio()<<endl
			<<"Estado: "<<lista_libros[i]->getEstado()<<endl;

			break;
		}else{
			cout<<"No lo encontro"<<endl<<endl;
		}
	}//Fin del for


}//Fin del metodo de la busqueda por titulo

void Agregar_Dinero(int cliente){
	int dinero;
	cout<<"Ingrese el dinero que quierer agregar: ";
	cin>>dinero;

	while(dinero<=0){
		cout<<"No le puede restar dinero"<<endl<<endl;
		cout<<"Ingrese el dinero: ";
		cin>>dinero;
	}//While de los numeros negativos

	lista_usuarios[cliente]->setDinero(lista_usuarios[cliente]->getDinero()+dinero);

}//Fin del metodo para agregar dinero

void Borrar_Cuenta(int cliente){

	lista_usuarios[cliente]->~Cliente();

}//Fin del metodo de borrar cueta

void Restablecer_Contra(int cliente){
	string contra;
	cout<<"Ingrese nueva contraseña: ";
	cin>>contra;
	lista_usuarios[cliente]->setContra(contra);
}//Fin del metodo para restablecer la contraseña

int main(){

	lista_usuarios[cantidad_usuarios]=new Cliente("n.duron","sybase","Nicolle Duron",20,1000);

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

   					do{
   						opcion=menuAdmin();

   						switch(opcion){

							case 1:{
								//Agregar Libro
								agregarLibro();
							break;}

							case 2:{

								//Modificar libro
								if(cantidad_libros==0){
									cout<<"No hay libros registrados aun"<<endl<<endl;
								}else {
									int posicion;
									cout<<"Ingrese una posicion: ";
									cin>>posicion;

									while(posicion<0|| posicion>10){
										cout<<"La posicion no puede ser mayor a 10 o menor que cero"<<endl;
										cout<<"Ingrese una posicion: ";
										cin>>posicion;
									}//Valida que la posicion sea valida

									ModificarLibro(posicion);
								}//Fin del if que ve si hay libros en el arreglo

							break;}

							case 3:{

								//Eliminar un libro
								if(cantidad_libros==0){
									cout<<"No hay libros registrados aun"<<endl<<endl;
								}else {
									int posicion;
									cout<<"Ingrese una posicion: ";
									cin>>posicion;

									while(posicion<0|| posicion>10){
										cout<<"La posicion no puede ser mayor a 10 o menor que cero"<<endl;
										cout<<"Ingrese una posicion: ";
										cin>>posicion;
									}//Valida que la posicion sea valida

									eliminarLibro(posicion);
								}//Fin del if que ve si hay libros en el arreglo

							break;}

							case 4:{
								//Eliminar el registro de los libros
								delete []lista_libros;
								cout<<"Se elimio el registro de los libros"<<endl<<endl;
								if(lista_libros!=NULL){
									delete []lista_libros;
									lista_libros=NULL;
								}//Liberacion de memoria
							break;}

							case 5:{
								usuario_admin=2;
							break;}

   							default:{
   								cout<<"Opcion no valida"<<endl<<endl;
   							break;}
   								
   						}//Fin del case de las opciones del admin
   						cout<<"Volver al menu de admin [1.-Si/2.-No]: ";
   						cin>>usuario_admin;
   					}while(usuario_admin!=2);

   				}else{
   					for(int i=0;i<10;i++){
   						int usuario_cliente=1;
   						if(lista_usuarios[i]->getUsuario()==usuario &&lista_usuarios[i]->getContra()==contra){

   							do{
   								opcion=menuCliente();
   						
   								switch(opcion){

									case 1:{
										//Comprar libro
										if(cantidad_libros==0){
											cout<<"No hay libros registrados";
										}else {
											Compra(i);
										}//Fin del if que ve si hay libros
									break;}

									case 2:{
										//Buscar por autor
										if(cantidad_libros==0){
											cout<<"No hay Libros Registrados"<<endl<<endl;
										}else{
											Buscar_Autor();
										}

									break;}

									case 3:{
										//Buscar por titulo 
										if(cantidad_libros==0){
											cout<<"No hay Libros Registrados"<<endl<<endl;
										}else{
											Buscar_Titulo();
										}
									break;}

									case 4:{
										//Agregar dinero a mi cuenta
										Agregar_Dinero(i);
									break;}

									case 5:{
										//Restablecer contraseña
									break;}	

									case 6:{
										//Borrar cuenta
										Borrar_Cuenta(i);
									break;}

   									default:{
   										cout<<"Opcion no valida"<<endl<<endl;
   									break;}
   								
   								}//Fin del case de las opciones del cliente
   								cout<<"Volver al menu de cliente [1.-Si/2.-No]: ";
   								cin>>usuario_cliente;
   								}while(usuario_cliente!=2);
   							break;
   						}//Fin dl fi si entro

   					}//Fin del for

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

	//Liberacion de usuarios
	delete[]lista_usuarios;				
	if(lista_usuarios!=NULL){
		delete []lista_usuarios;
		lista_usuarios=NULL;
	}//Liberacion de memoria


	//Libreacion de libros
    delete []lista_libros;							
	if(lista_libros!=NULL){
		delete []lista_libros;
		lista_libros=NULL;
	}//Liberacion de memoria

}//Fin del main