#include <iostream>

using namespace std;

float matriz[4][5] = { {7,2,9,4,4},{1,2,3,4,5},{5,1,1,9,3},{7,5,2,2,8} };


//matriz[ecuaciones][n]
bool verificar(float **matriz,int ecuaciones,int n)
{
    for (int i=0;i<n-1;i++)
    {
        if (matriz[ecuaciones-1][i])
            return 0;
    }
    return 1;
}

void imprimir(float matriz[][5],int x,int y)
{
    for (int i=0;i<x;i++)
    {
        for (int j=0;j<y;j++)
        {
        cout << matriz[i][j] << ' ';
        }
       cout<<endl;
    }
    cout<<endl;
}

void pivot(float matriz[][5],int ecuaciones,int n,int fila)
{
    float variable;
    variable=1/matriz[fila][fila];
    for(int i=0;i<n;i++)
        matriz[fila][i]*=variable;

}

void funcion(float matriz[][5], int ecuaciones,int n)
{

    float variable;
    variable=1/matriz[0][0];
    for(int i=0;i<n;i++)
        matriz[0][i]*=variable;

}

int main()
{
    imprimir(matriz,4,5);
    pivot(matriz,4,5,1);
    imprimir(matriz,4,5);

    return 0;
}
