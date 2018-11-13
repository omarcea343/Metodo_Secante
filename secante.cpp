#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x);

double secante(double x_i_1,      // x_i_ 1 = aproximacion inicial por la izquierda
			   double x_i,      // x_i  = aproximacion inicial por la derecha
			   int it,      // it   = num de iteraciones
			   double tol){     // tol  = tolerancia del error
	// Inicializacion de variables
	int i = 1;   // conteo de iteracion
	double e = 1;;   // error 100%
	double x[100];
	
	printf("Valor de aproximacion por la izquierda x0: "); scanf("%lf",&x_i_1);
	printf("Valor de aproximacion por la derecha x1: "); scanf("%lf",&x_i);
	printf("Maximo de iteraciones: "); scanf("%d",&it);
	printf("Tolerancia de error: "); scanf("%lf",&tol);
	
	x[i-1] = x_i_1;
	x[i] = x_i;
	
	printf(" i | x[i-1] | x[i]   | x[i+1] | e\n");
	
	while (i < it && e >= tol) {
		x[i+1] = x[i]-( f(x[i])*(x[i-1] - x[i]) / (f(x[i-1]) - f(x[i])) );
		
		e = (fabs(x[i+1] - x[i])/fabs(x[i+1]))*100;
		
		printf("%.2d | %.3f | %.3f | %.3f | %.15f \n",i, x[i-1], x[i], x[i+1], e);
		if (tol >= e){
			printf("\nLa mejor aproximacion de x es %.16f en %i iteraciones.", x[i], i);
			exit(1);
		}
		
		i++;
	}
	
	printf("\nLa mejor aproximacion de x es %.16f en %i iteraciones.", x[i], i);
}

double f(double x){
	x = pow(x,3)-(4)*pow(x,2)+10;
	return x;
}

int main(){
	printf("\n");
	double x_i_1;     // x_i_ 1 = aproximacion inicial por la izquierda
	double x_i;    // x_i  = aproximacion inicial por la derecha
	int it;  // it   = num de iteraciones
	double tol;
	secante( x_i_1, x_i,  it,  tol);
}
