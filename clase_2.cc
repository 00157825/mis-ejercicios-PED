#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

void ImprimirDatos(struct DatosCantante datos);

struct DatosCantante SolicitarDatos();

int CalcularAntiguedad(struct DatosCantante datos);

struct InformacionAlbum
{
    std ::string nombre_del_album;
    int ano_de_lanzamiento;
    std ::vector<std ::pair<int, std::string>> canciones;
    int edad_album;

};

struct DatosCantante
{
    std ::string nombre_cantante, nacionalidad_cantante;
    InformacionAlbum album;
}datos;

int main()
{
    struct DatosCantante cantantes = SolicitarDatos();

    ImprimirDatos(cantantes);

    std :: cout << "La antiguedad del album es: "<<CalcularAntiguedad(cantantes)<< " años. "<<std::endl;

    return 0;
}

struct DatosCantante SolicitarDatos()
{
    int num_cantantes;
    //std::vector<DatosCantante> vector_cantante;

    std::cout << "¿Cuántos cantantes desea registrar? ";
    std::cin >> num_cantantes;
    std::cout << "\n";

    for (int i = 0; i < num_cantantes; i++)
    {

        int num_canciones;

        std::cout << "Ingrese el nombre del cantante: ";
        std::cin >> datos.nombre_cantante;
        std::cout << "\n";

        std::cout << "Ingrese la nacionalidad del cantante: ";
        std::cin >> datos.nacionalidad_cantante;
        std::cout << "\n";

        std::cout << "Nombre del Album: ";
        std::cin.ignore();
        std::getline(std::cin, datos.album.nombre_del_album);
        std::cout << "\n";

        std::cout << "Año de lanzamiento: ";
        std::cin >> datos.album.ano_de_lanzamiento;
        std::cout << "\n";

        std::cout << "¿Cuántas canciones tiene el album? : ";
        std::cin >> num_canciones;
        std::cin.ignore();

        for (int j = 0; j < num_canciones; j++)
        {
            std::string nombre_cancion;
            std::cout << "Ingrese el nombre de la cancion #" << (j + 1) << ": ";
            std::getline(std::cin, nombre_cancion);

            datos.album.canciones.push_back({j + 1, nombre_cancion});
        }

        
    }

    //vector_cantante.push_back(datos);

    return datos;
}

void ImprimirDatos(std::vector<DatosCantante> vector_cantante)
{

    for (auto cantante : vector_cantante)
    {
        std ::cout << "----------Datos del Cantante----------------" << std::endl;
        std ::cout << "Nombre: " << cantante.nombre_cantante << std::endl;
        std ::cout << "Nacionalidad: " << cantante.nacionalidad_cantante << std::endl;
        std ::cout << "Nombre del album: " << cantante.album.nombre_del_album << std::endl;
        std ::cout << "Año de lanzamiento: " << cantante.album.ano_de_lanzamiento << std::endl;

        for (auto cancion : cantante.album.canciones)
        {
            std ::cout << "#" << cancion.first << " -  " << cancion.second << std::endl;
        }
    }
}

int CalcularAntiguedad(std::vector<DatosCantante> vector_cantante)
{
    return 2025 - datos.album.ano_de_lanzamiento;
}