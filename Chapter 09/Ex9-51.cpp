#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool checkParentheses(const string &expression)
{
    stack<char> stk;
    for (const auto &c : expression)
    {
        if (c == ')')
        {
            while (!stk.empty() && stk.top() != '(')
            {
                stk.pop();
            }
            if (stk.empty())
                return false;
            stk.pop();
        }
        else
            stk.push(c);
    }

    while (!stk.empty())
    {
        if (stk.top() == '(')
            return false;
        stk.pop();
    }

    return true;
}

int main()
{
    cout << (checkParentheses("12+34-56-((78-9)+10)") ? "Pass" : "Fail") << endl;
    cout << (checkParentheses("(12+34)-(56-((78-9)+10))") ? "Pass": "Fail") << endl;
    cout << (checkParentheses("((12+34-(56-10)-1") ? "Pass" : "Fail") << endl;
    cout << (checkParentheses("12+34)-(56-10)-1") ? "Pass" : "Fail") << endl;
}