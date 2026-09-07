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
    Estudiante student 
    {
        "Pepito",
        19,
        5.0f,
    };

    Estudiante* student_ptr = &student;

    std::cout<<"Datos del estudiante: "<<std::endl;
    MostrarEstudiante(student_ptr);
    
    if (Aprobar(student_ptr))
    {
        std::cout << "\nAprobado"<<std::endl;
    }

    else 
    {
       std::cout << "\nNo aprobado"<<std::endl; 
    }

    ModificarPromedio(student_ptr, 8.5f);

    std::cout<<"Nuevos datos del estudiante: "<<std::endl;
    MostrarEstudiante(student_ptr);

    if (Aprobar(student_ptr))
    {
        std::cout << "\nAprobado"<<std::endl;
    }

    else 
    {
       std::cout << "\nNo aprobado"<<std::endl; 
    }
    
}

void MostrarEstudiante(const Estudiante* estudiante)
{
    std::cout << "Nombre: "<<estudiante->nombre<<std::endl;
    std::cout << "Promedio: "<<estudiante->promedio<<std::endl;
    std::cout << "Edad: "<<estudiante->edad<<std::endl;
};

void ModificarPromedio(Estudiante* estudiante, float nuevo_promedio)
{
    estudiante->promedio = nuevo_promedio;
};

bool Aprobar(const Estudiante* estudiante)
{
    return estudiante->promedio >= 6.0f;
}



