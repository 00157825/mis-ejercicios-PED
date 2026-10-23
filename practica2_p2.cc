#include <stack>
#include <queue>

void RotateQueue(std::queue<int> &requests, int k);

void RemoveFromStack(std::stack<int> &tasks, int target)
{
    std::stack<int> auxiliary;

    while (!tasks.empty())
    {
        int value = tasks.top();
        tasks.pop();

        if (value != target)
        {
            auxiliary.push(value);
        }
    }

    // Complete la función.
    while (!auxiliary.empty())
    {
        tasks.push(auxiliary.top());
        auxiliary.pop();
    }
}

int main()
{
    std::stack<int> tasks;

    tasks.push(10);
    tasks.push(20);
    tasks.push(30);
    tasks.push(20);
    tasks.push(40);

    RemoveFromStack(tasks, 20);
}

void RotateQueue(std::queue<int> &requests, int k)
{
    if (requests.empty() || k <= 0)
    {
        return;
    }

    int n = static_cast<int>(requests.size());
    int rotaciones = k % n;

    for (int i = 0; i < rotaciones; ++i)
    {
        requests.push(requests.front());
        requests.pop();
    }
}


/*Respuesta a la pregunta: ¿por qué es necesario devolver los elementos a la pila original?

Porque la función debe modificar la pila original: el enunciado pide que tasks termine con los elementos restantes.
Después del primer ciclo, tasks está vacía y todos los elementos que se conservan están en auxiliary, que es una variable 
local y se destruye al terminar la función. Si no se devolvieran, se perderían todos los datos. Además, el primer ciclo 
deja los elementos en orden invertido dentro de auxiliary, así que al regresarlos uno por uno a tasks se invierte otra 
vez y se restaura el orden relativo original.*/

/*Respuesta a la pregunta: ¿qué elemento queda al frente y cómo cambia su posición?

Después de rotar k posiciones, queda al frente el elemento que originalmente estaba en la posición k (contando desde 0). 
Con k = 2, el frente pasa a ser el 30, que antes estaba en la tercera posición (índice 2). Su posición cambia del 
índice 2 al índice 0, es decir, avanzó k lugares hacia el frente. Los elementos que estaban antes (10 y 20) pasan al 
final conservando su orden relativo. En general, el elemento en el índice i pasa al índice (i - k) mod n, donde n es el 
tamaño de la cola.*/