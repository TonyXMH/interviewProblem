#include<stack>
#include<iostream>
using namespace std;
//利用递归函数和栈操作将一个栈逆序
//首先写一个函数的功能是返回栈底元素并删除
int getAndRemoveLastElement(stack<int> & stack1)
{
    //首先将栈顶元素取出
    int result = stack1.top();
    stack1.pop();
    if(stack1.empty())  //递归出口
        return result;
    else
    {
        int last = getAndRemoveLastElement(stack1);     //获取栈底元素
        stack1.push(result);                            //将其他元素压入栈
        return result;
    }
}
void reverse(stack<int> stack1)
{
    //先写递归出口
    if(stack1.empty())
        return;
    int last = getAndRemoveLastElement(stack1);         //
    reverse(stack1);
    stack1.push(last);
}
//其实自己不是很理解2个递归函数，提供了2个函数栈，要在同一个栈中进行数据的逆序
//栈中的数据放到函数栈中，先将栈底的元素放入函数栈，在从函数栈取出栈顶元素压栈。
//从而实现了栈的逆序
int main(void)
{
    stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    reverse(stack1);
    while(!stack1.empty())
    {
        cout << stack1.top() << endl;
        stack1.pop();
    }
    return 0;
}
