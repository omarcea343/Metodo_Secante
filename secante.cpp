#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void valores(double x_i_1, double x_i, int it, double tol){
	cout<<"Valor inicial aproximacion por la izquierda: "<<endl; cin>>x_i_1;
	cout<<"Valor inicial aproximacion por la derecha: "<<endl;   cin>>x_i;
	cout<<"Numero de interaciones: "<<endl; cin>>it;
	cout<<"Tolerancia de error: "<<endl;    cin>>tol;
}

double f(double x){
	x = pow(x,3)-(4)*pow(x,2)+10;
	return x;
}

double secante(double x_i_1,      // x_i_ 1 = aproximacion inicial por la izquierda
			   double x_i,      // x_i  = aproximacion inicial por la derecha
			   int it,      // it   = num de iteraciones
			   double tol){     // tol  = tolerancia del error
			   valores(x_i_1, x_i, it, tol); //pide los valores al usuario
	// Inicializacion de variables
	int i = 1;   // conteo de iteracion
	double e = 1;   // error 100%
	double x[100];
	x[i-1] = x_i_1;
	x[i] = x_i;

	cout<<" i | x[i-1] | x[i]   | x[i+1] | e"<<endl;

	while (i < it && e >= tol) {
		x[i+1] = x[i]-( f(x[i])*(x[i-1] - x[i]) / (f(x[i-1]) - f(x[i])) );

		e = (fabs(x[i+1] - x[i])/fabs(x[i+1]))*100;

		printf("%.2d | %.3f | %.3f | %.3f | %.15f \n",i, x[i-1], x[i], x[i+1], e);

		i++;
	}

	printf("\nLa mejor aproximacion de x es %.16f en %i iteraciones.", x[i], i);
}

int main(){
    double x_i_1, x_i, tol;
    int it;

	secante(x_i_1, x_i, it, tol);
	return 0;
}
