#include<iostream>
#include <cstdio>
using namespace std;
 
class linkStack
{
private:
    struct node
    {
        int data;
        node *next;
        node(const int &x, node *N = NULL)
        {
            data = x;
            next = N;
        }
        node() :next(NULL) {}
        ~node() {}
    };
    node * elem;
public:
    linkStack()
    {
        elem = NULL;
    }
    ~linkStack()
    {
        node *tmp;
        while (elem != NULL)
        {
            tmp = elem;
            elem = elem->next;
            delete tmp;
        }
    }
 
    bool isEmpty() const
    {
        return elem == NULL;
    }
    void push(const int &x)
    {
        node * tmp = new node(x, elem);
        elem = tmp;
    }
    int pop()
    {
        node *tmp = elem;
        int x = tmp->data;
        elem = elem->next;
        delete tmp;
        return x;
    }
    int top() const
    {
        return elem->data;
    }
};
class linkQueue
{
private:
    struct node
    {
        int data;
        node * next;
        node(const int &x, node *N = NULL)
        {
            data = x;
            next = N;
        }
        node() :next(NULL) {}
        ~node() {}
    };
    node *front, *rear;
public:
    linkQueue()
    {
        front = rear = NULL;
    }
    ~linkQueue()
    {
        node * tmp;
        while (front != NULL)
        {
            tmp = front;
            front = front->next;
            delete tmp;
        }
    }
    bool isEmpty()
    {
        return front == NULL;
    }
    void enQueue(const int &x)
    {
        if (rear == NULL)
            front = rear = new node(x);
        else
        {
            rear->next = new node(x);
            rear = rear->next;
        }
    }
    int deQueue()
    {
        node *tmp = front;
        int value = front->data;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete tmp;
        return value;
    }
    int getHead()
    {
        return front->data;
    }
};
 
class priorityQueue
{
public:
    priorityQueue(int capacity = 100)
    {
        array = new int[capacity];
        maxSize = capacity;
        currentSize = 0;
    }
    priorityQueue(const int *data, int size);
    ~priorityQueue()
    {
        delete[] array;
    }
    bool isEmpty() const
    {
        return currentSize == 0;
    }
    void enQueue(const int &x);
    int deQueue();
    int getHead() const
    {
        return array[1];
    }
private:
    int currentSize;
    int * array;
    int maxSize;
    void doubleSpace();
    void buildHeap();
    void percolateDown(int hole);
 
};
 
 
 
 
void priorityQueue::enQueue(const int &x)
{
    if (currentSize == maxSize - 1)
        doubleSpace();
    int hole = ++currentSize;
    for (; hole > 1 && x < array[hole / 2]; hole /= 2)
        array[hole] = array[hole / 2];
    array[hole] = x;
}
int priorityQueue::deQueue()
{
    int minItem;
    minItem = array[1];
    array[1] = array[currentSize--];
    percolateDown(1);
    return minItem;
}
 
void priorityQueue::percolateDown(int hole)
{
    int child;
    int tmp = array[hole];
    for (; hole * 2 <= currentSize; hole = child)
    {
        child = hole * 2;
        if (child != currentSize && array[child + 1] < array[child])
            child++;
        if (array[child] < tmp)
            array[hole] = array[child];
        else
            break;
    }
    array[hole] = tmp;
}
 
void priorityQueue::buildHeap()
 
{
 
    for (int i = currentSize / 2; i > 0; --i)
 
        percolateDown(i);
 
}
 
 
priorityQueue::priorityQueue(const int *items, int size) :maxSize(size + 10), currentSize(size)
 
{
 
    array = new int[maxSize];
 
    for (int i = 0; i < size; ++i)
 
        array[i + 1] = items[i];
 
    buildHeap();
 
}
 
void priorityQueue::doubleSpace()
 
{
 
    int *tmp = array;
 
 
 
    maxSize *= 2;
 
    array = new int[maxSize];
 
 
 
    for (int i = 0; i <= currentSize; ++i)
 
        array[i] = tmp[i];
 
 
 
    delete[] tmp;
 
}
 
