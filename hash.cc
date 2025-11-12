#include <iostream>

#define dimension 7

struct Registro {

    std::string palabra;
    int dato;
};

struct Nodo {
    Registro registro;
    Nodo *anterior;
    Nodo *siguiente;
};

Nodo *tabla[dimension] = {nullptr};

void Agregar(std::string palabra);
int FHash(int);
int ConversionASCII(std::string palabra);
Nodo *Buscar(int, int);
void Buscar(int);
void Eliminar(int);
void Imprimir();

int main() {
  
    std::string palabra = "JOSE";

    int valor_ascii = ConversionASCII(palabra);

    std::cout<<"Valor ASCII: " <<valor_ascii<<"\n";
    std::cout<<"Valor de FHash: "<<FHash(valor_ascii);

    return 0;
}

int ConversionASCII(std::string palabra) {

    int total = 0;
    for (auto p: palabra)
    {
        total += static_cast<int>(p);
    }

    return total;
    
}

void Agregar(std::string palabra) {
    Nodo *nuevoNodo = new Nodo;
    Registro r;
    int clave = FHash(r.dato);

    nuevoNodo->registro = r;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->siguiente = tabla[clave];

    if (tabla[clave])
        tabla[clave]->anterior = nuevoNodo;

    tabla[clave] = nuevoNodo;

    std::cout << "Dir. nodo " << nuevoNodo
              << " | Indice: " << clave
              << " | Dato almacenado (ASCII): " << r.dato
              << " ('" << palabra << "')"
              << std::endl;
}

int FHash(int dato) {
    return dato % dimension;
}

Nodo *Buscar(int dato, int clave) {
    Nodo *actual = tabla[clave];
    while (actual) {
        if (actual->registro.dato == dato)
            return actual;
        actual = actual->siguiente;
    }
    return nullptr;
}

void Buscar(int dato) {
    int clave = FHash(dato);
    Nodo *nodo = Buscar(dato, clave);
    if (nodo) {
        std::cout << "Registro encontrado → Posicion: " << clave
                  << " | Valor ASCII: " << nodo->registro.dato
                  << " | Palabra: " << nodo->registro.palabra << "'"
                  << std::endl;
    } else {
        std::cout << "Registro no encontrado" << std::endl;
    }
}

void Eliminar(int dato) {
    int clave = FHash(dato);
    Nodo *nodo = Buscar(dato, clave);
    if (nodo) {
        std::cout << "Eliminando registro → Valor ASCII: "
                  << nodo->registro.dato
                  << "Palabra Eliminada: "<<nodo->registro.palabra
                  << std::endl;

        if (nodo->siguiente)
            nodo->siguiente->anterior = nodo->anterior;

        if (nodo->anterior)
            nodo->anterior->siguiente = nodo->siguiente;
        else
            tabla[clave] = nodo->siguiente;

        delete nodo;
    } else {
        std::cout << "Registro no encontrado" << std::endl;
    }
}

void Imprimir() {
    for (int i = 0; i < dimension; i++) {
        Nodo *temp = tabla[i];
        if (temp)
            std::cout << "\n[Índice " << i << "]\n";

        while (temp) {
            std::cout << "  Nodo: " << temp
                      << " | Anterior: " << temp->anterior
                      << " | Dato ASCII: " << temp->registro.dato
                      << " | Palabra: "<<temp->registro.palabra
                      << std::endl;
            temp = temp->siguiente;
        }
    }
}