#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	
	int num1, num2, result;
	
	cout<<"Diga el primer numero: ";
	cin>>num1;
	cout<<"Diga el segundo numero: ";
	cin>>num2;
	result = num1 + num2;
	cout<<"\nLa sumatoria de ambos numeros es: "<<result<<"\n";
	
	system("pause");
	
	return 0;
}
