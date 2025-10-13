#include <iostream>
#include <queue>
#include <windows.h>

struct Persona
{
    std ::string nombre;
    int fecha_nac;
};


void SolicitarDatos(struct Persona &persona);
void Imprimir(std::queue<struct Persona> &cola);

int main()
{

    int opcion;
    std::queue<struct Persona> cola;
    struct Persona persona;

    do
    {
        SolicitarDatos(persona);
        cola.push(persona);

        std :: cout <<"¿Quiere seguir usando el programa? \n 1. Si \n 2. No \n "<<std::endl;
        std :: cin >> opcion;
    } while (opcion == 1);
    
    Imprimir(cola);

    return 0;
}

void SolicitarDatos(struct Persona &persona)
{
    std ::cout << "Ingrese el nombre de la persona: ";
    std::cin.ignore();
    getline(std::cin, persona.nombre);

    std ::cout << "Ingrese su año de nacimiento: ";
    std ::cin >> persona.fecha_nac;
}

void Imprimir(std::queue<struct Persona> &cola)
{
    std::cout << "\nTamaño de la cola: " << cola.size();

    while (!cola.empty())
    {
        std::cout << "\nPrimera persona en la cola:";
        std::cout << "\n  Nombre: " << cola.front().nombre;
        std::cout << "\n  Año de nacimiento: " << cola.front().fecha_nac << "\n";

        cola.pop();
        Sleep(3000); 
    }

};