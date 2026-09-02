#include <iostream>
using namespace std;

void adjust_price(double *precios,int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        *(precios + i) *= 1.10;
    }
    
}
int main()
{
    double price[] = {100, 230, 75, 500, 120};
    int cantidad = 5;

    adjust_price(price, cantidad);

    std::cout<<"Precios Actualizados: "<<std::endl;
    for (int i = 0; i < cantidad; i++)
    {
        std::cout<< *(price + i)<<std::endl;
    }
    
    
    return 0;
}