#include <iostream>

using namespace std;

void f_cambio(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}

void cocktail(int*lista,int tam)
{
    int*final;
    int*inicio;

    bool cambio=true;
    while(cambio)
    {
        final=lista+tam-1;
        inicio=lista;

        cambio=false;
        for(;inicio<final;inicio+=1)
        {
            if(*(inicio)>*(inicio+1))
            {
                f_cambio(*(inicio),*(inicio+1));
                cambio=true;
            }
        }

        if(!cambio)
            return;

        final=lista+tam-1;
        inicio=lista;

        for(;final>inicio;final-=1)
        {
            if(*(final)<*(final-1))
            {
                f_cambio(*(final),*(final-1));
                cambio=true;
            }
        }
    }
}

void imprimir(int*a,int l)
{
    for(int i=0;i<l;++i)
    {
        cout<<*(a+i)<<endl;
    }
}


int main()
{
    int lista[]={9,8,7,6,5,4,3,2,1};
    cocktail(lista,9);
    imprimir(lista,9);
    return 0;
}
