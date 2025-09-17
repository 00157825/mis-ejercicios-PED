#include <iostream>
#include <string>

struct Persona
{
    std :: string nombre;
    float altura, peso, IMC;  //imc = indice de masa coorporal

};


struct Persona SolicitarDatos();
void CalcularIMC(struct Persona *ptr);


int main()
{
    struct Persona persona;
    struct Persona *ptr = &persona;

    ptr->nombre = "Chepe";

    persona = SolicitarDatos();
    CalcularIMC(&persona);

    return 0;
}

struct Persona SolicitarDatos()
{
    struct Persona persona;
    std :: cout << "Ingrese su nombre: ";
    std::cin.ignore();
    getline(std::cin, persona.nombre);
    std::cout << std::endl;
    
    std::cout<< "Ingrese su altura: ";
    std::cin>>persona.altura;
    std::cout<<std::endl;

    std::cout<< "Ingrese su peso: ";
    std::cin>>persona.peso;
    std::cout<<std::endl;

    return persona;
}

void CalcularIMC(struct Persona *ptr)
{

    ptr->IMC = (ptr->peso)/(ptr->altura * ptr->altura);

    std :: cout << "Su indice de masa es: "<<ptr->IMC;
    
};