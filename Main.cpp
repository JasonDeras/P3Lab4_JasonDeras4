#include <iostream>

using namespace std;

int menu(){
	int opcion;

	cout<<"Ingrese una opcion: ";
	cin>>opcion;
	cout<<"\n\n";
}//Fin del metodo del menu

int main(){
	
	int usuario=1;

	while(usuario==1){
		cout<<"Volver al menu?[1.-Si/2.-No]: ";
		cin>>usuario;
	}//Fin del while del usuario

}//Fin del main