#include <iostream>

struct Persona
{
    int edad;
    int altura;
};

void IntercambiarEdades(Persona &p1, Persona &p2)
{
    if (p1.edad < p2.edad)
    {
        int temp = p1.edad;
        p1.edad = p2.edad;
        p2.edad = temp;
    }
}

int main()
{

    Persona persona1 = {25, 175};
    Persona persona2 = {30, 180};

    std::cout << "Antes del intercambio:" << std::endl;
    std::cout << "Persona 1 edad: " << persona1.edad << ", altura: " << persona1.altura << std::endl;
    std::cout << "Persona 2 edad: " << persona2.edad << ", altura: " << persona2.altura << std::endl;

    IntercambiarEdades(persona1, persona2);

    std::cout << "Despues del intercambio:" << std::endl;
    std::cout << "Persona 1 edad: " << persona1.edad << ", altura: " << persona1.altura << std::endl;
    std::cout << "Persona 2 edad: " << persona2.edad << ", altura: " << persona2.altura << std::endl;

    return 0;
}