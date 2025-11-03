#include <iostream>

int Suma(int a);
int factorial(int x);
int Potencia(int a, int b);
int esPar(int a);
int esImpar(int a);

int main()
{
    int a = 6;

    std::cout << Suma(a);

    return 0;
}

int Suma(int a)
{
    if (a == 1)
    {
        return 1;
    }

    else
    {
        return (a + Suma(a-1));
    }
    
}

int factorial(int x)
{
    if (x <= 1)
    {
        return 1;
    }

    else
    {
        return x * factorial((x-1));
    }
    
}

int Potencia(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }

    else if (b == 1)
    {
        return a;
    }
    
    else
    {
        return a * Potencia(a, (b-1));
    }
    
}

int esPar(int a)
{
    if (a % 2 == 0)
    {
        return true;
    }
    
    else
    {
        return esImpar(a);
    }
}

int esImpar(int a)
{
    
}