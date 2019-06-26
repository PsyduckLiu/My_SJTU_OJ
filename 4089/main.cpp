#include <iostream>

using namespace std;
class node{
public:
int data;
node *next;

};
int main()
{node *head,*p,*q;
   int n,m,i,j;

   cin>>n>>m;
   head=p=new node;
   p->data=1;
   for (i=2;i<n+1;i++) {
    q=new node;
    q->data=i;
    p->next=q;
    p=q;
   }
   p->next=head;

   q=head;
   p=head;
   while (q->next!=q) {
    for (j=0;j<m-1;j++) p=p->next;
    q=p->next;
    p->next=q->next;
    cout<<q->data<<' ';
    delete q;
    q=p->next;
   }
   cout<<q->data;

    return 0;
}
