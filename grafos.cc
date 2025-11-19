#include <iostream>
#include <unordered_map>
#include <vector>

//typedef std::vector<int> vector; esto es un alias

using Grafo = std::unordered_map<char, std::vector<char>>;

void AgregarAristas(Grafo &lista_adj, char origen, char destino);
void Imprimir(const Grafo &lista_adj);

int main()
{
    Grafo grafo;

    AgregarAristas(grafo,'a','c');
    AgregarAristas(grafo, 'a', 'd');
    AgregarAristas(grafo, 'c', 'd');
    AgregarAristas(grafo, 'd', 'b');

    Imprimir(grafo);

    return 0;
}

void AgregarAristas(Grafo &lista_adj, char origen, char destino)
{
    lista_adj[origen].push_back(destino);

    lista_adj[destino].push_back(origen);
}

void Imprimir(const Grafo &lista_adj)
{
    for (auto g : lista_adj)
    {
        std::cout << "Nodo origen: "<< g.first;

        for (auto j : g.second)
        {
            std::cout<<" || Nodo destino: "<<j;
        }

        std::cout << std::endl;   
    }
    
}