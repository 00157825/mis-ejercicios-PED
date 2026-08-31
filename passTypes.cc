#include <iostream>
using namespace std;

void cambiarValorReferencia(int *&valor)
{
    *valor = 0; // Cambiamos el valor de la variable original a través de la referencia
}

void cambiarValor(int &a)
{
    a = 10; // Cambiamos el valor de la variable original a través de la referencia
}

void cambiarValorPuntero(int *ptr)
{
    *ptr = 20; // Cambiamos el valor de la variable original a través del puntero
}
int main()
{
    int a = 10;
    int *ptr = &a;                                    // Creamos un puntero que apunta a la variable a
    cout << "Valor original de ptr: " << ptr << endl; // Imprimimos el valor original de a
    cambiarValorReferencia(ptr);                      // Llamamos a la función que cambia el valor de a

    return 0;
}