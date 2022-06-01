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
    node *start;
public:
    Stack();
    bool isEmpty();
    void push(int);
    void pop();
    int peek();
};
Stack::Stack()
{
    start=NULL;
}
bool Stack::isEmpty()
{
    return start==NULL;
}
void Stack::push(int data)
{
    node *n=new node;
    n->item=data;
    n->next=NULL;
    if(start==NULL)
    {
        start=n;
    }
    else
    {
        node *temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
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
        node *temp=start;
        if(temp->next==NULL)
        {
            start=NULL;
            delete temp;
        }
        else
        {
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            delete temp->next;
            temp->next=NULL;
        }
    }
}
int Stack::peek()
{
    if(!isEmpty())
    {
        node *temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        return temp->item;
    }
}
