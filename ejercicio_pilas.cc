#include <iostream>
#include <stack>

int main()
{
    int cantidad;
    char letras;
    std :: stack<char> nombre;

    std :: cout << "¿Cuantas letras tiene tu nombre? \n";
    std :: cin >> cantidad;

    for (int i = 0; i < cantidad; i++)
    {
        std :: cout << "Ingresa la letra #"<<(i+1)<<": ";
        std :: cin >> letras;

        nombre.push(letras);
    }
    
    
    for (int i = 0; i < cantidad; i++)
    {
        
        std :: cout << nombre.top();
        nombre.pop();
    }
    

    return 0;
}