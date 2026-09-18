#include <iostream>
#include <string>

struct Elemento
{
    std::string codigo;
    std::string nombre_del_elemento;
    double longitud;
    float cargas[3];
    float capacidad_max;
    float factor_utilización;
    std::string estado_seguro;
};

void registrarElemento(Elemento &elemento);
float calcularFactor(Elemento *elemento);
void determinarSeguridad(Elemento &elemento);
Elemento *obtenerElementoCritico(Elemento elementos[], int cantidad);
void aumentarCargas(Elemento &elemento, float porcentaje);
void generarInforme(Elemento elementos[], int cantidad);

int main()
{
    Elemento elementos[10]; // capacidad máxima fija en 10
    int cantidad;

    do
    {
        std::cout << "¿Cuántos elementos desea registrar? (1-10): ";
        std::cin >> cantidad;

        if (cantidad < 1 || cantidad > 10)
        {
            std::cout << "Cantidad inválida. Debe estar entre 1 y 10." << std::endl;
        }

    } while (cantidad < 1 || cantidad > 10);

    std::cin.ignore(); // limpia el \n antes del primer getline en registrarElemento

    for (int i = 0; i < cantidad; i++)
    {
        std::cout << "--- Registrando elemento " << (i + 1) << " ---" << std::endl;
        registrarElemento(elementos[i]);
        calcularFactor(&elementos[i]);
        determinarSeguridad(elementos[i]);
    }

    std::cout << std::endl << "===== INFORME GENERAL =====" << std::endl;
    generarInforme(elementos, cantidad);

    Elemento *critico = obtenerElementoCritico(elementos, cantidad);
    std::cout << std::endl << "El elemento más crítico es: " << critico->codigo
              << " (" << critico->nombre_del_elemento << ")" << std::endl;

    std::cout << std::endl << "--- Aumentando cargas del elemento crítico en 10% ---" << std::endl;
    aumentarCargas(*critico, 10);

    std::cout << std::endl << "===== INFORME DESPUÉS DEL AUMENTO =====" << std::endl;
    generarInforme(elementos, cantidad);

    return 0;
}

void registrarElemento(Elemento &elemento)
{

    std::cout << "Ingrese el código del elemento (2 letras y 2 números ej. AB12): ";
    getline(std::cin, elemento.codigo);
    std::cout << std::endl;

    std::cout << "Ingrese el nombre del elemento: ";
    getline(std::cin, elemento.nombre_del_elemento);
    std::cout << std::endl;

    std::cout << "Ingrese la longitud del elemento: ";
    std::cin >> elemento.longitud;
    std::cout << std::endl;

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Ingrese la carga #" << (i + 1) << ": ";
        std::cin >> elemento.cargas[i];
        std::cout << std::endl;
    }

    std::cout << "Ingrese la capacidad maxima: ";
    std::cin >> elemento.capacidad_max;
    std::cout << std::endl;

    std::cin.ignore();
}

float calcularFactor(Elemento *elemento)
{

    float suma = 0;
    for (int i = 0; i < 3; i++)
    {
        suma += elemento->cargas[i];
    }

    float promedio = suma / 3;

    elemento->factor_utilización = promedio / elemento->capacidad_max;

    return elemento->factor_utilización;
}

void determinarSeguridad(Elemento &elemento)
{

    if (elemento.factor_utilización <= 0.50 && elemento.factor_utilización >= 0.0)
    {
        elemento.estado_seguro = "SEGURO";
    }

    else if (elemento.factor_utilización <= 0.80 && elemento.factor_utilización > 0.50)
    {
        elemento.estado_seguro = "PRECAUCIÓN";
    }

    else if (elemento.factor_utilización <= 1.0 && elemento.factor_utilización > 0.80)
    {
        elemento.estado_seguro = "RIESGO";
    }

    else if (elemento.factor_utilización > 1.0)
    {
        elemento.estado_seguro = "SOBRECARGA";
    }
}

Elemento *obtenerElementoCritico(Elemento elementos[], int cantidad)
{

    Elemento *critico = &elementos[0]; // asumimos que el primero es el más crítico

    for (int i = 1; i < cantidad; i++)
    {
        if (elementos[i].factor_utilización > critico->factor_utilización)
        {
            critico = &elementos[i]; // encontramos uno peor (más crítico), actualizamos
        }
    }

    return critico;
}

void aumentarCargas(Elemento &elemento, float porcentaje)
{

    for (int i = 0; i < 3; i++)
    {
        float nueva_carga = elemento.cargas[i] * (1 + porcentaje / 100);
        elemento.cargas[i] = nueva_carga;
    }

    calcularFactor(&elemento);
    determinarSeguridad(elemento);
}

void generarInforme(Elemento elementos[], int cantidad)
{

    int contadorSeguro = 0;
    int contadorPrecaucion = 0;
    int contadorRiesgo = 0;
    int contadorSobrecarga = 0;
    float sumaFactores = 0;

    for (int i = 0; i < cantidad; i++)
    {
        float promedio = elementos[i].factor_utilización * elementos[i].capacidad_max;

        std::cout << "Codigo: " << (elementos[i].codigo) << std::endl;
        std::cout << "Nombre: " << (elementos[i].nombre_del_elemento) << std::endl;
        std::cout << "Carga Promedio: " << promedio << std::endl;
        std::cout << "Factor de utilización: " << (elementos[i].factor_utilización) << std::endl;
        std::cout << "Estado de seguridad: " << (elementos[i].estado_seguro) << std::endl;

        sumaFactores += elementos[i].factor_utilización;

        if (elementos[i].estado_seguro == "SEGURO")
            contadorSeguro++;
        else if (elementos[i].estado_seguro == "PRECAUCIÓN")
            contadorPrecaucion++;
        else if (elementos[i].estado_seguro == "RIESGO")
            contadorRiesgo++;
        else if (elementos[i].estado_seguro == "SOBRECARGA")
            contadorSobrecarga++;
    }

    std::cout << std::endl
              << "Elementos SEGURO: " << contadorSeguro << std::endl;
    std::cout << "Elementos PRECAUCIÓN: " << contadorPrecaucion << std::endl;
    std::cout << "Elementos RIESGO: " << contadorRiesgo << std::endl;
    std::cout << "Elementos SOBRECARGA: " << contadorSobrecarga << std::endl;

    float factorPromedioGeneral = sumaFactores / cantidad;
    std::cout << "Factor de utilización promedio de toda la estructura: " << factorPromedioGeneral << std::endl;
}