#include <iostream>
#include <stack>
struct Datos
{
    int elemento;
};

struct Nodo
{
    struct Datos datos;
    struct Nodo *siguiente;
};

// Declarando funciones
void Insertar(struct Nodo *&pila, int n);
void Eliminar(struct Nodo *&pila);

// Porque el parametro de imprimir es puntero simple ?
void Imprimir(struct Nodo *pila);

// Es necesario el parametro si o no ?
// Si es si quien es el parametro ?
// Es necesario el uso de ** o *&, porque si o no?
bool Vacia(struct Nodo *pila);
void UltimoElemento(struct Nodo *pila);

// Un nodo tiene un dato, el cual es el elemento y  otro nodo al que apunta

int main(int argc, char *argv[])
{
    struct Nodo *pila = nullptr;
    int valor;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Ingrese un valor ";
        std::cin >> valor;
        Insertar(pila, valor);
    }
    std::cout << "------------------" << std::endl;
    Imprimir(pila);
    return 0;
}

// Operacion Push
void Insertar(struct Nodo *&pila, int n)
{
    // Reserva de memoria
    struct Nodo *nuevo_nodo = new Nodo;
    // almacenar el valor ingresado por el usuario
    nuevo_nodo->datos.elemento = n;
    // Ingresando el nuevo nodo a la pila
    nuevo_nodo->siguiente = pila;
    // Asignando que el valor ingresado esta en la cima de la pila
    pila = nuevo_nodo;
}

// Operación Pop
void Eliminar(struct Nodo *&pila)
{
    if (pila != nullptr)
    {
        struct Nodo *temporal = pila;
        // Asignación del nuevo valor que esta en la cima de la pila
        pila = temporal->siguiente;
        delete temporal;
    }
    else
    {
        std::cout << "Pila vacia /n";
    }
}

// Imprimir la pila
void Imprimir(struct Nodo *pila)
{
    struct Nodo *temporal = pila;
    while (temporal != nullptr)
    {
        std::cout << "Elementos de la pila " << temporal->datos.elemento
                  << "dir. memoria del nodo" << temporal
                  << " Dir memoria nodo sig " << temporal->siguiente << std::endl;

        temporal = temporal->siguiente;
    }
}

// Operacion Pila vacia
bool Vacia(struct Nodo *pila)
{
    if (pila != nullptr)
    {
        std ::cout << "La lista tiene datos" << std::endl;
    }

    else
    {
        std::cout << "La pila esta vacia\n";
    }
}

// Operación Top
void UltimoElemento(struct Nodo *pila)
{
    struct Nodo *temporal = pila;

    std::cout << "Ultimo Elemento:  " << temporal->datos.elemento;
}