class tree1117
 
{
 
private:
 
    struct node
    {
 
        int data;
 
        int parent,num_sons;
 
    };
 
 
 
 
 
    int length, root;
 
public:
 
    node * elem;
 
 
 
    tree1117();
 
 
 
    ~tree1117()
    {
        delete[] elem;
    }
 
 
 
    int getRoot()
    {
        return root;
    }
 
 
 
    void del()
 
    {
 
        priorityQueue pq(length);
 
        linkStack s;
 
        int tmp,i,j,flag=0;
 
        for (i = 1; i <= length; ++i)
 
            if (elem[i].num_sons == 0)
 
            {
 
                pq.enQueue(i);
 
            }
 
 
 
        if (elem[root].num_sons == 1)
 
        {
 
            flag = 1;
 
            tmp = pq.getHead();
 
            pq.enQueue(root);
 
 
 
            while (tmp != root)
 
            {
 
                s.push(tmp);
 
                tmp = elem[tmp].parent;
 
            }
 
        }
 
 
 
 
 
        for (i = 0; i < length - 2; ++i)
 
        {
 
            tmp = pq.deQueue();
 
            if (tmp != root)
 
            {
 
                printf("%d ", elem[tmp].parent);
 
                if (--elem[elem[tmp].parent].num_sons == 0)
 
                    pq.enQueue(elem[tmp].parent);
 
            }
 
            else
 
            {
 
                printf("%d ", s.top());
 
                root = s.top();
 
                pq.enQueue(s.pop());
 
            }
 
 
 
            if (elem[root].num_sons == 1 && flag == 0)
 
            {
 
                flag = 1;
 
                tmp = pq.getHead();
 
                pq.enQueue(root);
 
 
 
                while (tmp != root)
 
                {
 
                    s.push(tmp);
 
                    tmp = elem[tmp].parent;
 
                }
 
            }
 
 
 
        }
 
 
 
        i = pq.deQueue();
 
        j = pq.deQueue();
 
        if (j > i)
 
            printf("%d", j);
 
        else
 
            printf("%d", i);
 
 
 
 
 
    }
 
};
 
 
tree1117::tree1117()
 
{
 
    linkQueue que;
 
    linkStack makeTree,last;
 
 
 
    char tmp;
 
    int value = 0,max = 0,current,cnt;
 
 
 
    while (scanf("%c",&tmp))
 
    {
 
        if(tmp == '\n')
 
            break;
 
 
 
        if(tmp <= '9' && tmp >= '0')
 
            value = 10 * value + tmp - '0';
 
        else
 
            if (tmp == '(')
 
            {
 
                if (value)
 
                {
 
                    que.enQueue(value);
 
                    if (value > max)
 
                        max = value;
 
                    value = 0;
 
                }
 
            }
 
 
 
            else
 
                if (tmp == ')')
 
                {
 
                    if (value)
 
                    {
 
                        que.enQueue(value);
 
                        que.enQueue(0);
 
                        if (value > max)
 
                            max = value;
 
                        value = 0;
 
                    }
 
                    else
 
                        que.enQueue(0);
 
                }
 
 
 
    }
 
 
 
    length = max;
 
    elem = new node[max + 1];
 
    while (!que.isEmpty())
 
    {
 
        current = que.deQueue();
 
        if (current > 0)
 
        {
 
            makeTree.push(current);
 
            last.push(current);
 
        }
 
        else
 
            if (current == 0)
 
            {
 
                cnt = 0;
 
                while (!last.isEmpty() && !makeTree.isEmpty() && makeTree.top() < 0)
 
                {
 
                    elem[-makeTree.top()].parent = last.top();
 
                    makeTree.pop();
 
                    cnt++;
 
                }
 
                elem[last.top()].num_sons = cnt;
 
                root = last.top();
 
                makeTree.pop();
 
                makeTree.push(-last.pop());
 
            }
 
 
 
    }
 
 
 
}
 
 
 
 
 
int main()
 
{
 
    tree1117 tree;
 
    tree.del();
 
    cout << endl;
 
 
 
    return 0;
 
}
