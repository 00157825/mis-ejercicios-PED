#include <iostream>
#include <stdio.h>      
#include <cmath> 

const double kPi = 3.1416;

float CalcularAreaCirculo (float Radio);

int main()
{

    float radio;

    std :: cout << "Ingrese el radio de su circulo: ";
    std :: cin >> radio;

    std :: cout << "\nEl area de su circulo es: "<< CalcularAreaCirculo(radio)<< " m^2";


    
    return 0;
}

float CalcularAreaCirculo (float Radio)
{
    return roundf(kPi * (Radio * Radio));
};