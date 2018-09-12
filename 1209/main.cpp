#include <iostream>

using namespace std;

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout<<a[i];
    cout<<endl;
}

void fcambio(int &a, int &b)
{
    int c=a;
    a=b;
    b=c;
}

void cocktail(int lista[],int len)
{
    bool cambio=true;
    int inicio=0;
    int final=len-1;

    while(cambio)
    {

    cambio = false;
    for (int i = inicio; i < final; ++i)
        {
        if (lista[i] > lista[i + 1])
            {
            fcambio(lista[i], lista[i + 1]);
            cambio = true;
            }
        }

    if (!cambio)
        return;

    final-=1;

    cambio = false;
    for (int i = final - 1; i >= inicio; --i)
        {
        if (lista[i] > lista[i + 1])
            {
            fcambio(lista[i], lista[i + 1]);
            cambio = true;
            }
        }
    inicio+=1;
    }
}

int main()
{
    int a[]={6,4,3,7,3,6,5,4,1,2,9};
    printArray(a,11);
    cocktail(a,11);
    printArray(a,11);

    return 0;
}
