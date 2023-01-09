#include<iostream>
using namespace std;
struct stack
{
    

    struct node
    {
        int element;
        node* next;
    };

    typedef struct node node;
    typedef node* nodeptr;

    nodeptr head = NULL;
    nodeptr curr = NULL;
    nodeptr temp = NULL;

    void push(int addelement)
    {
        nodeptr n = new node;
        
        
        
        if(head!=NULL)
        {
           
            
            n->element=addelement;
            n->next=head;
            head=n;
        }
        else
        {
        head=n;
        n->next=NULL;
           
            
        n->element=addelement;
        }
    }
    void pop()
    {
        if(head==NULL)
        {
            cout<<"this stack is empty"<<"\n";
        }
        else{
            temp=head;
            head=head->next;
            
            delete temp;
        
        }
    }
    
    void printStack()
    {
        if(head==NULL)
        {
            
        }
        else{
            curr=head;
            while(curr!=NULL)
            {
                cout<<curr->element<<"\n";
                curr=curr->next;
            }
        }
    }
};
int main()
{
    stack stack1;
    stack1.push(3);
    stack1.push(4);
    stack1.push(8);
    stack1.pop();
    stack1.printStack();
    return 0;
}
