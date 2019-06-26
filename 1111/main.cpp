#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 1000+5;
int total;
char tree[maxn];
void traverse(int cur,char preOrder[],int le1,int ri1,char inOrder[],int le2,int ri2)
{
    int i;
    if(ri1 < le1 || ri2 < le2) return;
    if(cur > total) total = cur;
    tree[cur] = preOrder[le1];
    if(ri1 == le1 || ri2==le2) return;
    for(i=le2;i<=ri2;++i)
        if(inOrder[i] == preOrder[le1]) break;
    int number = i-le2;
    traverse(2*cur,preOrder,le1+1,le1+number,inOrder,le2,i-1);
    traverse(2*cur+1,preOrder,le1+number+1,ri1,inOrder,i+1,ri2);
}

int main()
{
    for(int i=0;i<maxn;++i) tree[i] = NULL;
    char preOrder[maxn],inOrder[maxn];
    cin.getline(preOrder,maxn);
    cin.getline(inOrder,maxn);
    traverse(1,preOrder,0,strlen(preOrder)-1,inOrder,0,strlen(inOrder)-1);
    for(int i=1;i<=total;++i) {
        if(tree[i]==NULL)  cout<<"NULL ";
        else          cout<<tree[i]<<" ";
    }
    return 0;
}
