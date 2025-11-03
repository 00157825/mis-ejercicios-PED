#include <iostream>

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

Nodo *crear_nodo(const Tiobe &indice);

void insertar_nodo(Nodo *&abb, const Tiobe &indice);

void RecorridoInorden(Nodo *abb);

struct Tiobe SolicitarInformacion();

int main()
{
    struct Nodo *abb = nullptr;
    Tiobe informacion = SolicitarInformacion();
    crear_nodo(informacion);
    insertar_nodo(abb, informacion);
    RecorridoInorden(abb);

    return 0;
}

Nodo *crear_nodo(const Tiobe &indice)
{
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->indice_tiobe = indice;
    nuevo_nodo->izquierdo = nullptr;
    nuevo_nodo->derecho = nullptr;
    return nuevo_nodo;
}

void insertar_nodo(Nodo *&abb, const Tiobe &indice)
{
    if (abb == nullptr)
    {
        abb = crear_nodo(indice);
        return;
    }
    //comparativa con la raiz ABB

    if (indice.puntaje < abb->indice_tiobe.puntaje)
        insertar_nodo(abb->izquierdo, indice);
    else
        insertar_nodo(abb->derecho, indice);
}

struct Tiobe SolicitarInformacion()
{
    struct Tiobe informacion_indice;
    std::cin.ignore();
    std::cout << "Ingrese el lenguaje de programacion: ";
    getline(std::cin, informacion_indice.lenguaje_programacion);

    std::cout<<"\nIngrese su puntuaje en el tiobe: ";
    std::cin >> informacion_indice.puntaje;

    return informacion_indice;
}

void RecorridoInorden(Nodo *abb)
{
    // Si el arbol es nulo
    if (!abb)
        return;
    // Si no es nulo
    RecorridoInorden(abb->izquierdo);
    std::cout << "[" << abb->indice_tiobe.puntaje << " : " << abb->indice_tiobe.lenguaje_programacion << "] ";
    RecorridoInorden(abb->derecho);
}