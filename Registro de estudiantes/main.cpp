#include <iostream>
#include <fstream>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class Estudiantes{
		public:
			
			string nombre, apellido, profesion, lnacimiento, direccion,cedula,telefono;
			int edad, id;
			void mostrar(){
				cout<<"ID: "<<id<<"\n"<<nombre<<" "<<apellido<<"\n";
				cout<<"Edad: "<<edad<<", "<<"Profesion: "<<profesion<<"\n";
				cout<<"Lugar de nacimiento: "<<lnacimiento<<"\n";
				cout<<"Direccion: "<<direccion<<"\n"<<"Telefono: "<<telefono;
			}
		
};

void nuevoAlumno(){
		int n;
		cout<<"Diga cantidad de estudiantes: ";
		cin>>n;
		Estudiantes estudiante[n];
		for(int i=0;i<n;i++){
			estudiante[i].id = i+1;
			cout<<"ID del estudiante: "<<estudiante[i].id;
			cout<<"\nPrimer nombre: ";
			cin>>estudiante[i].nombre;
			cout<<"Apellido: ";
			cin>>estudiante[i].apellido;
			cout<<"Cedula: ";
			cin>>estudiante[i].cedula;
			cout<<"Edad: ";
			cin>>estudiante[i].edad;
			cout<<"Profesion: ";
			cin>>estudiante[i].profesion;
			cout<<"Lugar de nacimiento: ";
			cin>>estudiante[i].lnacimiento;
			cout<<"Direccion: ";
			cin>>estudiante[i].direccion;
			cout<<"Telefono: ";
			cin>>estudiante[i].telefono;
		}
		string res;
		
		while(res != "y" || res != "Y" || res != "n" || res != "N"){
			cout<<"\nDesea exportar los datos? Y or N";
			cin>>res;
			if(res == "y" || res=="Y"){
				ofstream registro;
				registro.open("Registro de Estudiantes.txt");
				for(int i=0; i<n;i++){
					registro<<"ID del estudiante: "<<estudiante[i].id;
					registro<<"\nNombre: "<<estudiante[i].nombre<<"\n";
					registro<<"Apellido: "<<estudiante[i].apellido<<"\n";
					registro<<"Cedula: "<<estudiante[i].cedula<<"\n";
					registro<<"Edad: "<<estudiante[i].edad<<"\n";
					registro<<"Profesion: "<<estudiante[i].profesion<<"\n";
					registro<<"Lugar de nacimiento: "<<estudiante[i].lnacimiento<<"\n";
					registro<<"Direccion: "<<estudiante[i].direccion<<"\n";
					registro<<"Telefono: "<<estudiante[i].telefono<<"\n\n";
					
				}
				registro.close();
				break;
				
			}else if(res == "n" || res == "N"){
				cout<<"Hasta pronto";
				break;
			}
		}
	}
void leerBase(){
		string line;
		ifstream registro;
		registro.open("Registro de Estudiantes.txt");
		if(registro.is_open()){
			while(getline(registro,line)){
				cout<<line<<"\n";
			}
		}
		registro.close();
	}
	
int main(int argc, char** argv) {

	int options;
	bool opVal = false;
	cout<<"Bienvenido al sistema\n";
	cout<<"Elija una de las siguientes opciones:\n";
	while(options != 1 || options != 2){
		cout<<"1. Agregar nuevo alumno\n2. Leer base de datos\n";
		cin>>options;
		if(options == 1){
			nuevoAlumno();
			break;
		}
		if(options == 2){
			leerBase();
			break;
		}
	}
	
	
	return 0;
}
