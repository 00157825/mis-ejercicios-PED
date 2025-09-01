#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

struct InformacionAlbum
{
    std :: string nombre_del_album;
    int año_de_lanzamiento;
    std :: vector < std :: pair < std :: string , int>> canciones;
    int edad_album;
};

struct DatosCantante
{
    std :: string nombre_cantante, nacionalidad_cantante;
    InformacionAlbum album;
};

int main()
{

    return 0;
}