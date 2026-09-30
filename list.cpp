#include <iostream>
#include <list>

int main()
{
    std::list <int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    for (int i : numbers)
    {
        std::cout << i << "-> ";
    }
    std::cout << std::endl;

    numbers.push_front(40);
    numbers.push_front(50);
    numbers.push_front(60);

   for (int i : numbers)
    {
        std::cout << i << "-> ";
    }
    std::cout << std::endl;

    numbers.pop_front();
    numbers.pop_back();

    for (int i : numbers)
    {
        std::cout << i << "->";
    }
    std::cout << std::endl;

    return 0;
}