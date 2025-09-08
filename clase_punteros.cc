#include <iostream>

void PasoPorValor(int n);
void PasoPorPuntero(int *ptr);
void PasoPorReferencia(int &n);

int main()
{
    int num = 100;

    //int *ptr = &num;

    std :: cout << "Valor de num: "<<num<<std::endl;

    PasoPorValor(num); //110
    PasoPorReferencia(num);

    std :: cout << "Valor de num: "<<num<<std::endl;

    std :: cout << "Valor de num: "<< num<<std::endl;


    return 0;
}

void PasoPorPuntero(int *ptr)
{
    std:: cout<<"Valor de n: " << *ptr + 10<<std::endl; 
}

void PasoPorValor(int n)
{
   std:: cout<<"Valor de n: " << n + 10<<std::endl; 
}

void PasoPorReferencia(int &n)
{
   std:: cout << "Valor de n: "<<n + 10<<std::endl;
}
