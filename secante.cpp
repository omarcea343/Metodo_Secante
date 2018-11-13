#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double f(double x);
void secante(double x_i_1, double x_i, int it, double tol);

int main(){
	double x_i_1;// x_i_ 1 = aproximacion inicial por la izquierda
	double x_i;// x_i  = aproximacion inicial por la derecha
	int it;//it = num de iteraciones
	double tol;//Tolerancia de error
	
	cout<<"Metodo de la Secante"<<endl;
	
	secante(x_i_1,x_i,it,tol);
	
	return 0;
}

double f(double x){
	x = pow(x,3)-(4)*pow(x,2)+10;
	return x;
}

void secante(double x_i_1, double x_i, int it, double tol){
	int i = 1;// conteo de iteracion
	double e = 1;;// error 100%
	double x[100];
	
	//Obtencion de Datos
	cout<<endl<<"Valor de aproximacion por la izquierda x0: "; 
	cin>>x_i_1;
	cout<<endl<<"Valor de aproximacion por la derecha x1: "; 
	cin>>x_i;
	cout<<endl<<"Maximo de iteraciones: "; 
	cin>>it;
	cout<<endl<<"Tolerancia de error: "; 
	cin>>tol;
	
	x[i-1] = x_i_1;
	x[i] = x_i;
	
	cout<<endl<<"i | x[i-1] | x[i]   | x[i+1] | e\n"<<endl;
	
	while (i < it && e >= tol) {
		x[i+1] = x[i]-( f(x[i])*(x[i-1] - x[i]) / (f(x[i-1]) - f(x[i])) );
		e = (fabs(x[i+1] - x[i])/fabs(x[i+1]))*100;
		printf("%.2d | %.3f | %.3f | %.3f | %.15f \n",i, x[i-1], x[i], x[i+1], e);
		if (tol >= e){
			printf("\nLa mejor aproximacion de x es %.16f en %i iteraciones.\n", x[i], i);
			exit(1);
		}
		i++;
	}
	printf("\nLa mejor aproximacion de x es %.16f en %i iteraciones.\n", x[i], i);
}
