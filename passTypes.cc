#include <iostream>

using namespace std;

//Paso por valor
void cambiarValor(int a){
    a = 20;
}

//Paso por referencia aaaaaa
// Todo lo que pase a "b" le pasara tambien a la variable "a"
void cambiarValorReferencia(int& b){
    b = 0;
} 

//Paso por referencia de punteros
//int*& es la direccion de memoria de un puntero
void cambiarValorReferenciaPtr(int*& a){
    a = nullptr;
}

int main(){
    int a = 10;
    int *ptr = &a;

    /*
    cout<<"a: "<<a<<endl; // 10
    cambiarValorReferencia(a);
    cout<<"a luego de ejecutar funcion: "<<a<<endl; 
    */

    std::cout<<"ptr: "<<ptr<<endl; // 10
    cambiarValorReferenciaPtr(ptr);
    std::cout<<"ptr luego de ejecutar funcion: "<<ptr<<endl; 
    
    return 0;   
}