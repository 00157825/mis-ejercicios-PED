#include <iostream>
#include<stack>

bool isBalanced(const std::string& expression)
{
    std::stack<char> stack;

    for (const char c: expression)
    {
        //Para todo elemento de apertura apilado
        if (c == '(' || c == '['||c == '{')
        {
            stack.push(c);
        }

        else if(c == ')' || c == ']'||c == '}'){
            if (stack.empty())
            {
                return false;
            }
            
        }
        
    }
    
}

int main(){

    std::string expression = "{[()]}";

    return 0;
}