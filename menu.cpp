#include <iostream>

using namespace std;

float func_b(float a, float b, float c, float d)
{
	return a*b*c*d;
}

float func_a(float a, float b, float c, float d)
{
	return a+b+c+d;
}

int select()
{
	int s;
	
	cout<<"Elija una operacion:\n"<<"1. Sumar\n"<<"2. Multiplicar\n"<<"3. Salir"<<endl; //los \n indican una nueva linea; estas son las opciones del menu
	cin>>s;
	
	return s;
}

int menu()
{
	int s=select(); float ans=0;
	
	switch(s)
	{
		case 1: ans=func_a(1,2,3,4); break; //operacion uno, toma cuatro parametros numericos
		case 2: ans=func_b(2,3,1,4); break; //operacion dos igual a la primera
		case 3: cout<<"Salir"<<endl;
		default: cout<<"Opcion no elegible"<<endl;
	}
	
	cout<<"El resultado es: "<<ans<<endl;
	
	return s;
}

int main()
{
	int continuar=0;
	
	do{
		continuar=menu();
	}while(continuar<3); //condicion de salida del menu
	
	return 0;
}
