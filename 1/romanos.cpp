#include <iostream>
#include <string>

using namespace std;

string romano(int entero)
{
    string x;
    string millares[] = {"","M","MM","MMM","IV","V","VI","VII","VIII","IX"};
    string centenas[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string decenas[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string unidades[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    x = millares[entero/1000]+centenas[(entero%1000)/100]+decenas[(entero%100)/10]+unidades[(entero%10)];
    return x;
}

void interfaz()
{
    int entero;
    cout<<"Ingrese un numero de 4 cifras"<<endl;
    cin>>entero;
    cout<<romano(entero)<<endl;
}
int main()
{
    interfaz();
    return 0;
}
