#include<stack>
#include<iostream>
using namespace std;
class GetMinStack
{
    private: 
        stack<int> stackData;           //用来存放数据的栈
        stack<int> stackMin;            //用来存放最小值的栈
    public:
        void push(int newNum)
        {
            if(stackMin.empty())        //当最值栈为空时，将数据压入最值栈
            {
                stackMin.push(newNum);
            }
            else if(newNum <= stackMin.top())   //若不为空，则比较最值栈顶元素，若小于则压栈
            {
                stackMin.push(newNum);
            }
            stackData.push(newNum);     //不管怎样数据都要如数据栈
        }           //这种压栈规则会使得出栈时变得麻烦
        void pop()  //出栈操作
        {
            if(!stackData.empty())  //只有当数据栈非空时才能出栈
            {
                int value = stackData.top();
                if(value == stackMin.top())     //压栈的规则使得数据栈和最值栈的长度不同
                     stackMin.pop();
                stackData.pop();
            }
            return;
        }
        int getmin()
        {
            if(!stackMin.empty())
                return stackMin.top();
            return -1;
        }
};
class GetMinStack2
{
    private:
        stack<int> stackData;
        stack<int> stackMin;
    public:
        void push(int newNum)
        {
            if(stackMin.empty())
                stackMin.push(newNum);
            else if(newNum <= stackMin.top())
                stackMin.push(newNum);
            else//当最值栈不为空，且数据大于最值栈的栈顶元素，将栈顶元素压入栈
                stackMin.push(stackMin.top());
            stackData.push(newNum);
        }
        void pop()
        {
            if(!stackData.empty())
            {
                stackData.pop();
                stackMin.pop();
            }
            return ;                //这里应该写异常处理的
        }
        int getmin()
        {
            if(!stackMin.empty())
                return stackMin.top();
            return -1;              //异常
        }
        
};
int main(void)
{
    GetMinStack stack1;
    stack1.push(3);
    cout << stack1.getmin() << endl;
    stack1.push(4);
    cout << stack1.getmin() << endl;
    stack1.push(1);
    cout << stack1.getmin() << endl;
    stack1.pop();
    cout << stack1.getmin() << endl;
    GetMinStack2 stack2;
    stack2.push(3);
    cout << stack2.getmin() << endl;
    stack2.push(4);
    cout << stack2.getmin() << endl;
    stack2.push(1);
    cout << stack2.getmin() << endl;
    stack2.pop();
    cout << stack2.getmin() << endl;
    return 0;
}
