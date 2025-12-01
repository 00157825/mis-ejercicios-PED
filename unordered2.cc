#include <iostream>
#include <unordered_map>
#include <string>

struct Videojuego
{
    std::string titulo;
    std::string categoria;
    int anio_lanzamiento;
};

Videojuego SolicitarDatos();
void Imprimir(const std::unordered_map<std::string, Videojuego> &db);
void Buscar(const std::unordered_map<std::string, Videojuego> &db, std::string id);
void Actualizar(std::unordered_map<std::string, Videojuego> &db, std::string id);
void Eliminar(std::unordered_map<std::string, Videojuego> &db, std::string id);
void FiltrarPorCategoria(const std::unordered_map<std::string, Videojuego> &db, std::string categoria);

int main()
{
    std::unordered_map<std::string, Videojuego> juegos;
    int opc;

    do {
        std::cout << "\n===== COLECCIÓN DE VIDEOJUEGOS =====\n";
        std::cout << "1. Agregar videojuego\n";
        std::cout << "2. Mostrar todos los videojuegos\n";
        std::cout << "3. Buscar videojuego por ID\n";
        std::cout << "4. Actualizar videojuego por ID\n";
        std::cout << "5. Eliminar videojuego por ID\n";
        std::cout << "6. Contar videojuegos almacenados\n";
        std::cout << "7. Mostrar videojuegos por categoría\n";
        std::cout << "8. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opc;

        switch (opc)
        {
        case 1: {
            std::string id;
            std::cout << "\nIngrese el ID del videojuego: ";
            std::cin.ignore();
            getline(std::cin, id);

            Videojuego v = SolicitarDatos();
            juegos.emplace(id, v);
            std::cout << "\n✔ Videojuego agregado correctamente.\n";
            break;
        }
        case 2:
            Imprimir(juegos);
            break;

        case 3: {
            std::string id;
            std::cin.ignore();
            std::cout << "Ingrese el ID a buscar: ";
            getline(std::cin, id);
            Buscar(juegos, id);
            break;
        }

        case 4: {
            std::string id;
            std::cin.ignore();
            std::cout << "Ingrese el ID a actualizar: ";
            getline(std::cin, id);
            Actualizar(juegos, id);
            break;
        }

        case 5: {
            std::string id;
            std::cin.ignore();
            std::cout << "Ingrese el ID a eliminar: ";
            getline(std::cin, id);
            Eliminar(juegos, id);
            break;
        }

        case 6:
            std::cout << "\nTotal de videojuegos almacenados: " << juegos.size() << "\n";
            break;

        case 7: {
            std::string categoria;
            std::cin.ignore();
            std::cout << "Ingrese la categoría a filtrar (ej. Acción, RPG, Aventura): ";
            getline(std::cin, categoria);
            FiltrarPorCategoria(juegos, categoria);
            break;
        }

        case 8:
            std::cout << "\nSaliendo...\n";
            break;

        default:
            std::cout << "\n⚠ Opción inválida. Intente de nuevo.\n";
        }

    } while (opc != 8);

    return 0;
}

Videojuego SolicitarDatos()
{
    Videojuego vg;
    std::cin.ignore();
    std::cout << "Ingrese el título del videojuego: ";
    getline(std::cin, vg.titulo);

    std::cout << "Ingrese la categoría del videojuego: ";
    getline(std::cin, vg.categoria);

    std::cout << "Ingrese el año de lanzamiento: ";
    std::cin >> vg.anio_lanzamiento;

    return vg;
}

void Imprimir(const std::unordered_map<std::string, Videojuego> &db)
{
    if (db.empty()) {
        std::cout << "\nNo hay videojuegos registrados.\n";
        return;
    }

    std::cout << "\n===== LISTA DE VIDEOJUEGOS =====\n";

    for (auto &par : db)
    {
        std::cout << "\nID: " << par.first
                  << "\nTítulo: " << par.second.titulo
                  << "\nCategoría: " << par.second.categoria
                  << "\nAño de lanzamiento: " << par.second.anio_lanzamiento
                  << "\n";
    }
}

void Buscar(const std::unordered_map<std::string, Videojuego> &db, std::string id)
{
    auto it = db.find(id);

    if (it != db.end()) {
        std::cout << "\n✔ Videojuego encontrado:\n";
        std::cout << "Título: " << it->second.titulo << "\n";
        std::cout << "Categoría: " << it->second.categoria << "\n";
        std::cout << "Año: " << it->second.anio_lanzamiento << "\n";
    }
    else {
        std::cout << "\n❌ No se encontró un videojuego con ese ID.\n";
    }
}

void Actualizar(std::unordered_map<std::string, Videojuego> &db, std::string id)
{
    auto it = db.find(id);

    if (it == db.end()) {
        std::cout << "\n❌ No existe ese ID, no se puede actualizar.\n";
        return;
    }

    std::cout << "\nIngrese los nuevos datos:\n";
    it->second = SolicitarDatos();
    std::cout << "\n✔ Actualización completada.\n";
}

void Eliminar(std::unordered_map<std::string, Videojuego> &db, std::string id)
{
    size_t eliminado = db.erase(id);

    if (eliminado > 0)
        std::cout << "\n✔ Videojuego eliminado con éxito.\n";
    else
        std::cout << "\n❌ No existe ese ID, no se pudo eliminar.\n";
}

void FiltrarPorCategoria(const std::unordered_map<std::string, Videojuego> &db, std::string categoria)
{
    bool encontrado = false;

    for (auto &item : db)
    {
        if (item.second.categoria == categoria)
        {
            if (!encontrado) {
                std::cout << "\n===== VIDEOJUEGOS EN CATEGORÍA: " << categoria << " =====\n";
                encontrado = true;
            }

            std::cout << "\nTítulo: " << item.second.titulo
                      << "\nID: " << item.first
                      << "\nAño: " << item.second.anio_lanzamiento << "\n";
        }
    }

    if (!encontrado) {
        std::cout << "\n❌ No hay videojuegos registrados en esa categoría.\n";
    }
}