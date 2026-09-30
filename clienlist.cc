#include <iostream>
#include<list>

struct Client
{
    int id;
    std:: string name;
    int age;
};

int main()
{
    std::list <Client> clients;

    clients.push_back({1, "Chepe", 20});
    clients.push_back({2, "Luis", 20});
    clients.push_back({3, "Carlos", 19});

    int op;

    do
    {
        std::cout << "Ingrese una opcion"<<std::endl;
        std::cin>>op;

        switch (op)
        {
        case 1:
            {
            int id, age;
            std::string name;


            std::cout <<"Ingrese un cliente"<<std::endl;
            std::cin>>id;
            std::cout <<"Ingrese un edad"<<std::endl;
            std::cin>>age;
            std::cout <<"Ingrese un nombre"<<std::endl;
            std::cin>>name;

            clients.push_back({id, name, age});
            break;
            }
        default:
            break;
        }
    } while (op != 100);
    

    for (const Client& c: clients)
    {
        std::cout << c.id<<std::endl;
        std::cout << c.name<<std::endl;
        std::cout << c.age<<std::endl;
    }
    
}