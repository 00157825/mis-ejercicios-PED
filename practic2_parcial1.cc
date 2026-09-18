#include <iostream>
#include <string>

struct Producto {
    std::string codigo;
    std::string nombre;
    float ventas[3];       // ventas de 3 meses
    float precio_unitario;
    float venta_promedio;
    float ingreso_total;
    std::string nivel_rotacion;
};

void registrarProducto(Producto &p);
float calcularPromedio(Producto *p);
float calcularIngreso(Producto *p);
void determinarRotacion(Producto &p);
Producto* obtenerProductoTop(Producto productos[], int cantidad);
void aplicarDescuento(Producto &p, float porcentaje);
void generarInforme(Producto productos[], int cantidad);

int main() {

    int cantidad = 3;
    Producto productos[3];

    for (int i = 0; i < cantidad; i++) {
        std::cout << "--- Producto " << (i + 1) << " ---" << std::endl;
        registrarProducto(productos[i]);
        calcularIngreso(&productos[i]);
        determinarRotacion(productos[i]);
    }

    std::cout << std::endl << "===== INFORME GENERAL =====" << std::endl;
    generarInforme(productos, cantidad);

    Producto *top = obtenerProductoTop(productos, cantidad);
    std::cout << std::endl << "Producto con mayor ingreso: " << top->nombre << std::endl;

    std::cout << std::endl << "--- Aplicando 15% de descuento al producto top ---" << std::endl;
    aplicarDescuento(*top, 15);

    std::cout << std::endl << "===== INFORME DESPUES DEL DESCUENTO =====" << std::endl;
    generarInforme(productos, cantidad);

    return 0;
}

void registrarProducto(Producto &p) {

    std::cout << "Codigo: ";
    getline(std::cin, p.codigo);

    std::cout << "Nombre: ";
    getline(std::cin, p.nombre);

    for (int i = 0; i < 3; i++) {
        std::cout << "Ventas mes #" << (i + 1) << ": ";
        std::cin >> p.ventas[i];
    }

    std::cout << "Precio unitario: ";
    std::cin >> p.precio_unitario;

    std::cin.ignore(); // limpia el \n sobrante antes del proximo getline
}

float calcularPromedio(Producto *p) {
    float suma = 0;
    for (int i = 0; i < 3; i++) {
        suma += p->ventas[i];
    }
    return suma / 3;
}

float calcularIngreso(Producto *p) {

    p->venta_promedio = calcularPromedio(p);
    p->ingreso_total = p->venta_promedio * p->precio_unitario;

    return p->ingreso_total;
}

void determinarRotacion(Producto &p) {

    if (p.venta_promedio <= 10 && p.venta_promedio >= 0) {
        p.nivel_rotacion = "BAJA";
    }
    else if (p.venta_promedio <= 30 && p.venta_promedio > 10) {
        p.nivel_rotacion = "MEDIA";
    }
    else if (p.venta_promedio > 30) {
        p.nivel_rotacion = "ALTA";
    }
}

Producto* obtenerProductoTop(Producto productos[], int cantidad) {

    Producto *top = &productos[0];

    for (int i = 1; i < cantidad; i++) {
        if (productos[i].ingreso_total > top->ingreso_total) {
            top = &productos[i];
        }
    }

    return top;
}

void aplicarDescuento(Producto &p, float porcentaje) {

    p.precio_unitario = p.precio_unitario * (1 - porcentaje / 100);

    calcularIngreso(&p);
    determinarRotacion(p);
}

void generarInforme(Producto productos[], int cantidad) {

    int contadorBaja = 0, contadorMedia = 0, contadorAlta = 0;
    float sumaIngresos = 0;

    for (int i = 0; i < cantidad; i++) {

        std::cout << "Codigo: " << productos[i].codigo << std::endl;
        std::cout << "Nombre: " << productos[i].nombre << std::endl;
        std::cout << "Ingreso total: " << productos[i].ingreso_total << std::endl;
        std::cout << "Rotacion: " << productos[i].nivel_rotacion << std::endl;

        sumaIngresos += productos[i].ingreso_total;

        if (productos[i].nivel_rotacion == "BAJA") contadorBaja++;
        else if (productos[i].nivel_rotacion == "MEDIA") contadorMedia++;
        else if (productos[i].nivel_rotacion == "ALTA") contadorAlta++;
    }

    std::cout << std::endl << "Productos BAJA: " << contadorBaja << std::endl;
    std::cout << "Productos MEDIA: " << contadorMedia << std::endl;
    std::cout << "Productos ALTA: " << contadorAlta << std::endl;
    std::cout << "Ingreso promedio general: " << sumaIngresos / cantidad << std::endl;
}