//#include <iostream>
//#include <fstream>
#include "support.cpp"
#include <dirent.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

string dbUsers[15];
string dbPasswords[15];

void getUsers(){
	ifstream users;
	string line;
	users.open("users.txt");
	if(users.is_open()){
		for(int i=0;i<15;i++){
			getline(users,line);
			dbUsers[i]=line;
		}
	}
	users.close();
	
}
void getPasswords(){
	ifstream passwords;
	string line;
	passwords.open("passwords.txt");
	if(passwords.is_open()){
		for(int i=0;i<15;i++){
			getline(passwords,line);
			dbPasswords[i]=line;
		}
	}
	passwords.close();
}
void inventory(){
	int n;
	cout<<"\tInventario\n\n";
	cout<<"1.Ducati\n2.Harley-Davidson\n3.Kawasaki\n4.Kia\n5.Yamaha";
	cin>>n;
	switch(n){
		case 1:
			system("start Inventario/Ducati.xlsx");
			break;
		case 2:
			system("start Inventario/Harley-Davidson.xlsx");
			break;
		case 3:
			system("start Inventario/Kawasai.xlsx");
			break;
		case 4:
			system("start Inventario/Kia.xlsx");
			break;
		case 5:
			system("start Inventario/Yamaha.xlsx");
			break;
	}
}
void mainPage(){
	Customers custo;
	int n;

	system("cls");
	cout<<"\t\tAkira Motors\n\n";
	cout<<"1.Nueva venta\n";
	cout<<"2.Inventario\n";
	cout<<"3.Salir\n";
	cin>>n;
	switch(n){
		case 1:
			system("cls");
			custo.nuevaVenta();
			mainPage();
			break;
			
		case 2:
			system("cls");
			inventory();
			mainPage();
			break;
			
		case 3:
			cout<<"Hasta pronto!";
			break;
	}
	
}

void initSesion(){
	ifstream sesion;
	string line, user, pass;
	string tempUser, tempPass;
	int index = 0;
	bool allright = false;
	cout<<"Username:\n";
	cin>>user;
	cout<<"Password:\n";
	cin>>pass;
	if(user == "empty" || pass =="empty"){
		system("cls");
		initSesion();
	}
	sesion.open("users.txt");
	if(sesion.is_open()){
		for(int i=0;i<15;i++){
			index = i;
			getline(sesion,line);
			if(dbUsers[i]==line && dbUsers[i] == user){
				if(dbPasswords[index] == pass){
					allright = true;
				}
			}
		}
		
	}
	sesion.close();
	if(allright){
		mainPage();
	}
}
void updateUser(string nUser){
	for(int i=0; i<15; i++){
		if(dbUsers[i] == "empty"){
			dbUsers[i]=nUser;
			break;
			}
		}
}

void updatePass(string nPass){
for(int j=0; j<15; j++){
		if(dbPasswords[j] == "empty"){
			dbPasswords[j]=nPass;
			break;
			}
		}
}	
	



void uploadUsers(){
	ofstream data;
	data.open("users.txt");
	if(data.is_open()){
		for(int i=0; i<15; i++){
			data<<dbUsers[i]<<"\n";
		}
	}
	data.close();

}
void uploadPasswords(){
	
	ofstream data;
	data.open("passwords.txt");
	if(data.is_open()){
		for(int i=0; i<15; i++){
			data<<dbPasswords[i]<<"\n";
		}
	}
	data.close();
}
void regNewUser(){

	string nombre, apellido, dir, tlf, newUser, newPass;
	cout<<"Nombre: ";
	cin>>nombre;
	cout<<"Apellido: ";
	cin>>apellido;
	cout<<"Direccion: ";
	cin>>dir;
	cout<<"Telefono: ";
	cin>>tlf;
	cout<<"New User: ";
	cin>>newUser;
	cout<<"New Password: ";
	cin>>newPass;
	
	updateUser(newUser);
	updatePass(newPass);
	uploadUsers();
	uploadPasswords();
}

void makeFolder(){
	system("mkdir Facturas");
}
void changeColor(){
	int n;
	cout<<"Escoja un color: \n\n";
	cout<<"0.Negro\n1.Azul\n2.Verde\n3.Aguamarina\n4.Rojo\n5.Purpura";
	cout<<"\n6.Amarillo\n7.Blanco\n8.Gris\n9.Azul Claro\n";
	cin>>n;
	
	string pickColor;
	ostringstream temp;
	temp<<n;
	pickColor = "color "+temp.str();
	system(pickColor.c_str());
	
}
void options(){
	int n;
	system("cls");
	cout<<"\tOpciones\n\n";
	cout<<"1.Cambiar Color\n";
	cout<<"2.Licencia\n";
	cin>>n;
	if(n==1){
		changeColor();
	}else if(n==2){
		system("start LICENSE.txt");
	}else{
		cin>>n;
	}
}
void start(){
	int optionsMenu;
	bool success = false;
	cout<<"\t\tBienvenido al sistema\n\n";
	cout<<"1.Iniciar Sesion\n";
	cout<<"2.Registrarse\n";
	cout<<"3.Opciones\n";
	
	while(!success){
		
		cin>>optionsMenu;
		switch(optionsMenu){
			case 1:
				system("cls");
				initSesion();
				success = true;
				break;
			case 2:
				regNewUser();
				success = true;
				break;
			case 3:
				options();
				
				success = true;
				system("cls");
				start();
				break;

		}
	}
}
int main(int argc, char** argv) {
	
	

	
	getUsers();
	getPasswords();
	DIR* dir = opendir("Facturas");
	int optionsMenu;
	bool success = false;
	struct dirent *ep;
	
	if(!dir){
		makeFolder();
		
		ofstream factIndex;
		factIndex.open("Facturas/factIndex.txt");
		factIndex<<0;
		factIndex.close();
	}
	start();

	return 0;
}
