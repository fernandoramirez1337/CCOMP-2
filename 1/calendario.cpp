#include <iostream>
#include <string>
using namespace std;

int mayormultiplo(int numero, int multiplo)
{
    return (numero / multiplo)*multiplo;
}

bool bisiesto(int numero)
{
	return(!(numero % 4)) ? ((!(numero % 100) && (numero % 400)) ? false : true) : false;
}

string meses[12] = { "enero","febrero","marzo","abril","mayo","junio","julio","agosto","septiembre","octubre","noviembre","diciembre" };
int valores[12] = { 0,3,3,6,1,4,6,2,5,0,3,5 };
int dias[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int tabladesiglos(int a)
{
    a/=100;
	a=5*(a-mayormultiplo(a,4));
	a-=mayormultiplo(a,7);
	return a;
}

int mes2valor(string m)
{
    for(int i=0; i<12;++i)
    {
        if (meses[i]==m)
            return valores[i];
    }
    return 0;
}

int mes2dias(string m)
{
    for(int i=0; i<12;++i)
    {
        if (meses[i]==m)
            return dias[i];
    }
    return 0;
}

int dia(string m, int a)
{
    int d=1,v1,v2,v3,v4; //Necesito calcular que dia fue el 1ro del mes
    v1=d+mes2valor(m);
    v1-=mayormultiplo(v1,7);

    v2=a-((a/100)*100);
    v3=v2/4;
    v2-=mayormultiplo(v2,28);
    v2+=v3+tabladesiglos(a);
    if ((m=="enero"||m=="febrero")&&bisiesto(a))
		v2-=1;

    v4=v1+v2;
    v4-=mayormultiplo(v4,7);
    return v4-1;
}

void imprimircalendario(string m, int a)
{
	int diasxmes=mes2dias(m);
	(m=="febrero"&&bisiesto(a))?diasxmes+=1:diasxmes+=0;
	int diainicial=dia(m,a);

    cout<<m<<", "<<a<<endl;
	cout<<"D L M M J V S"<<endl<<endl;

	int i;
	for(i=0;i<diainicial;++i)
		cout << "  ";
    i-=1;
	for(int j=1;j<=diasxmes;++j)
	{
		if(i+j-mayormultiplo(i+j,7)==0)
		{
			cout<<endl;
		}
		cout<<j<<" ";
	}

	cout<<endl<<endl<<"DO LU MA MI JU VI SA"<< endl<< endl;
}

void interfaz()
{
    string m;
    int a;
    cout<<"Ingrese un mes: (minusculas)"<<endl;
    cin>>m;
    cout<<endl<<"Ingrese un año: (no negativo)"<<endl;
    cin>>a;
    cout<<endl;
    imprimircalendario(m,a);
}
int main()
{
    interfaz();
    return 0;
}
