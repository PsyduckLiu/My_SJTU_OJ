#include<iostream>
using namespace std;

const int m=102;
int main()
{

	int L,i,j;
	int count=0;
	bool flag=true;
	int box[m][m]={0},tmp[m][m]={0};

	cin >> L;


	for (i=1;i<=L;i++){
    for (j=1;j<=L;j++){
        cin>>box[i][j];
        tmp[i][j] = box[i][j];
}}

    while (true) {
        for (i=1;i<=L;i++) {
        for (j=1;j<=L;j++) {
            if (box[i][j]==0){
                if (box[i+1][j]==1||box[i][j+1]==1||box[i][j-1]==1||box[i-1][j]==1){
                    tmp[i][j]=1;
}}}}
    count++;

    for (i=1;i<=L;i++) {
    for (j=1;j<=L;j++) {
        box[i][j]=tmp[i][j];
}
}

		flag=true;
		for (i=1;i<=L;i++) {
        for (j=1;j<=L;j++) {
            if (box[i][j]==0) {
                flag=false;
                break;
}}
               if (!flag) {
                break;
}}


            if (flag){
                break;
}
}

	cout << count;

	return 0;

}
