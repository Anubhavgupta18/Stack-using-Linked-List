#include<iostream>
#include<stdio.h>
using namespace std;
class Stack
{
private:
    struct node
    {
        int item;
        node *next;
    };
    node *top;
public:
    Stack();
    bool isEmpty();
    void push(int);
    void pop();
    int peek();
};
Stack::Stack()
{
    top=NULL;
}
bool Stack::isEmpty()
{
    return top==NULL;
}
void Stack::push(int data)
{
    node *n=new node;
    n->item=data;
    if(top==NULL)
    {
        top=n;
        n->next=NULL;
    }
    else
    {
        n->next=top;
        top=n;
    }
}
void Stack::pop()
{
    if(isEmpty())
    {
        cout<<"OPERATION FAILED:STACK UNDERFLOW!\n";
    }
    else
    {
        node *temp=top;
        if(temp->next==NULL)
        {
            top=NULL;
            delete temp;
        }
        else
        {
            top=top->next;
            delete temp;
        }
    }
}
int Stack::peek()
{
    if(!isEmpty())
    {
        return top->item;
    }
}
