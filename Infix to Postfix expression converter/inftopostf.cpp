#include <iostream>
using namespace std;
char sta[100],infix[1000],postfix[1000];
int top=-1;
void push(char val)
{
    sta[++top]=val;
}
int pop()
{
    if(top==-1)
    {
        cout<<"No elements to pop!\n";
        return 0;
    }
    return sta[top--];
}
int pri(char c)
{
    if(c=='+'||c=='-') return 0;
    if(c=='*'||c=='/'||c=='%') return 1;
    if(c=='^') return 2;
    return -1;
}
bool isOp(char c)
{
    return c=='+'||c=='-'||c=='%'||c=='/'||c=='*'||c=='^';
}
bool isCh(char c)
{
    return ((c>='a'&&c<='z')||(c>='A'&&c<='Z'));
}
void infToPos()
{
    cout<<"Enter infix expression:";
    cin.getline(infix,sizeof(infix));
    int i=0;char x;int ct=0;
    while(infix[i]!='\0')
    {
        if(infix[i]==' ')
        {
            i++;
            continue;
        }
        if(infix[i]=='(')
        {
            push('(');
            i++;
        }
        else if(infix[i]==')')
        {
            while((x=pop())!='(')
            {
                postfix[ct++]=x;
            }
            i++;
        }
        else if(isOp(infix[i]))
        {
            while(top!=-1&&sta[top]!='('&&pri(infix[i])<=pri(sta[top]))
            {
                postfix[ct++]=pop();
            }
            push(infix[i]);
            i++;
        }
        else if(isCh(infix[i]))
        {
            postfix[ct++]=infix[i];
            i++;
        }
        else
        {
            cout<<"Invalid Character!\n";
            cout<<"Exiting Code!\n";
            return;
        }
    }
    while(top!=-1)
        postfix[ct++]=pop();
    postfix[ct]='\0';
    cout<<"The Infix Expression:"<<infix<<endl;
    cout<<"The Postfix Expression:"<<postfix<<endl;
}
int main()
{
    infToPos();
}
