//Prev link improvements to be made
#include<iostream>
using namespace std;
struct Node
{
        int data;
        Node* next;
        Node* prev;
};
Node *head=NULL;
void insBeg(int v)
{
        Node* temp=new Node;
        temp->data=v;
        temp->next=head;
        temp->prev=NULL;
        head=temp;
        cout<<"Successfully Inserted!\n";
}
void insEnd(int v)
{
        if(head==NULL)
        {
                insBeg(v);
                return;
        }
        Node *temp=head;
        while(temp->next!=NULL)
        {
                temp=temp->next;
        }
        Node *p=new Node;
        temp->next=p;
        p->data=v;
        p->prev=temp;
        cout<<"Successfully Inserted!\n";
}
void insPos(int p,int v)
{
        if(head==NULL)
        {
                insBeg(v);
                return;
        }
        if(p==0)
        {
                insBeg(v);
                return;
        }
        Node *temp=head;
        for(int i=0;i<p-1;i++)
        {
                if(temp->next==NULL)
                {
                        cout<<"Positon out of bounds!\n";
                        return;
                }
                temp=temp->next;
        }
        Node *pa=new Node;
        pa->data=v;
        pa->next=temp->next;
        pa->prev=temp;
        temp->next=pa;
        pa->next->prev=pa;
        cout<<"Successfully inserted!\n";
}
void delBeg()
{
        if(head==NULL)
        {
                cout<<"There are no nodes!\n";
                return;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
        cout<<"Successfully deleted!\n";
}
void delEnd()
{
        if(head==NULL)
        {
                cout<<"There are no nodes!\n";
                return;
        }
        Node *temp=head;
        if(temp->next==NULL)
        {
                delBeg();
                return;
        }
        while(temp->next->next!=NULL)
        {
                temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
        cout<<"Successfully deleted!\n";
}
void delPos(int p)
{
        if(head==NULL)
        {
                cout<<"There are no nodes!\n";
                return;
        }
        if(p==0)
        {
                delBeg();
                return;
        }
        Node *temp=head;
        for(int i =0;i<p-1;i++)
        {
                if(temp->next==NULL)
                {
                        cout<<"Position out of bounds!\n";
                        return;
                }
                temp=temp->next;
        }
        if(temp->next==NULL)
        {
                cout<<"Position out of bounds!\n";
                return;
        }
        if(temp->next->next==NULL)
        {
                delete temp->next;
                temp->next=NULL;
                return;
                cout<<"Successfully deleted!\n";
        }
        Node* r=temp->next->next;
        delete temp->next;
        temp->next=r;
        r->prev=temp;
        cout<<"Successfully deleted!\n";
}
int src(int v)
{
        if(head==NULL)
        {
                return -1;
        }
        Node* temp=head;
        int ct=0;
        while(temp!=NULL)
        {
                if(temp->data==v)
                        return ct;
                ct++;
                temp=temp->next;
        }
        return -1;
}
void delVal(int v)
{
        if(src(v)!=-1)
        {
                delPos(src(v));
                return;
        }
        else
                cout<<"There is no such element!\n";
}
void disp()
{
        Node *temp=head;
        if(head==NULL)
        {
                cout<<"There are no elements!\n";
                return;
        }
        while(temp!=NULL)
        {
                cout<<temp->data<<" ";
                temp=temp->next;
        }
        cout<<endl;
}
int main()
{
        int p,v;
        cout<<"---Enter number for operation---";
        cout<<"\n1)Insertion at beginning\n";
        cout<<"2)Insertion at end\n";
        cout<<"3)Insertion at position\n";
        cout<<"4)Deletion at beginning\n";
        cout<<"5)Deletion at end\n";
        cout<<"6)Deletion at position\n";
        cout<<"7)Deletion by value\n";
        cout<<"8)Display\n9)Exit\n";
        int ch;
        cin>>ch;
        while(1)
        {
                switch(ch)
                {
                        case 1:
                                cout<<"Enter value to insert:";
                                cin>>v;
                                insBeg(v);
                                break;
                        case 2:
                                cout<<"Enter value to insert:";
                                cin>>v;
                                insEnd(v);
                                break;
                        case 3:
                                cout<<"Enter value to insert:";
                                cin>>v;
                                cout<<"Enter position to insert:";
                                cin>>p;
                                insPos(p,v);
                                break;
                        case 4:
                                delBeg();
                                break;
                        case 5:
                                delEnd();
                                break;
                        case 6:
                                cout<<"Enter position to delete:";
                                cin>>p;
                                delPos(p);
                                break;
                        case 7:
                                cout<<"Enter value to delete:";
                                cin>>v;
                                delVal(v);
                                break;
                        case 8:
                                disp();
                                break;
                        case 9:
                                cout<<"Program End!\n";
                                return 0;
                        default:
                                cout<<"Enter valid number(1-8)!\n";
                }
                cout<<"Enter number for operation:";
                cin>>ch;
        }
}
