#include <iostream>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	
	float a,b,c,x1,x2,root, base;
	
	cout<<"Diga el numero A: ";
	cin>>a;
	cout<<"Diga el numero B: ";
	cin>>b;
	cout<<"Diga el numero C: ";
	cin>>c;
	
	base = 2 * a;
	root = pow(b,2) - (4 * a * c);
	x1 = (-1 * b) + pow(root,0.5f);
	x2 = (-1 * b) - pow(root,0.5f);
	
	if(root<0){
		cout<<"La ecuacion no tiene solucion real\n";
	}else{
		cout<<"Los resultados arrojados son: "<<x1/base<<" y "<<x2/base<<"\n";
	}
	
	
	system("pause");
	
	return 0;
}
