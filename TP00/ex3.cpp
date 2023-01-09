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
    
    void printstack()
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
    int check(stack s,int x);
    
};
int stack :: check(stack  s,int x)
{
    temp=head;
    while(temp!=NULL)
    {
        if (temp->element==x)
        {
            return 1;
        }
        else{
        temp=temp->next;
        }
    }
    return 0;
}

stack elimdepl(stack s)
{
    
    stack s2;
    s.temp=s.head;
    while(s.temp!=NULL)
    {
        int x=s.temp->element;
        if(s2.check(s2,x)==0){
            
        
        s2.push(x);
        }
        s.temp=(s.temp)->next;
        
        
    }
    return s2;

}
int main()
{
    stack s;
    s.push(3);
    s.push(4);
    s.push(3);
    s.push(4);
    // s.printstack();
    stack s2=elimdepl(s);
    s2.printstack();
    return 0;
    
}
