#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std :: string GenerarCupon(std :: string PREFIJO );
void VerificacionPremio (std :: string identificador_cupon);


int main()
{
     srand(time(0));

    std :: string cupon_generado = GenerarCupon("HGF");

    std :: cout << cupon_generado;

    
    return 0;
}

std :: string GenerarCupon(std :: string PREFIJO)
{
   

    int numero_aleatorio = rand() % 100 + 999;
    std :: string conversion = std :: to_string(numero_aleatorio);
    return PREFIJO + conversion;

    std :: string substraccion = conversion.substr(1,4);

    std :: cout << substraccion;


};

void VerificacionPremio(std :: string identidicador_cupon)
{
    identidicador_cupon.substr(3,4);

    int conversion_entero = std ::stoi(identidicador_cupon);

    if (conversion_entero % 2 == 0)
    {
        std :: cout << "TIENES PREMIO" << std :: endl;
    }

    else 
    {
        std :: cout << "NO TIENES PREMIO"<<std ::endl;

        //xd//
    }
    

}
