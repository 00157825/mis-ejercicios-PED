#include <iostream>
using namespace std;

int main()
{
    int n;

    do
    {
        std::cout<< "Ingrese la cantidad de elementoss"<<std::endl;
        std::cin>>n;

        int *vector = new int[n];

        for (int i = 0; i < n; i++)
        {
            std::cout << "Ingrese el emento: "<<std::endl;
            std::cin>>vector[i];
        }
    
        std::cout<<endl;
       
        std::cout<<"Los elementos son: "<<std::endl;
        for (int i = 0; i < n; i++)
        {
            std::cout<<vector[i]<<endl;
        }

        std::cout<<endl;

        delete [] vector;

    } while (n > 0);
    
    return 0;
}