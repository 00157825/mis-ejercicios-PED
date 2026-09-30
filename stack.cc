#include <iostream>
#include<stack>

int main(){

    std::stack <int> numbers;

    numbers.push(1);
    numbers.push(2);
    numbers.push(3);
    numbers.push(4);

    std::cout << "TOP: "<<numbers.top()<<std::endl;
    numbers.pop();
    std::cout << "TOP: "<<numbers.top()<<std::endl;
    numbers.pop();
    std::cout << "TOP: "<<numbers.top()<<std::endl;
    numbers.pop();
    std::cout << "TOP: "<<numbers.top()<<std::endl;
    numbers.pop();

    return 0;
}