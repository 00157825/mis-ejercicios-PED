#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

struct DatosCantante SolicitarDatos();
void ImprimirDatos(struct DatosCantante datos);
int CalcularAntiguedad(struct DatosCantante datos);

struct InformacionAlbum
{
    std ::string nombre_del_album;
    int ano_de_lanzamiento;
    std ::vector<std ::pair<int, std::string>> canciones;
    int edad_album;

} inf_album;

struct DatosCantante
{
    std ::string nombre_cantante, nacionalidad_cantante;
    InformacionAlbum album;
} datos;

int main()
{
    DatosCantante cantante = SolicitarDatos();
    ImprimirDatos(cantante);

    std ::cout << "Edad del album: " << CalcularAntiguedad(cantante) << " años" << std::endl;

    return 0;
}

struct DatosCantante SolicitarDatos()
{

    DatosCantante datos;
    int num_canciones;
    std ::cout << "Ingrese el nombre del cantante: ";
    std ::cin >> datos.nombre_cantante;
    std ::cout << "\n";

    std ::cout << "Ingrese la nacionalidad del cantante: ";
    std ::cin >> datos.nacionalidad_cantante;
    std ::cout << "\n";

    std ::cout << "Nombre del Album: ";
    std ::cin.ignore();
    std ::getline(std::cin, datos.album.nombre_del_album);
    std ::cout << "\n";

    std ::cout << "Año de lanzamiento: ";
    std ::cin >> datos.album.ano_de_lanzamiento;
    std ::cout << "\n";

    std ::cout << "¿Cuantas canciones tiene el album? :";
    std ::cin >> num_canciones;

    for (int i = 0; i < num_canciones; i++)
    {
        std ::string nombre_cancion;
        std ::cout << "Ingrese el nombre de la cancion #" << (i + 1) << ": ";
        std ::cin.ignore();
        std ::getline(std::cin, nombre_cancion);

        datos.album.canciones.push_back({i + 1, nombre_cancion});
    }

    return datos;
}

void ImprimirDatos(struct DatosCantante datos)
{
    std ::cout << "----------Datos del Cantante----------------" << std::endl;
    std ::cout << "Nombre: " << datos.nombre_cantante << std::endl;
    std ::cout << "Nacionalidad: " << datos.nacionalidad_cantante << std::endl;
    std ::cout << "Nombre del album: " << datos.album.nombre_del_album << std::endl;
    std ::cout << "Año de lanzamiento: " << datos.album.ano_de_lanzamiento << std::endl;

    for (auto cancion : datos.album.canciones)
    {
        std ::cout << "#" << cancion.first << " -  " << cancion.second << std::endl;
    }
}

int CalcularAntiguedad(struct DatosCantante datos)
{
    datos.album.edad_album = 2025 - datos.album.ano_de_lanzamiento;

    return datos.album.edad_album;
}