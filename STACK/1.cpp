#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.pop();

    cout << "The top of stack is " << s.top() << endl;

    cout << "The size of stack is " << s.size() << endl;

    if (s.empty())
    {
        cout << "Stack is empty";
    }
    else
    {
        cout << "Stack is not empty";
    }
    return 0;
}