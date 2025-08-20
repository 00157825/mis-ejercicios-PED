#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

std::string GenerarCupon(std::string PREFIJO);
void VerificacionPremio(std::string identificador_cupon);
std :: string SolicitarDatos();

int main()
{
    srand(time(0));

   
    int cupones_solicitados;
    

    std :: cout << "¿Cuantos cupones quisiera generar?"<<std::endl;
    std :: cin >> cupones_solicitados;

    std ::string array[cupones_solicitados];

    for (int i = 0; i < cupones_solicitados; i++)
    {
        std::string prefijo = SolicitarDatos();
        std::string cupon_generado = GenerarCupon(prefijo);

        array[i] = cupon_generado; 

        std::cout << "Cupón generado: " << cupon_generado << std::endl;
        VerificacionPremio(cupon_generado);

    return 0;
}

std::string GenerarCupon(std::string PREFIJO)
{
    int numero_aleatorio = rand() % 100 + 900; // genera un número entre 100 y 999
    std::string conversion = std::to_string(numero_aleatorio);
    return PREFIJO + conversion;
}

void VerificacionPremio(std::string identificador_cupon)
{

    std::string numeros = identificador_cupon.substr(3);
    int conversion_entero = std::stoi(numeros);

    if (conversion_entero % 2 == 0)
    {
        std::cout << "TIENES PREMIO " << std::endl;
    }
    else 
    {
        std::cout << "NO TIENES PREMIO " << std::endl;
    }
}

std :: string SolicitarDatos()
{

    std::string prefijo;
    int intentos = 0;

    
    do
    {
        std :: cout << "Ingrese el prefijo de su cupon (maximo de 3 letras)"<<std::endl;
        std :: cin >> prefijo;

        if (prefijo.length() == 3)
        {
            return prefijo;
            
        }

        else
        {
            std :: cout << "Recuerda que son EXACTAMENTE 3 letras"<<std::endl;
            intentos ++;
        }
        


    } 
    while (prefijo.length() != 3 && intentos < 5);
    
    
    return "";
}