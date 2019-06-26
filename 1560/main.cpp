#include <iostream>
#include <cstdio>

using namespace std;
template<class T>
class seqQueue
{
private:
    T *data;
    int maxSize;
    int front;
    int rear;
    void doubleSpace()
    {
        T *tmp = data;
        data = new T[maxSize*2];
        for(int i=1;i<maxSize;++i)
            data[i] = tmp[(front+i)%maxSize];
        front = 0;
        rear = maxSize-1;
        maxSize *= 2;
        delete tmp;
    }
public:
    seqQueue(int init = 10) {
        maxSize = init;
        data = new T[maxSize];
        front = rear = 0;
    }
    ~seqQueue() {delete [] data;}
    bool isEmpty() const {return rear==front;}
    void enqueue(const T &x)
    {
        if((rear+1)%maxSize == front)
            doubleSpace();
        rear = (rear+1)%maxSize;
        data[rear] = x;
    }
    T getHead() const
    {
        return data[(front+1)%maxSize];
    }
    T getTail() const
    {
        return data[rear];
    }
    T dequeue()
    {
        front = (front+1)%maxSize;
        return data[front];
    }
};

template<class T>
class BinarySearchTree
{
private:
    struct node
    {
        node *left;
        node *right;
        T data;
        node(const T &d = 0,node *le = NULL,node *ri = NULL):data(d),left(le),right(ri) {}
    };
    node *root;

    void insert(const T &x,node *&t)
    {
        if(t == NULL) {t = new node(x); return;}
        if(t->data == x) return;
        if(t->data > x)  insert(x,t->left);
        else            insert(x,t->right);
    }

    void remove(const T &x,node *&t)
    {
        if(t==NULL) return;
        if(t->data > x)
            remove(x,t->left);
        else if(t->data < x)
            remove(x,t->right);
        else if(!t->right)
        {
            node *old = t;
            t=t->left;
            delete old;
        }
        else
        {
            node *tmp=t->right,*rtmp=t->right;
            if(!tmp->left)
            {
                t->data=tmp->data;
                t->right=tmp->right;
                delete tmp;
                return;
            }
            while(tmp->left!=NULL)
            {
                rtmp=tmp;
                tmp=tmp->left;
            }
            t->data=tmp->data;
            rtmp->left=tmp->right;
            delete tmp;
        }
    }

    void makeEmpty(node *&t)
    {
        if(t==NULL) return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = NULL;
    }

public:
    BinarySearchTree(node *t = NULL) {root = t;}
    ~BinarySearchTree() {makeEmpty(root);}

    void find2(const T &x)
    {
        seqQueue<int> s;
        bool flag=false;
        node *tmp=root;
        int p;
        while(tmp)
        {
            if(tmp->data==x)
            {
                flag = true;
                printf("*");
                while(!s.isEmpty())
                    p=s.dequeue() ? printf("l"):printf("r");
                break;
            }
            else if(tmp->data>x)
            {
                s.enqueue(1);
                tmp=tmp->left;
            }
            else
            {
                s.enqueue(0);
                tmp=tmp->right;
            }
        }
        if(!flag) printf("Nothing.");
        printf("\n");
    }
    void insert(const T &x) {insert(x,root);}
    void remove(const T &x) {remove(x,root);}
};

int main()
{
    int Q,x;
    char ch;
    BinarySearchTree<int> tree;
    scanf("%d",&Q);
    while(Q--)
    {
        getchar();
        ch = getchar();
        scanf("%d",&x);
        switch(ch)
        {
        case '+':
            tree.insert(x); break;
        case '-':
            tree.remove(x); break;
        case '*':
            tree.find2(x);
        }
    }
    return 0;
}
