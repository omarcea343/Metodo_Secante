#include <iostream>
#include <complex>
#include <cstdlib>

using namespace std;

int main(){
	int i,j,z,k,coe,l,f,n,u,op,sw,maxit;
	int v[20], p[20];
	double xi,xa,fxi,fx1,e,b,a,x,fa,fb,tol,x0,x1;

	cout<<"Grado del polinomio: ";
	cin>>n;
	
	for(int i = 0; i <= n; i++){
		cout<<"x^"<<i;
		cin>>v[i];
	}
	
	cout<<endl<<"Tolerancia: ";
	cin>>tol;
	cout<<endl<<"Valor X0: ";
	cin>>x0;	
	cout<<endl<<"Valor X1: ";
	cin>>x1;
	cout<<endl<<"Maximo de iteraciones: ";
	cin>>maxit;
	
	z = 0;
	sw = 0;
	
	while((sw == 0) && (z <= maxit)){
		fxi = 0;
		for(int j = 0; j <= n; j++){
			fxi = fxi + v[j] * pow(x0,j);
		}
		for(int k = 0; k <= n; k++){
			fx1 = fx1 + v[k] * pow(x1,k);
		}
		xi = x1 - (fx1 * (x1 - x0)) / (fx1 - fxi);
			
		e = fabs(xi - x1);
		
		cout<<z<<"   "<<x0<<"   "<<x1<<"   "<<fxi<<"   "<<fx1<<"   "<<xi<<"   "<<e<<endl;
		
		if(e <= tol){
			sw = 1;			
		}
		else{
			z++;
			x0 = x1;
			x1 = xi;
		}
	}
	if(sw == 1){
		cout<<"x = "<<xi;
	}
	else{
		cout<<"No converge"<<endl;
	}
	
	return 0;
}
