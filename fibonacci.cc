#include <iostream>

int fibonacci(int n)
{
    if (n < 1)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    else 
    {
        return (fibonacci(n-1) + fibonacci (n-2));
    }
     
}

int main()
{
    int n = 7;

    std::cout<<fibonacci(n);
}