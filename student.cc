#include <iostream>

struct Estudiante
{
    std::string nombre;
    int edad;
    float promedio;
};

void MostrarEstudiante(const Estudiante* estudiante);
void ModificarPromedio(Estudiante* estudiante, float nuevo_promedio);
bool Aprobar(const Estudiante* estudiante);

int main()
{

}

void MostrarEstudiante(const Estudiante* estudiante)
{
    std::cout << "Nombre: "<<estudiante->nombre<<std::endl;
};

void ModificarPromedio(Estudiante* estudiante, float nuevo_promedio)
{
    estudiante->promedio = nuevo_promedio;
};

bool Aprobar(const Estudiante* estudiante)
{
    estudiante->promedio >= 6.0f;
};



