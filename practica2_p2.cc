#include <stack>

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