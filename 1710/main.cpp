#include <iostream>

using namespace std;


enum variables {filas=3, columnas};

long double matriz[filas][columnas] = { {1,1,1,0},{11,24,3,4},{25,17,13,5 }};


void cero(long double matriz[][columnas])
{
    for (int i=0;i<filas;i++)
    {
        for (int j=0;j<columnas;j++)
        {
        (!matriz[i][j])?matriz[i][j]=0:matriz[i][j]*=1;
        }
    }
}

void imprimir(long double matriz[][columnas])
{
    for (int i=0;i<filas;i++)
    {
        for (int j=0;j<columnas;j++)
        {
        (!matriz[i][j])?matriz[i][j]=0:matriz[i][j]*=1;
        cout << matriz[i][j] << ' ';
        }
       cout<<endl;
    }
    cout<<endl;
}

void pivot(long double matriz[][columnas],int fila)
{
    long double variable;
    variable=1/matriz[fila][fila];
    for(int i=0;i<columnas;i++)
        matriz[fila][i]*=variable;

}

void restarfilas(long double matriz[][columnas],int fila)
{
    int indice=1;
    long double variable;
    while(fila+indice<filas)
    {
        variable=matriz[fila+indice][fila];
        for(int i=0;i<columnas;i++)
        {
            matriz[fila+indice][i]-=(matriz[fila][i]*variable);
        }
        indice++;
    }
}

void funcion(long double matriz[][columnas])
{
    long double x,y,z;
    for(int i=0;i<columnas-1;i++)
    {
        pivot(matriz,i);
        imprimir(matriz);
        restarfilas(matriz,i);
        imprimir(matriz);
    }
    z=matriz[filas-1][columnas-1];
    y=matriz[filas-2][columnas-1]-(matriz[filas-2][columnas-2]*z);
    x=matriz[filas-3][columnas-1]-(matriz[filas-3][columnas-2]*z)-(matriz[filas-3][columnas-3]*y);
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"z = "<<z<<endl;


}

int main()
{

    funcion(matriz);

    return 0;
}
