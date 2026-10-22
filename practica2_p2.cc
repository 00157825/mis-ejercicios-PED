#include <stack>
#include <queue>

void RotateQueue(std::queue<int> &requests, int k);

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

void RotateQueue(std::queue<int> &requests, int k)
{
    if (requests.empty() || k <= 0)
    {
        return;
    }

    int n = static_cast<int>(requests.size());
    int rotaciones = k % n;

    for (int i = 0; i < rotaciones; ++i)
    {
        requests.push(requests.front());
        requests.pop();
    }
}
