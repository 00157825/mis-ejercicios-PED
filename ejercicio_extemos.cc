#include <iostream>
using namespace std;

void invertir_array(int *array, int cantidad)
{
    int *inicio = array;

    int *fin = array + cantidad - 1;

    while (inicio < fin)
    {
        int temp = *inicio;
        *inicio = *fin;
        *fin = temp;

        inicio++;
        --fin;
    }
}

int main()
{
    int array[] = {10, 20, 30, 40, 50};
    int cantidad = 5;

    invertir_array(array, cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        std::cout << "Elemento " << (i + 1) << ": " << array[i] << std::endl;
    }

    return 0;
};