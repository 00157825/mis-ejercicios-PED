#include <iostream>
using namespace std;


int main()
{
    int array[]={10,20,30,40,50};
    int n = sizeof(array)/sizeof(array[0]);

    int *ptr_inicio = array;
    int *ptr_fin = array + n - 1;

    while (ptr_inicio < ptr_fin)
    {
        int temp = *ptr_inicio;
        *ptr_inicio = *ptr_fin;
        *ptr_fin = temp;

        ptr_inicio++; // Avanza a la siguiente posición de memoria
        ptr_fin--;    // Retrocede a la posición de memoria anterior
    }
    
    for (int* ptr = array; ptr < array + n; ptr++)
    {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;
    
    return 0;
};