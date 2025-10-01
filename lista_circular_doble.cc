#include <iostream>

struct Datos
{
    int elemento;
};

struct Nodo
{
    struct Datos datos;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};

void InsertarInicio(Nodo *&lista, int n);
void InsertarFinal(Nodo *&lista, int n);
void Imprimir(Nodo *&lista);


int main()
{

    return 0;
}

void InsertarInicio(Nodo *&lista, int n)
{
    Nodo* nuevo_nodo = new Nodo;

    nuevo_nodo->datos.elemento = n;

    if (lista == nullptr)
    {
        nuevo_nodo->anterior = lista;
        nuevo_nodo->siguiente = lista;
        lista = nuevo_nodo;
    }
    
    else
    {
        Nodo* ultimo = lista->anterior;
        nuevo_nodo->siguiente = lista;
        nuevo_nodo->anterior = ultimo;

        lista->anterior = nuevo_nodo;
        ultimo->siguiente = nuevo_nodo;
        lista = nuevo_nodo;
    }
}

void InsertarFinal(Nodo *&lista, int n)
{
    Nodo* nuevo_nodo = new Nodo;
    nuevo_nodo->datos.elemento = n;

    if (lista == nullptr)
    {
        nuevo_nodo->anterior = nuevo_nodo;
        nuevo_nodo->siguiente = nuevo_nodo;
        lista = nuevo_nodo;

    }
    else
    {
        Nodo* ultimo = lista->anterior;
        nuevo_nodo->siguiente = lista;
        nuevo_nodo->anterior = ultimo;
        ultimo->siguiente = nuevo_nodo;
        lista->anterior = nuevo_nodo;
    }
}

void Imprimir(Nodo *&lista)
{
    if (lista != nullptr)
    {
        /* code */
    }

    else
    {
        std :: cout << "La lista esta vacia"<<std::endl;
    }
    

}