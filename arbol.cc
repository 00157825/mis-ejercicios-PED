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

Nodo *BuscarMenor(Nodo *abb);

Nodo *BuscarMayor(Nodo *abb);

void buscar_nodo(Nodo *&abb, float puntaje_busqueda, Nodo *&padre);

void BorrarNodo(Nodo *&abb, float puntaje_buscado);

struct Tiobe SolicitarInformacion();

int main()
{
    int opc;
    struct Nodo *abb = nullptr;
    do
    {
        Tiobe indice_tiobe = SolicitarInformacion();
        crear_nodo(indice_tiobe);
        insertar_nodo(abb, indice_tiobe);

        std::cout << "¿Desea agregar otro dato? \n 1. Si \n 2. No\n";
        std::cin >> opc;

    } while (opc == 1);

    RecorridoInorden(abb);
    BorrarNodo(abb, 15);

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
    // comparativa con la raiz ABB

    if (indice.puntaje < abb->indice_tiobe.puntaje)
        insertar_nodo(abb->izquierdo, indice);
    else
        insertar_nodo(abb->derecho, indice);
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

void buscar_nodo(Nodo *&abb, float puntaje_busqueda, Nodo *&padre)
{
    while (abb != nullptr && abb->indice_tiobe.puntaje != puntaje_busqueda)
    {
        padre = abb;
        if (puntaje_busqueda < abb->indice_tiobe.puntaje)
            abb = abb->izquierdo;
        else
            abb = abb->derecho;
    }
}

Nodo *BuscarMenor(Nodo *abb)
{
    while (abb && abb->izquierdo != nullptr)
        abb = abb->izquierdo;
    return abb;
}

Nodo *BuscarMayor(Nodo *abb)
{
    while (abb && abb->derecho != nullptr)
    {
        abb = abb->derecho;
    }
    return abb;
}

// Borrar un nodo
void BorrarNodo(Nodo *&abb, float puntaje_buscado)
{
    Nodo *padre = nullptr;
    Nodo *aux = abb;
    buscar_nodo(aux, puntaje_buscado, padre);
    // Si es nulo
    if (!aux)
        return;

    // Si es un nodo hoja
    if (!aux->izquierdo && !aux->derecho)
    {
        if (aux == abb)
            abb = nullptr;
        else if (padre->izquierdo == aux)
            padre->izquierdo = nullptr;
        else
            padre->derecho = nullptr;
        delete aux;
    }
    // Si es un nodo con dos hijos
    else if (aux->izquierdo && aux->derecho)
    {
        Nodo *predecesor = BuscarMayor(aux->derecho);
        aux->indice_tiobe = predecesor->indice_tiobe;
        BorrarNodo(aux->derecho, predecesor->indice_tiobe.puntaje);
    }
    // Si es un nodo con un solo hijo
    else
    {
        Nodo *hijo = ((aux->izquierdo) ? aux->izquierdo : aux->derecho);
        if (aux != abb)
        {
            if (aux == padre->izquierdo)
                padre->izquierdo = hijo;
            else
                padre->derecho = hijo;
        }
        else
            abb = hijo;
        delete aux;
    }
}