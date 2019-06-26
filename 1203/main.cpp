#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
class linear
{
    class node{
    public:
        T data;

        node*next;
        node*front;
        node(T mes) :data(mes), next(NULL),front(NULL) {}
        node(T mes, node*bef) :data(mes), next(NULL) { bef->next=this; front = bef; }
};
    private:
        node*first;
    public:
    linear(T arr[], int n){
        first=new node(arr[0]);
        node*front = first;
        for (int i = 1; i < n; i++){
        node*next = new node(arr[i], front);
        next->front = front;
        front = next;
}    }
     friend linear& operator+(linear& lhs,const linear& rhs){
        node*p = lhs.first;
        while(p->next)p = p->next;
        rhs.first->front = p;
        p->next = rhs.first;
        return lhs;}

    friend ostream& operator<<(ostream&os, const linear&ob){
        node*p = ob.first;
        do{
        cout << p->data << " ";
        p = p->next;
        } while (p);
        return os;

    }

};


int main()
{
    string type;
    int num1, num2;
    cin >> type;
    cin >> num1 >> num2;
    if (type == "int"){
    int arr1[10000], arr2[10000];
        for (int i = 0; i < num1; i++)cin >> arr1[i];
        for (int i = 0; i < num1; i++)cin >> arr2[i];
        linear<int>l1(arr1, num1); linear<int>l2(arr2, num2);
        cout << l1+l2;
    }

    else if (type == "char"){
    char arr1[10000], arr2[10000];
        for (int i = 0; i < num1; i++)cin >> arr1[i];
        for (int i = 0; i < num1; i++)cin >> arr2[i];
        linear<char>l1(arr1, num1); linear<char>l2(arr2, num2);
        cout << l1 + l2;}

    else if (type == "double"){
    double arr1[10000], arr2[10000];
        for (int i = 0; i < num1; i++)cin >> arr1[i];
        for (int i = 0; i < num1; i++)cin >> arr2[i];
        linear<double>l1(arr1, num1); linear<double>l2(arr2, num2);
        cout << l1 + l2;
}
           return 0;
}
