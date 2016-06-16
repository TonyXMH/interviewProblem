#include<stack>
#include<iostream>
using namespace std;
void sortStackByStack(stack<int> & stack1)
{
    stack<int> help;                //help为辅助栈
    while(!stack1.empty())        //我们大家目的是将stack中的数据全部移入help
    {                               //所用这个条件
        int cur = stack1.top();     //每次必须先取出stack的栈顶元素
        stack1.pop();               //并出栈
        while(!help.empty() && help.top() < cur)
        {   //循环里就是当help栈顶元素小于cur的时候，我们要将help栈的元素逐一压入stack中，直到cur小于或者等于help的栈顶元素
            stack1.push(help.top());
            help.pop();
        }
        //每次都需要将cur压入help栈中
        help.push(cur);
    }
    while(!help.empty())
    {
        stack1.push(help.top());
        help.pop();
    }
}

int main(void)
{
    stack<int> stack1;
    stack1.push(3);
    stack1.push(1);
    stack1.push(6);
    stack1.push(2);
    stack1.push(5);
    stack1.push(4);
    sortStackByStack(stack1);
    while(!stack1.empty())
    {
        cout << stack1.top() << endl;
        stack1.pop();
    }
    return 0;
}
