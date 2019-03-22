#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class Amigos{
	public:
		string nombre, apellido, sexo, direccion, telefono;
		int edad;
		
		void mostrar(){
			cout<<nombre<<" "<<apellido<<"\n";
			cout<<edad<<" "<<sexo<<"\n";
			cout<<telefono<<"\n"<<direccion;
			cout<<"\n\n";
		}
};
int main(int argc, char** argv) {
	Amigos amigos[5];
	
	for(int i=0;i<5;i++){
		cout<<"Numero de amigos: "<<i+1<<"\n\n";
		cout<<"Nombre: ";
		cin>>amigos[i].nombre;
		cout<<"Apellido: ";
		cin>>amigos[i].apellido;
		cout<<"Sexo: ";
		cin>>amigos[i].sexo;
		cout<<"Edad: ";
		cin>>amigos[i].edad;
		cout<<"Direccion: ";
		cin>>amigos[i].direccion;
		cout<<"Telefono: ";
		cin>>amigos[i].telefono;
	}
	
	for(int i=0; i<5;i++){
		amigos[i].mostrar();
	}
	return 0;
}
