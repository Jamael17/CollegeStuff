#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
//using namespace std;
class Customers{
	
	
	public:
		
		std::string nombre, apellido, dir, tlf;
		double monto,sub,total;
		
		void nuevaVenta(){
			std::string prntFact;
			bool validAsw = false;
			std::cout<<"Datos del cliente\n";
			std::cout<<"Nombre: ";
			std::cin>>nombre;
			std::cout<<"Apellido: ";
			std::cin>>apellido;
			std::cout<<"Direccion: ";
			std::cin>>dir;
			std::cout<<"Telefono: ";
			std::cin>>tlf;
			std::cout<<"Monto: ";
			std::cin>>monto;
			
			sub = monto * 0.18;
			total = monto + sub;
			
			std::cout<<"Total a pagar: "<<total<<"\n\n";
			
			int index;
			std::ifstream getindex;
			getindex.open("Facturas/factIndex.txt");
			if(getindex.is_open()){
				getindex>>index;
			}
			getindex.close();
			std::string factName = "Facturas/fact.txt";
			while(!validAsw){
				
				std::cout<<"Imprimir Factura (Y/N)\n";
				std::cin>>prntFact;
				
				if(prntFact == "y" ||prntFact == "Y"){
					
					//obtener una seed y traducirla a string//
					time_t timer;
					int var = time(&timer);
					std::string numFact;
					std::ostringstream temp;
					temp<<var;
					numFact = temp.str();
					//-----------------------------------//
					
					
					//Crear un archivo donde se guarda cada factura//
					std::ofstream facturas;
					std::string filename = "Facturas/"+nombre+""+apellido+""+numFact+".txt";
					
					facturas.open(filename.c_str());
					
					facturas<<nombre<<" "<<apellido<<"\n";
					facturas<<"\nDirección: "<<dir;
					facturas<<"\nTélefono: "<<tlf;
					facturas<<"\nReferencia: "<<numFact;
					facturas<<"\n\nVenta por:"<<monto;
					facturas<<"\nIVA 18%: "<<monto*0.18;
					facturas<<"\nSub-Total: "<<sub;
					facturas<<"\nTotal a pagar: "<<total;
					facturas.close();
					std::cout<<"Hecho\n";
					//---------------------------------------------------------------//
					
					
					system("pause");
					validAsw = true;
				}
				
				if(prntFact == "n" ||prntFact == "N"){
					validAsw = true;
				}
			}

			
		}
		
};


