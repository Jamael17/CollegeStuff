#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	
	int x;
	
	cout<<"Diga el numero para saber si es par o impar: ";
	cin>>x;
	if(x%2 == 0){
		cout<<"El numero es par\n";
	} else{
		cout<<"El numero es impar\n";
	}
	
	system("pause");
	return 0;
}
