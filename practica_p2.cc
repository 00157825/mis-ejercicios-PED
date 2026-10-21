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
