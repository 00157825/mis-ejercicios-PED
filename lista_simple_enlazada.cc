#include <iostream>

struct Datos
{
    int numero;
};

struct Nodo
{
    struct Datos datos;

    struct Nodo *siguiente;
};

struct Nodo *inicio_lista = nullptr;

void InsertarInicio(int n);
void Imprimir();
void InsertarFinal(int n);
void EliminarInicio();

int main()
{

    InsertarInicio(40);
    InsertarInicio(80);
    InsertarInicio(100);
    Imprimir();
    /* std ::cout << "Dir Memoria: " << inicio_lista << " Numero: " << inicio_lista->datos.numero << std::endl;

     std :: cout << "Dir Memoria: "<<inicio_lista->siguiente->siguiente<< " Numero: "<<inicio_lista->siguiente->siguiente->datos.numero;

     return 0; */
}

void InsertarInicio(int n)
{
    // Reserva de memoria
    struct Nodo *nuevo_nodo = new Nodo;

    nuevo_nodo->datos.numero = n;

    nuevo_nodo->siguiente = nullptr;

    // Si la lista esta vacia se agrega el primer n

    if (inicio_lista == nullptr)
    {
        inicio_lista = nuevo_nodo;
    }

    else
    {
        nuevo_nodo->siguiente = inicio_lista;

        inicio_lista = nuevo_nodo;
    }
}

void InsertarFinal(int n)
{
    struct Nodo *nuevo_nodo = new Nodo;
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = inicio_lista;
    nuevo_nodo->datos.numero = n;
    nuevo_nodo->siguiente = nullptr;

    // Si la lista esta vacia se agrega el primer nodo
    if (inicio_lista == nullptr)
    {
        inicio_lista = nuevo_nodo;
    }
    else
    {
        // Agregar un nodo al final
        while (temporal->siguiente != nullptr)
        {
            temporal = temporal->siguiente;
        }
        temporal->siguiente = nuevo_nodo;
    }
}

void Imprimir()
{
    struct Nodo *temporal = inicio_lista;

    if (inicio_lista != nullptr)
    {
        while (temporal != nullptr)
        {
            std ::cout << "\n Valores de la lista: " << temporal->datos.numero
                       << " \n Direccion: " << temporal
                       << " \n Dir nodo siguiente: " << temporal->siguiente;

            temporal = temporal->siguiente;
        }
    }
}

void EliminarInicio()
{
    struct Nodo *temporal = inicio_lista;

    if (inicio_lista != nullptr)
    {
        inicio_lista = temporal->siguiente;

        delete temporal;

        temporal = nullptr;
    }
}

void EliminarFinal()
{
    struct Nodo *temporal = inicio_lista;
    struct Nodo *temporal2 = inicio_lista;

    if (inicio_lista != nullptr)
    {
        if (temporal->siguiente != nullptr)
        {
            while (temporal->siguiente != nullptr)
            {
                temporal2 = temporal;
                temporal = temporal->siguiente;
            }

            temporal2->siguiente = nullptr;

            delete temporal;
        }
    }
}