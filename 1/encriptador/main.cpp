#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*int mod(int x,int y)
{
	return(x>=0)?x%y:y-(-x%y);
}

int mcd(int x, int y)
{
    if (x == 0 || y == 0)
       return 0;
    if (x == y)
        return x;
    if (x > y)
        return mcd(x-y, y);
    return mcd(x, y-x);
}*/

int inversa(int a, int b) //c
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

void encriptador(int clave_priv)
{
    ifstream input( "txt.txt" );
    ofstream output("encriptado.txt");
    string texto;

    for(int i = 0; input.eof()!=true; i++ )
    {
        texto += input.get();
    }
    input.close();


    char encriptado = texto[0];
    int variable;
    for( int i = 0; encriptado != '\0'; encriptado = texto[++i])
    {
        variable = (encriptado*clave_priv)%256;
        texto[i] = variable;
    }

    texto = texto.substr(0, texto.length() - 1 );

    output << texto;
    output.close();
    return;
}


void desencriptador(int clave_pub)
{

    ifstream input("encriptado.txt");
    ofstream output("desencriptado.txt");
    string texto;


    for(int i = 0; input.eof()!=true; i++ )
    {
        texto += input.get();
    }
    input.close();

    char desencriptado = texto[0];
    for( int i = 0; desencriptado != '\0'; desencriptado = texto[++i])
    {
        int variable= (desencriptado*clave_pub)%256;
        texto[i] = variable;
    }

    texto=texto.substr(0,texto.length()-1);

    output<<texto;
    output.close();
    return;
}

void interfaz()
{
    int priv,pub;
    cout<< "Ingrese la clave para el cifrado: " << std::endl;
    cin>>pub;
    priv=inversa(pub,256);
    encriptador(pub);
    desencriptador(priv);
}

int main()
{
    interfaz();
    return 0;
}
