#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

std::string GenerarCupon(std::string PREFIJO);
std :: string VerificacionPremio(std::string identificador_cupon);
std :: string SolicitarDatos();

struct InformacionCupon
{
    int cant_cupones;
    std :: string nombre_persona;
    std :: vector <std :: pair <std::string, std::string>> cupones_generados;
} cupon;

std :: vector <struct InformacionCupon> inf_cupones;

int main()
{
    srand(time(0));

 
    // std :: vector<std::string> cupones_vector;

    std :: cout << "Ingrese el nombre de la persona:"<<std::endl;
    std :: cin >> cupon.nombre_persona;
  

    std :: cout << "¿Cuantos cupones quisiera generar?"<<std::endl;
    std :: cin >> cupon.cant_cupones;


    for (int i = 0; i < cupon.cant_cupones; i++)
    {
        std::string prefijo = SolicitarDatos();
        std::string cupon_generado = GenerarCupon(prefijo);

        // array[i] = cupon_generado; 
        // std::cout << "Cupón generado: " << cupon_generado << std::endl;
        // VerificacionPremio(cupon_generado);
        cupon.cupones_generados.push_back({cupon_generado, VerificacionPremio(cupon_generado)});
        // cupones_vector.push_back(cupon_generado);
    }

    inf_cupones.push_back(cupon);

    std :: cout << inf_cupones[0].cant_cupones;

    std :: cout << "Informacion de los cupones generados: "<<std::endl;
    std :: cout << "Cantidad de cupones: "<<cupon.cant_cupones << std:: endl;
    std :: cout << "Nombre de la persona: "<<cupon.nombre_persona<<std::endl;


    for (auto cupon : cupon.cupones_generados)
    {
        std :: cout << "Cupones:  " << cupon.first << "- Premio: "<< cupon.second <<std::endl;
    }

    
    return 0;
}

std::string GenerarCupon(std::string PREFIJO)
{
    int numero_aleatorio = rand() % 100 + 900; // genera un número entre 900 y 999
    std::string conversion = std::to_string(numero_aleatorio);
    return PREFIJO + conversion;
}

std :: string VerificacionPremio(std::string identificador_cupon)
{
    std:: string mensaje;

    std::string numeros = identificador_cupon.substr(3);
    int conversion_entero = std::stoi(numeros);

    if (conversion_entero % 2 == 0)
    {
        mensaje = "TIENES PREMIO ";
    }
    else 
    {
        mensaje = "NO TIENES PREMIO ";

    }

    return mensaje;

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
