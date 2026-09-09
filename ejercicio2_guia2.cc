#include <iostream>

struct Producto
{
    double precio;
    int cantidad;
};

int PrecioTotal(Producto *prod);

int main()
{

    Producto prod = {60.00, 25};

    std::cout << "Antes de modificar: Precio = " << prod.precio << ", Cantidad = " << prod.cantidad << std::endl;

    int total = PrecioTotal(&prod);

    std::cout << "Después de modificar: Precio = " << prod.precio << ", Cantidad = " << prod.cantidad << std::endl;
    std::cout << "Precio total calculado: " << total << std::endl;

    return 0;
}

int PrecioTotal(Producto *prod)
{
    const int limite = 20;
    const double nuevo_precio = 50.00;

    if (prod->cantidad > limite)
    {
        prod->precio = nuevo_precio;
    }

    return prod->precio * prod->cantidad;
}
