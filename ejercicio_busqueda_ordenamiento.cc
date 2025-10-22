#include <iostream>
#include <vector>
#include <algorithm>

struct Luchador
{
    std::string nombre;
    float peso;
};

std::vector<struct Luchador> luchadores;
struct Luchador SolicitarDatos();

bool CompararPorPeso(const Luchador &l1, const Luchador &l2)
              { return l1.peso > l2.peso; }

void BuscarPorNombre(std::vector<Luchador> luchador_vector, std::string nombre_buscado )
{
    auto it = std::find_if(luchador_vector.begin(), luchador_vector.end(),
                            [nombre_buscado](const Luchador &luchador)
                            {return luchador.nombre == nombre_buscado;});

    if (it != luchador_vector.end())
    {
        std::cout << "Luchador encontrado: "<<it->nombre<<"con peso de: "<<it->peso<<" libras. \n";
    }
    
    else
    {
        std::cout << "Luchador no encontrado";
    }
}
int main()
{
    float peso_buscado;
    Luchador luchador;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "#" << i + 1 << "\n";
        luchador = SolicitarDatos();
        luchadores.push_back(luchador);
    }

    std::sort(luchadores.begin(), luchadores.end(), CompararPorPeso);

    for (auto l : luchadores)
    {
        std::cout << "Luchador: " << l.nombre << " --- peso lbs: " << l.peso << "\n";
    }

    std::cout << "Ingrese el peso en libras a buscar \n";
    std::cin >> peso_buscado;
    bool busqueda = std::binary_search(luchadores.begin(), luchadores.end(), Luchador{"", peso_buscado}, CompararPorPeso);

    if (busqueda)
    {
        std::cout<<"Peso encontrado \n";
    }
    else{
        std::cout<<"Peso no encontrado \n";
    }

    return 0;
}

struct Luchador SolicitarDatos()
{
    struct Luchador luchador;
    std::cin.ignore();
    std::cout << "Ingrese el nombre del luchador \n";
    getline(std::cin, luchador.nombre);
    std::cout << "Ingrese el peso en libras del luchador \n";
    std::cin >> luchador.peso;
    return luchador;
}