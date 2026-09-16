#include <iostream>
struct Node
{
    int data;
    Node *next;
};

void Insert(Node*& head, int data){
    Node* new_node = new Node{data, head};
    head = new_node;
}

void InsertAtEnd(Node*& head, int data){
    Node* new_node = new Node{data, nullptr};

    // Si esto ocurre, es por que la lista está vacia
    if (head == nullptr){
        head = new_node;
        return;
    }

    //Pero esto ocurre si no está vacia

    Node* current = head;

    while (current->next != nullptr)
    {
       current = current->next;
    }

    current->next = new Node;    
    
}

int main(){


    return 0;
}