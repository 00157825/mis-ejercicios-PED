#include <iostream>

using namespace std;

void depositar(float *saldo, float cantidad)
{
    cout << "Saldo Original: $"<< *saldo<<endl;

    *saldo += cantidad;

    cout << "Monto depositado: $" << cantidad << endl;
    cout << "Nuevo saldo: $" << *saldo << endl;
}

int main()
{
    float saldo = 150.67;
    float cantidad = 50.45;

    depositar(&saldo, cantidad);

}