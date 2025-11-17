#include <iostream>
#include <unordered_map>

struct Animal
{
    std::string nombre_cientifico;

    std::string nombre_comun;

    std::string genero;
};

Animal SolicitarDatos();
void Imprimir(const std::unordered_map<std::string, Animal> &umap);
void Buscar(const std::unordered_map<std::string, Animal> &umap, std::string nombre_cientifico);

int main()
{

    std::unordered_map<std::string, Animal> umap;
    Animal animales;
    int opc;


    do {
        std::cout << "\n======= MENU =======\n";
        std::cout << "1. Agregar animal\n";
        std::cout << "2. Mostrar todos los animales\n";
        std::cout << "3. Buscar animal por nombre científico\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opc;

        switch (opc) {

        case 1: {
            Animal animal = SolicitarDatos();
            umap.emplace(animal.nombre_cientifico, animal);
            std::cout << "\nAnimal agregado correctamente.\n";
            break;
        }

        case 2:
            Imprimir(umap);
            break;

        case 3:{
            std::string nombre_cient;

            std::cin.ignore();
            std::cout << "Ingrese el nombre cientifico a buscar: ";
            getline(std::cin,nombre_cient);

            Buscar(umap, nombre_cient);
            break;
        }

        case 4:
            std::cout << "Saliendo del programa...\n";
            break;

        default:
            std::cout << "Opción inválida. Intente nuevamente.\n";
        } 
        
    }while (opc != 4);

    return 0;

    } 
    


Animal SolicitarDatos()
{
    Animal animal;

    std::cout << "Ingrese el nombre cientifico del animal: ";
    std::cin.ignore();
    getline(std::cin, animal.nombre_cientifico);

    std::cout << "\nIngrese el nombre comun del animal: ";
    getline(std::cin, animal.nombre_comun);

    std::cout << "\n Ingrese el genero del animal: ";
    getline(std::cin, animal.genero);

    return animal;
}

void Imprimir(const std::unordered_map<std::string, Animal> &umap)
{
    auto hash = umap.hash_function();

    for (auto i : umap)
    {
        std::cout << "Clave: " << hash(i.first) << std::endl;
        std::cout << "Nombre cientifico: " << i.first << std::endl;
        std::cout << "Nombre comun: " << i.second.nombre_comun << std::endl;
        std::cout << "Genero: " << i.second.genero << std::endl;
    }
}

void Buscar(const std::unordered_map<std::string, Animal> &umap, std::string nombre_cientifico)
{
    if (umap.empty())
    {
        std::cout << "No hay animales en la lista\n";

        return;
    }

    auto it = umap.find(nombre_cientifico);

    if (it != umap.end())
    {

        std::cout << "Clave '" << nombre_cientifico << "' encontrada. \nValor: " << it->second.nombre_comun << std::endl;
    }

    else
    {
        std::cout << "Clave '" << nombre_cientifico << "' no encontrada." << std::endl;
    }
}