#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

void SolicitarDatos();

struct InformacionAlbum
{
    std ::string nombre_del_album;
    int año_de_lanzamiento;
    std ::vector<std ::pair<int, std::string>> canciones;
    int edad_album = 2025 - año_de_lanzamiento;

} inf_album;

struct DatosCantante
{
    std ::string nombre_cantante, nacionalidad_cantante;
    InformacionAlbum album;
} datos;

int main()
{
    

    inf_album.canciones.push_back({});

    return 0;
}

void SolicitarDatos()
{
    int num_canciones;
    std ::cout << "Ingrese el nombre del cantante: ";
    std ::cin >> datos.nombre_cantante;
    std ::cout << "/n";

    std ::cout << "Ingrese la nacionalidad del cantante: ";
    std ::cin >> datos.nacionalidad_cantante;
    std ::cout << "/n";

    std ::cout << "Nombre del Album: ";
    std ::cin.ignore();
    std ::getline(std:: cin, datos.album.nombre_del_album);
    std ::cout << "/n";

    std ::cout << "Año de lanzamiento: ";
    std ::cin >> datos.album.año_de_lanzamiento;
    std ::cout << "/n";

    std ::cout << "¿Cuantas canciones tiene el album? :";
    std ::cin >> num_canciones;
    

    for (int i = 0; i < num_canciones; i++)
    {
        std :: string nombre_cancion;
        std :: cout << "Ingrese el nombre de la cancion #"<<(i+1) << ": ";
        std ::cin.ignore();
        std ::getline(std:: cin, nombre_cancion);

        datos.album.canciones.push_back({ i, nombre_cancion});
    }
}