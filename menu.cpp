#include <iostream>
#include "formulas.h"

using namespace std;

float func_b()
{
	return 3.4;
}

float traccion()
{
	float e, sigma_o, sigma_ts, lo, df, lf, epsilon, s;
	float f,area, diametro;

	cout<<"Modulo de Young (MPa)>"<<endl;
	cin>>e;
	cout<<"Limite Elastico (MPa)>"<<endl;
	cin>>sigma_o;
	cout<<"Resistencia a la traccion (MPa)>"<<endl;
	cin>>sigma_ts;
	cout<<"==Esfuerzo:\nLongitud (mm)>"<<endl;
	cin>>lo;
	cout<<"Alargamiento [D] (MPa)>"<<endl;
	cin>>df;
	cout<<"==Diametro:\nCarga (kN)>"<<endl;
	cin>>f;

	lf=lo+df;
	epsilon=esfuerzo(lo,lf);
	s=sigma(e, epsilon);
	cout<<"Esfuerzo: "<<s<<endl;

	area=area_fs(f, sigma_o);
	diametro=d_api(area);
	cout<<"Diametro (mm): "<<diametro<<endl;
}

int select()
{
	int s;
	
	cout<<"Elija una operacion:\n"<<"1. Traccion\n"<<"2. Poisson\n"<<"3. Salir"<<endl; //los \n indican una nueva linea; estas son las opciones del menu
	cin>>s;
	
	return s;
}

int menu()
{
	int s=select(); float ans=0;
	
	switch(s)
	{
		case 1: ans=traccion(); break; //operacion uno, toma cuatro parametros numericos
		case 2: ans=func_b(); break; //operacion dos igual a la primera
		case 3: cout<<"Salir"<<endl;
		default: cout<<"Opcion no elegible"<<endl;
	}
	
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
