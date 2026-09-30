#include <iostream>
#include<queue>

int main(){

    std::queue <int> numbers;

    numbers.push(1);
    numbers.push(2);
    numbers.push(3);
    numbers.push(4);

    std::cout << "Primer elemento que saldrá: "<<numbers.front()<<std::endl;
    std::cout << "Ultimo elemento que saldrá: "<<numbers.back()<<std::endl;
    numbers.pop();
    std::cout << "Siguiente elemento que saldrá: "<<numbers.front()<<std::endl;
    std::cout << "Ultimo elemento que saldrá: "<<numbers.back()<<std::endl;
    while (!numbers.empty())
    {
        numbers.pop();
    }
    


    return 0;
}