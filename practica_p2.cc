#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

void Append(Node *&head, int value)
{
    Node *new_node = new Node{value, nullptr, nullptr};

    if (head == nullptr)
    {
        head = new_node;
        return;
    }

    Node *current = head;

    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = new_node;
    new_node->prev = current;
}

void PrintForward(Node *head)
{
    Node *current = head;

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << '\n';
}

void PrintBackward(Node *head)
{
    if (head == nullptr)
    {
        return;
    }

    Node *current = head;

    while (current->next != nullptr)
    {
        current = current->next;
    }

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->prev;
    }

    std::cout << '\n';
}

bool InsertAfter(Node* head, int target, int value);
void SplitByPosition(Node*& head, Node*& even_head, Node*& odd_head);
void MoveLastToFront(Node*& head);

int main()
{
    Node *head = nullptr;

    Append(head, 10);
    Append(head, 20);
    Append(head, 30);
    Append(head, 40);
    Append(head, 50);

    return 0;
}

bool InsertAfter(Node* head, int target, int value)
{
    Node *current = head;

    while (current != nullptr && current->data != target)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        return false;
    }

    Node *new_node = new Node{value, current->next, current};

    if (current->next != nullptr)
    {
        current->next->prev = new_node;
    }

    current->next = new_node;
    return true;
}

void SplitByPosition(Node*& head, Node*& even_head, Node*& odd_head) {
    even_head = nullptr;
    odd_head = nullptr;
    Node* even_tail = nullptr;
    Node* odd_tail = nullptr;

    Node* current = head;
    head = nullptr;              // la lista original deja de existir
    int pos = 0;

    while (current != nullptr) {
        Node* next = current->next;   // guardar antes de desconectar
        current->next = nullptr;
        current->prev = nullptr;

        // Elegir destino según la posición original
        Node*& dest_head = (pos % 2 == 0) ? even_head : odd_head;
        Node*& dest_tail = (pos % 2 == 0) ? even_tail : odd_tail;

        if (dest_head == nullptr) {
            dest_head = dest_tail = current;
        } else {
            dest_tail->next = current;
            current->prev = dest_tail;
            dest_tail = current;
        }

        current = next;
        ++pos;
    }
}

void MoveLastToFront(Node*& head)
{   
    if (head == nullptr || head->next == nullptr) 
    {
        return;
    }

    Node* last = head;

    while (last->next != nullptr)
    {
        last = last->next;
    }

    last->next->prev = nullptr;

    // Conectarlo al frente
    last->prev = nullptr;
    last->next = head;
    head->prev = last;

    head = last;
    
}

/*a. ¿Por qué guardar el siguiente nodo antes de modificar current->next?

Porque current->next es la única referencia que tenemos al resto de la lista. En esta función, current->next se pone en 
nullptr para desconectar el nodo y luego se reasigna al reubicarlo. Si no se guardara antes en next_node, se perdería el 
acceso a los nodos siguientes, el recorrido no podría continuar y esos nodos quedarían inaccesibles (fuga de memoria).

b. ¿Qué problema ocurre si se actualizan next pero no prev?

La lista queda inconsistente: hacia adelante se ve correcta, pero los prev siguen apuntando a nodos de la lista original,
o a nullptr. PrintBackward recorrería nodos incorrectos o se detendría antes de tiempo, y en la lista impar, 
por ejemplo, el nodo 40 todavía apuntaría hacia atrás al 30 en vez de al 20. Cualquier operación que use prev 
(borrar, insertar antes, recorrer al revés) podría corromper la lista o causar un acceso inválido a memoria.

c. Complejidad temporal

O(n), donde n es el número de nodos. Cada nodo se visita exactamente una vez y, por cada uno, se hace trabajo 
constante: guardar next, reasignar un par de punteros y agregarlo al final de una de las dos listas en O(1) gracias 
a los punteros de cola. Total: n · O(1) = O(n). El espacio adicional es O(1), porque solo se usan unos cuantos punteros
 y no se crean nodos nuevos.*/