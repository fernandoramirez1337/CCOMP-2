#include <iostream>
#include <string>
using namespace std;


int mod(int x,int y)
{
	return(x>=0)?x%y:y-(-x%y);
}

/*
int mcd(int x, int y)
{
    if (x == 0 || y == 0)
       return 0;
    if (x == y)
        return x;
    if (x > y)
        return mcd(x-y, y);
    return mcd(x, y-x);
}

bool cooprimos(int x, int y)
{
    return (mcd(x,y)==1)?1:0;
}
*/
int inversa(int a, int b) //c
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}


int calculadora(int x,int y,int modulo,string operacion)
{
    if (operacion=="+")
    {
        return mod(x+y,modulo);
    }
    else if(operacion=="-")
    {
        return mod(x-y,modulo);
    }
    else if(operacion=="*")
    {
        return mod(x*y,modulo);
    }
    else if(operacion=="inversa")
    {
        return inversa(mod(x,modulo),modulo);
    }
    return 0;
}

void interfaz()

{
    int x,y,mod,calculo;
	string operacion;
	cout<<"CALCULADORA MODULAR"<<endl<<endl;
	cout<<"Ingrese x:"<<endl;
	cin>>x;
	cout<<"Ingrese y:"<<endl;
	cin>>y;
	cout<<"Ingrese el modulo:"<<endl;
	cin>>mod;
	cout<<"Ingrese la operacion deseada: +/-/*/inversa"<<endl;
	cin>>operacion;
	calculo=calculadora(x,y,mod,operacion);
	cout<<"................."<<endl;
    cout<<calculo<<" mod "<<mod<<endl;
}

int main ()
{
    interfaz();
	return 0;
}
