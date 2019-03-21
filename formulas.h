#include <math.h>

double Pi=3.14159265359;

float esfuerzo(float l_o, float l_f){
	return (l_f-l_o)/l_o;
}

float sigma(float e, float epsilon){
	return e*epsilon;
}

float sigma_fa(float f, float a){
	return f/a;
}

float area_fs(float f, float sigma){
	return f/sigma;
}

float area_pid(float d){
	return (Pi*pow(d,2))/4;
}

float d_api(float a){
	return sqrt(4*a/Pi);
}

float f_factor_seg(float f, float fs){
	return f*fs;
}

float l_f_se(float sigma, float e, float l_o){
	return (sigma/e)*l_o+l_o;
}

float V(float e_x, float e_y){
	return e_y/e_x;
}

float ey_vex(float V, float e_x){
	return V*e_x;
}
