#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	int m;
	cout<<"Diga un numero entre 1 y 12: ";
	cin>>m;
	
	switch(m){
		case 1:
			cout<<"Enero";
			break;
		case 2:
			cout<<"Febrero";
			break;
		case 3:
			cout<<"Marzo";
			break;
		case 4:
			cout<<"Abril";
			break;
		case 5:
			cout<<"Mayo";
			break;
		case 6:
			cout<<"Junio";
			break;
		case 7:
			cout<<"Julio";
			break;
		case 8:
			cout<<"Agosto";
			break;
		case 9:
			cout<<"Septiembre";
			break;
		case 10:
			cout<<"Octubre";
			break;
		case 11:
			cout<<"Noviembre";
			break;
		case 12:
			cout<<"Diciembre";
			break;
		default:
			cout<<"Numero invalido";
			break;
	}
	system("pause");
	return 0;
}
