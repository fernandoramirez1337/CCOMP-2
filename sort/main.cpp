#include <iostream>

using namespace std;

void fcambio( int& a, int& b )
{
	int t=a;
   	a=b;
   	b=t;
}

void cocktail( int* inicio, int tam )
{
    int*final;
    final=inicio+tam-1;
    int*a;
    a=inicio;
    int*b;
    b=final;
	bool cambio = true;
	while( cambio )
	{
	    cambio=false;
	    for(;a<b;a+=4)
        {
            if(*(a)>=*(a+1))
            {
                fcambio( *(a), *(a+1) );
                cambio = true;
            }
        }
        a=inicio;
        b=final;
	    if( !cambio )
            break;

        cambio = false;

	    for(;b>a;b-=4 )
        {
            if(*(b-1)>=*(b))
            {
            fcambio(*(a),*(a-1));
		    cambio = true;
            }
	    }
	    a=inicio;
        b=final;

	}
}

void imprimir(int*a,int len)
{
    for(int i=0;i<len;++i)
    {
        cout<<*(a+i)<<endl;
    }
}


int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1};
    imprimir(a,10);
    cocktail(a,10);
    cout<<endl;
    imprimir(a,10);
    //int*final;
    //final=a+9;

    //cout<<*(final)<<endl;

    return 0;
}
