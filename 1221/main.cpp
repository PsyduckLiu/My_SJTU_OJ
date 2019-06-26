#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
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
    bool find(const T &x,node *&t) const
    {
        if(t==NULL) return false;
        if(t->data == x)
            return true;
        if(t->data < x)
            return find(x,t->right);
        if(t->data >= x)
            return find(x,t->left);
    }
    void insert(const T &x,node *&t)
    {
        if(t == NULL) {t = new node(x); return;}
        if(t->data >= x)
            insert(x,t->left);
        else
            insert(x,t->right);
    }
    void remove(const T &x,node *&t)
    {
        if(t == NULL) return;
        if(t->data > x)
            remove(x,t->left);
        else if(t->data < x)
            remove(x,t->right);
        else
        {
            if(t->left && t->right)
            {
                node *tmp = t->right;
                while(tmp->left) tmp = tmp->left;
                t->data = tmp->data;
                remove(t->data,t->right);
            }
            else if(!t->left && !t->right)
            {
                delete t;
                t = NULL;
            }
            else
            {
                node *old = t;
                t = (t->left ? t->left:t->right);
                delete old;
            }
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
    bool check(node *t,T &min,T &max) const
    {
        T mint,maxt;
        bool flag;
        if(t->left)
        {
            flag = check(t->left,min,maxt);
            if(!flag || maxt > t->data)
                return false;
        }
        else min=t->data;
        if(t->right)
        {
            flag = check(t->right,mint,max);
            if(!flag || mint < t->data)
                return false;
        }
        else max=t->data;
        return true;
    }
    void delete_less_than_x(const T &x,node *&t)
    {
        if(!t) return;
        if(t->data >= x)
            delete_less_than_x(x,t->left);
        else
        {
            node *tmp = t;
            t = t->right;
            makeEmpty(tmp->left);
            delete tmp;
            delete_less_than_x(x,t);
        }
    }
    void delete_greater_than_x(const T &x,node *&t)
    {
        if(!t) return;
        if(t->data <= x) delete_greater_than_x(x,t->right);
        else
        {
            node *tmp = t;
            t = t->left;
            makeEmpty(tmp->right);
            delete tmp;
            delete_greater_than_x(x,t);
        }
    }
    void delete_range(const T &x,const T &y,node *&t)
    {
        if(!t) return;
        if(t->data <= x) delete_range(x,y,t->right);
        else if(t->data >= y) delete_range(x,y,t->left);
        else
        {
            remove(t->data,t);
            delete_range(x,y,t);
        }
    }
    int size(node *t)
    {
        if(!t) return 0;
        else return (1+size(t->left)+size(t->right));
    }
    bool find_ith_min(int i,T &x,node *t)
    {
        if(!t) return false;
        int s = size(t->left);
        if(s == i-1) {x = t->data; return true;}
        else if(s >= i) return find_ith_min(i,x,t->left);
        else
            return find_ith_min(i-s-1,x,t->right);
    }
public:
    BinarySearchTree(node *t = NULL) {root = t;}
    ~BinarySearchTree() {makeEmpty(root);}
    bool find(const T &x) {return find(x,root);}
    void insert(const T &x) {insert(x,root);}
    void remove(const T &x) {remove(x,root);}

    bool check() const
    {
        int min,max;
        if(!root) return true;
        return check(root,min,max);
    }
    void delete_less_than_x(const T &x) {delete_less_than_x(x,root);}
    void delete_greater_than_x(const T &x) {delete_greater_than_x(x,root);}
    void delete_range(const T &x,const T &y) {
        if(x>=y) return;
        delete_range(x,y,root);
    }
    bool find_ith_min(int i,T &x)
    {
        return find_ith_min(i,x,root);
    }
};

int main()
{
    int n,x,y;
    scanf("%d",&n);
    BinarySearchTree<int> tree;
    for(int i=0;i<n;++i){
    char ch[20];
    scanf("%s",&ch);
    if(ch[0] == 'i') {scanf("%d",&x);tree.insert(x);}
    else if(strcmp(ch,"find")==0) {scanf("%d",&x);if(tree.find(x)) printf("Y\n"); else printf("N\n");}
    else if(strcmp(ch,"find_ith")==0){
        scanf("%d",&x);
        if(tree.find_ith_min(x,y)) printf("%d\n",y);
        else printf("N\n");
        }
    else if(strcmp(ch,"delete")==0) {scanf("%d",&x);tree.remove(x);}
    else if(strcmp(ch,"delete_less_than")==0) {scanf("%d",&x);tree.delete_less_than_x(x);}
    else if(strcmp(ch,"delete_greater_than")==0) {scanf("%d",&x);tree.delete_greater_than_x(x);}
    else {scanf("%d %d",&x,&y);tree.delete_range(x,y);}
    }
    return 0;
}
