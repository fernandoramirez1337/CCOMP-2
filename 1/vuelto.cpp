#include <iostream>

using namespace std;

float cambio[]={2000,1000,500,200,100,50,20,10,5,2,1};
int monedas[]={0,0,0,0,0,0,0,0,0,0,0};

void funcion(float x)
{
    x*=10;
    for(int i=0;i<11;++i)
    {
        while(x>=cambio[i])
        {
            x-=cambio[i];
            monedas[i]+=1;
        }

    }
    for(int i=0;i<11;++i)
        cambio[i]/=10;
    for (int i=0;i<5;++i)
    {
        if(monedas[i]&&(monedas[i]>1))
        cout<<"Hay "<<monedas[i]<<" billetes de "<<cambio[i]<<" soles"<<endl;
        else if(monedas[i]&&(monedas[i]==1))
        cout<<"Hay "<<monedas[i]<<" billete de "<<cambio[i]<<" soles"<<endl;
    }
    for (int i=5;i<7;++i)
    {
        if(monedas[i]&&(monedas[i]>1))
        cout<<"Hay "<<monedas[i]<<" monedas de "<<cambio[i]<<" soles"<<endl;
        else if(monedas[i]&&(monedas[i]==1))
        cout<<"Hay "<<monedas[i]<<" moneda de "<<cambio[i]<<" soles"<<endl;
    }
    if(monedas[7])
        cout<<"Hay "<<monedas[7]<<" moneda de "<<cambio[7]<<" soles"<<endl;
    for (int i=8;i<11;++i)
    {
        if(monedas[i]&&(monedas[i]>1))
        cout<<"Hay "<<monedas[i]<<" monedas de "<<cambio[i]<<" centimos"<<endl;
        else if(monedas[i]&&(monedas[i]==1))
        cout<<"Hay "<<monedas[i]<<" moneda de "<<cambio[i]<<" centimos"<<endl;
    }
    //cout<<monedas[10]<<endl;
}

void interfaz()
{
    float x;
    cout<<"Ingrese la cantidad (float):"<<endl;
    cin>>x;
    funcion(x);
}
int main()
{
    interfaz();
    return 0;
}
