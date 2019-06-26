#include <iostream>

using namespace std;
struct Node
{
	int left;
	int right;
	int data;
};

int main(){
	int i,n,l,r,data,root,head,rear;
	cin>>n;

	Node* node=new Node[n+1];
	bool *flag=new bool[n+1];
	int *queue=new int[n+1];
	for (i=0;i<=n;++i) flag[i]=true;
	for (i=1;i<=n;++i){
		cin>>l>>r>>data;
		node[i].left=l; node[i].right=r; node[i].data=data;
		flag[l]=false; flag[r]=false;
	}
	for (i=1;i<=n;++i){
		if (flag[i]) break;
	}
	root=i;
	head=0;rear=0;
	queue[head]=root;
	while (head!=n){
		if (node[queue[head]].left>0) queue[++rear]=node[queue[head]].left;
		if (node[queue[head]].right>0) queue[++rear]=node[queue[head]].right;
		cout<<node[queue[head]].data<<' ';
		head++;
	}
	return 0;

}
