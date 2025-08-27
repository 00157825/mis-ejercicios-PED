#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <ctime>

struct InformacionPersona
{
    std::string nombre_persona;
    
};

 
struct InformacionCupon{
    int cant_cupones;
    
    std::vector<std::pair<std::string, std::string>> cupon_premio;

    struct InformacionPersona inf_persona;
};
 
//  Vector global de tipo struct
std::vector<struct InformacionCupon> vector_cupones;

struct InformacionCupon SolicitarDatosGenerales();
std::string SolicitarDatos();
std::string GenerarCupon(std::string prefijo);
std::string AsignarPremio(std::string identificador_cupon);
void Imprimir(std:: vector <struct InformacionCupon>vector_cupones);
 
int main()
{

    char opcion;
    srand(time(0));
        // Solicitar la cant de cupones a generar
        struct InformacionCupon cupon;

    do
    {
        cupon = SolicitarDatosGenerales();
        // Almanenando el struct en el vector
        vector_cupones.push_back(cupon);

        Imprimir(vector_cupones);

        std::cout<<"¿Quieres seguir agregando mas informacion?"<<std::endl;
        std::cout<<"(s/n)";
        std::cin>>opcion;


    } while (opcion == 's'||opcion == 'S');
    
    

    return 0;
}

struct InformacionCupon SolicitarDatosGenerales()
{
    struct InformacionCupon cupon;

    std::cout<<"Ingresa el nombre de la persona: ";
    std::cin>>cupon.inf_persona.nombre_persona;
    std::cout<<"Ingresa la cantidad de cupones a generar: ";
    std::cin>>cupon.cant_cupones;
 
 
    for (int i = 0; i < cupon.cant_cupones; i++)
    {
        std::string cupon_generado = GenerarCupon(SolicitarDatos());
        std::string premio = AsignarPremio(cupon_generado);
        cupon.cupon_premio.push_back({cupon_generado, premio});
       
    }

    return cupon;
}
std::string SolicitarDatos()
{
 
    std::string prefijo;
 
    do
    {
        // Solicitar el prefijo
        std::cout << "Ingresa el prefijo del cupon (3 letras maximo): ";
        std::cin >> prefijo;
 
        // Validar la longitud igual 3
        if (prefijo.length() == 3)
        {
            return prefijo;
        }
        else
        {
            std::cout << "Error. El prefijo debe ser de 3 letras.\n";
        }
    } while (true);
}
 
std::string GenerarCupon(std::string prefijo)
{
    // generar el valor aleatorio
    int numero_aleatorio = rand() % 100 + 999;
    std::string conversion = std::to_string(numero_aleatorio);
    return prefijo + conversion;
}
 
std::string AsignarPremio(std::string identificador_cupon)
{
    std::string mensaje;
    // Extraer el valor numerico del identificador
    // AGO1090   1090
    identificador_cupon = identificador_cupon.substr(3, 4);
 
    // Convertir a entero
    int conversion_entero = std::stoi(identificador_cupon);
 
    // Evaluar si es o no par
    if (conversion_entero % 2 == 0)
    {
        mensaje = "Tiene premio";
    }
    else
    {
        mensaje = "No tiene premio";
    }
 
    return mensaje;
}

void Imprimir(std:: vector <struct InformacionCupon>vector_cupones)
{
    for (auto c: vector_cupones )
    {
        std :: cout << "Nombre de la persona: "<<c.inf_persona.nombre_persona<<std::endl;
        std :: cout << "Cantidad de cupones: "<<c.cant_cupones<<std::endl;

        for (auto c_p: c.cupon_premio )
        {
            std :: cout << "Cupon: "<< c_p.first<<std::endl;
            std :: cout << "Premio: "<< c_p.second<<std::endl;
        }
        
    }
    
}