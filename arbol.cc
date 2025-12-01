#include <iostream>
#include <string>
#include <set>

struct Tiobe
{
    std::string lenguaje_programacion;
    float puntaje;
};

struct Nodo
{
    struct Tiobe indice_tiobe;

    struct Nodo *izquierdo;
    struct Nodo *derecho;
};

struct Tiobe SolicitarInformacion();

struct CompTiobe {
    bool operator()(const Tiobe& a, const Tiobe& b) const {
        return a.puntaje < b.puntaje;
    }

};

void Imprimir(const std::set<Tiobe , CompTiobe> &abb);

void BuscarLenguaje(const std::set<Tiobe , CompTiobe> &abb, std::string lenguaje_buscado);

int main()
{
    std::set<Tiobe, CompTiobe> ABB;
    int opc;
    do
    {
        Tiobe indice_tiobe = SolicitarInformacion();
        ABB.insert(indice_tiobe);

        std::cout << "¿Desea agregar otro dato? \n 1. Si \n 2. No\n";
        std::cin >> opc;

    } while (opc == 1);

    Imprimir(ABB);
    
    return 0;

}

struct Tiobe SolicitarInformacion()
{
    struct Tiobe indice_tiobe;
    std::cin.ignore();
    std::cout << "Ingrese el lenguaje de programacion: ";
    getline(std::cin, indice_tiobe.lenguaje_programacion);

    std::cout << "\nIngrese su puntuaje en el tiobe: ";
    std::cin >> indice_tiobe.puntaje;

    return indice_tiobe;
}

void Imprimir(const std::set<Tiobe , CompTiobe> &abb)
{
    if (abb.empty())
    {
        std::cout << "\nEl árbol está vacío.\n";
        return;
    }

    for (auto indice : abb)
    {
        std::cout << "[" << indice.puntaje << " : " << indice.lenguaje_programacion << "] ";
        std::cout << "\n";
    }
    std::cout << "\n";
}

void BuscarLenguaje(const std::set<Tiobe , CompTiobe> &abb, std::string lenguaje_buscado)
{
    if (abb.empty()){
    std::cout << "El set esta vacio \n";
   }
   auto it = abb.find({lenguaje_buscado, 0});
   if(it != abb.end())
   {
    std::cout << "Lenguaje de programacion " ;
   }
}