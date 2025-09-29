#include <iostream>

struct Datos
{
    int numero;
};


struct Nodo
{
    struct Datos datos;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};

void InsertarInicio(struct Nodo **lista, int n);
void InsertarFinal(struct Nodo **lista, int n);
void InsertarIntermedio(struct Nodo **lista, int n);
void Imprimir(struct Nodo **lista);


int main(int argc, char *argv[])
{
    struct Nodo *lista = nullptr;
    InsertarInicio(&lista, 100);
    InsertarInicio(&lista, 7);
    InsertarInicio(&lista, 17);

    std :: cout << "Dir de memoria 17: "<<lista << "\nDir memoria siguiente: "<<lista->siguiente<< "\nDir memoria anterior: "<<lista->anterior<<std::endl;
    std :: cout << "Valor: "<<lista->datos.numero;

    std :: cout << "Dir de memoria 100: "<<lista->siguiente->siguiente << "\nDir memoria siguiente: "<<lista->siguiente->siguiente->siguiente<< "\nDir memoria anterior: "<<lista->siguiente->siguiente->anterior<<std::endl;
    std :: cout << "Valor: "<<lista->siguiente->siguiente->datos.numero;


    return 0;
}

void InsertarInicio(struct Nodo **lista, int n)
{
    struct Nodo *nuevoNodo = new Nodo;

    nuevoNodo->datos.numero = n;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    if (*lista = nullptr)
    {
        *lista = nuevoNodo;
    }

    else
    {
        //conexion con el nuevo nodo de la lista
        nuevoNodo->siguiente = *lista;
        (*lista)->anterior = nuevoNodo;

        //asignar el nuevonodo a la cabeza de la lista
        *lista = nuevoNodo;
    }
    
}
