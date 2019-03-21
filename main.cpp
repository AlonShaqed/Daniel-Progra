#include <iostream>
#include "formulas.h"

using namespace std;

float poisson()
{
	float phi, l_o, area, f, sigma, l_f, e;
	float V, e_y, e_x, phi_f;

	cout<<"Longitud phi (cm) >"<<endl;
	cin>>phi;
	cout<<"Longitud l (cm) >"<<endl;
	cin>>l_o;
	cout<<"Fuerza (N) >"<<endl;
	cin>>f;
	cout<<"Coeficiente E (GPa) >"<<endl;
	cin>>e;
	cout<<"Coeficiete de Poisson [V] >"<<endl;
	cin>>V;
	cout<<"Coeficiente de Poisson [Ex] (e-05 m) >"<<endl;
	cin>>e_x;

	area=area_pid(centi(phi));
	sigma=sigma_fa(f,area);
	l_f=l_f_se(sigma, giga(e), centi(l_o));
	cout<<"Longitud L final (m): "<<l_f<<endl;

	e_y=ey_vex(V, mili(e_x)/100);
	phi_f=phi_F(centi(phi),e_y);
	cout<<"Longitud phi final (m): "<<phi_f<<endl;

}

float traccion()
{
	float e, sigma_o, sigma_ts, lo, df, lf, epsilon, s;
	float f,area, diametro, fs, cfs;

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
	cout<<"Factor de seguridad >"<<endl;
	cin>>fs;

	lf=lo+df;
	epsilon=esfuerzo(lo,lf);
	s=sigma(e, epsilon);
	cout<<"Esfuerzo: "<<s<<endl;

	area=area_fs(f, sigma_o);
	diametro=d_api_meters(area);
	cout<<"Diametro (mm): "<<diametro<<endl;

	cfs=f_factor_seg(f,fs);
	cout<<"Factor de seguridad ("<<fs<<"):"<<cfs<<endl;
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
		case 2: ans=poisson(); break; //operacion dos igual a la primera
		case 3: cout<<"Salir"<<endl; break;
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
