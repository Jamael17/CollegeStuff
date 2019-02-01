#include <iostream>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	
	float b,x;
	
	cout<<"Introduzca el numero base: ";
	cin>>b;
	cout<<"Introduzca la raiz a buscar: ";
	cin>>x;
	cout<<"La raiz "<<x<<" de "<<b<<" es: "<<pow(b,(1/x))<<"\n";
	
	system("pause");
	return 0;
}
