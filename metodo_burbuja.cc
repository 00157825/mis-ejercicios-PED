#include <iostream>

void OrdenarBurbuja(float arreglo_estaturas[], int n);
void ImprimirArregloEstaturas(float arreglo_estaturas[], int n);

int main()
{
    std::cout << "Ingrese cuantas estaturas va a ingresar"<<std::endl;

    int num_datos;
    
    std::cin >> num_datos;

    float arreglo_estaturas[num_datos];

    for (int i = 0; i < num_datos; i++)
    {
        std::cout << "Ingrese la estura #"<<(i+1)<<" (en centimetros): ";
        std::cin >> arreglo_estaturas[i];
    }
    
    int n = sizeof(arreglo_estaturas) / sizeof(arreglo_estaturas[0]);

    std::cout << "Estaturas sin ordenar: ";
    ImprimirArregloEstaturas(arreglo_estaturas, n);

    // Ordenamos el arreglo_estaturas usando el método burbuja
    OrdenarBurbuja(arreglo_estaturas, n);

    std::cout << "Estaturas ordenadas: ";
    ImprimirArregloEstaturas(arreglo_estaturas, n);

    return 0;
}

// Función para realizar el ordenamiento por burbuja
void OrdenarBurbuja(float arreglo_estaturas[], int n)
{
    // Contador para el número de pasos realizados
    int pasos = 0;
    // Contador de intercambios
    int intercambios = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // Incrementamos el contador de pasos en cada comparación
            pasos++;
            // Si el elemento actual es mayor que el siguiente, los intercambiamos
            if (arreglo_estaturas[j] < arreglo_estaturas[j + 1])
            {
                // Intercambio de elementos
                int temp = arreglo_estaturas[j];
                arreglo_estaturas[j] = arreglo_estaturas[j + 1];
                arreglo_estaturas[j + 1] = temp;
                // Incrementamos el contador de intercambios
                intercambios++;
            }
        }
    }
    std::cout << "Numero total de pasos: " << pasos << std::endl;
    std::cout << "Numero total de intercambios: " << intercambios << std::endl;
}

// Función para imprimir el arreglo_estaturaseglo
void ImprimirArregloEstaturas(float arreglo_estaturas[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arreglo_estaturas[i] << " ";
    }
    std::cout << std::endl;
}
