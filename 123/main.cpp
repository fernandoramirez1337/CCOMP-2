#include <iostream>

using namespace std;


//SIETE input: cadena   output: separado por silabas

int tam(char*base)
{
    int i=0;
    while (*(base+i)!='\0')
    {
        ++i;
    }
    return i;
}

void limpiar(char*base)
{
    int l=tam(base);
    for(int i=0;i<l;++i)
        *(base+i)=64;
}

void imprimir(char*base)
{
    int l=tam(base);
    for(int i=0;i<l;++i)
        cout<<*(base+i)<<endl;
}





int main()
{
    char a[]="Hola";
    limpiar(a);
    imprimir(a);
    return 0;
}
