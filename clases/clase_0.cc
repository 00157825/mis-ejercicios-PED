#include <iostream>

float area_circulo (float x);

int main()
{

    float radio;

    std :: cout << "Ingrese el radio de su circulo: ";
    std :: cin >> radio;
    std :: cout << "/n";

    std :: cout << "El area de su circulo es: "<< area_circulo(radio)<< " m^2";


    
    return 0;
}

float area_circulo (float x)
{
    return 3.1416 * (x * x);
};