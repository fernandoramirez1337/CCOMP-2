#include <iostream>

using namespace std;


enum variables {filas=3, columnas};

long double matriz[filas][columnas] = { {1,1,1,0},{6,8,1,5},{3,1,9,1 }};


void print (long double (*matriz)[columnas])
{
    long double (*indice);
    indice=*matriz;

    long double (*pFinal)[columnas];
    pFinal=matriz+filas;

    long double (*pParcial);
    pParcial=(*matriz)+columnas;

    for(;indice<*pFinal;)
    {
        for(;indice<pParcial;)
        {
            (*indice)?(*indice)*=1:(*indice)=0;
            cout<<*indice<<" ";
            indice+=1;
        }
        cout<<endl;
        pParcial+=columnas;
    }
    cout<<endl;
}

void pivot(long double (*matriz)[columnas],int fila)
{
    long double variable;
    variable=1/(*(*(matriz+fila)+fila));

    long double (*indice);
    indice=*(matriz+fila);

    for(;indice<*(matriz+fila+1);indice++)
        (*indice)*=variable;

}

void restarfilas(long double (*matriz)[columnas],int fila)
{
    int indice=1;
    long double variable;
    while(fila+indice<filas)
    {
        variable=*(*(matriz+fila+indice)+fila);
        for(int i=0;i<columnas;i++)
        {
            (*(*(matriz+fila+indice)+i))-=(*(*(matriz+fila)+i))*variable;
        }
        indice++;
    }
}

void funcion(long double (*matriz)[columnas])
{
    long double x,y,z;
    for(int i=0;i<columnas-1;i++)
    {
        pivot(matriz,i);
        print(matriz);
        restarfilas(matriz,i);
        print(matriz);
    }
    z=*(*(matriz+filas-1)+columnas-1);
    y=*(*(matriz+filas-2)+columnas-1)-(*(*(matriz+filas-2)+columnas-2)*z);
    x=*(*(matriz+filas-3)+columnas-1)-(*(*(matriz+filas-3)+columnas-2)*z)-(*(*(matriz+filas-3)+columnas-3)*y);
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"z = "<<z<<endl;


    //*(*(puntero+i)+j)
}

int main()
{

    funcion(matriz);

    return 0;
}
