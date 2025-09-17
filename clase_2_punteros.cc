#include <iostream>

int main()
{
    int array[5] = {10,20,30,40,50};

    int suma = 0;

    int *ptr = array;

    std:: cout << "Peso de bytes en int: "<< sizeof(int)<<std::endl;


    std :: cout << "Dir. Memoria: "<<&array;
    std :: cout << " Valor pos[0]: "<<array[0]<<std::endl;

    std :: cout << "Dir. Memoria: "<<(array +1);
    std :: cout << " Valor pos[1]: "<< *(array +1)<<std::endl;

    std :: cout << "Dir. Memoria de la pos[2]: "<< ptr + 2
                <<"Valor pos [2]: " << *(ptr +2)<<std::endl;

    std :: cout <<std::endl;

    std:: cout << "Primer For"<<std:: endl;

    
    for (int i = 0; i < 5; i++)
    {
        std :: cout << "Dir. Memoria: "<<(array +i);
        std :: cout << " Valor pos[0]: "<<*(array + i)<<std::endl;

    }

    std:: cout << "Segundo For"<<std::endl;

    for (int i = 0; i < 5; i++)
    {
        std :: cout << "Dir. Memoria de la pos["<<(i)<<"]: "<< ptr + i
                <<" Valor pos ["<<(i)<<"]: " << *(ptr + i)<<std::endl;

        suma = suma + (*(ptr +i));
        
    }
    
    std :: cout << "Suma: "<<suma;

    

    return 0;
}