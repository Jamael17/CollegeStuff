#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int main(int argc, char** argv) {
	
	int n;
	cout<<"Diga un numero: ";
	cin>>n;
	cout<<"\nLos numeros divisibles de "<<n<<" son:\n";
	
	for(int i=0; i<=100;i++){
		if(i%n==0){
			cout<<i<<"\n";
		}
		
	}
	
	system("pause");
	
	return 0;
}
