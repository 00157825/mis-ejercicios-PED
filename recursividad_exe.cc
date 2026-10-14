#include <iostream>

int Potencia(int a, int b);
void InvertirCadena(const std::string cadena, int i);

int main()
{
    std::cout << Potencia(2, 5);

    std::cout << std::endl;

    InvertirCadena("ana", 0);


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
        return a * Potencia(a, (b - 1));
    }
}

void InvertirCadena(const std::string s, int i)
{
    if (i == s.size())
    {
        return;
    }                        
    InvertirCadena(s, i + 1); // primero avanza hasta el final
    std::cout << s[i];
}
