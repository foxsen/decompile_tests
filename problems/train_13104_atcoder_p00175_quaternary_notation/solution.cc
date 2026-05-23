#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int i,j,k,cnt=1,flg;
	int n;
	int fo[10]={1,4,16,64,256,1024,4096,16384,65536,262144};
	while(1) {
		cin>>n;
		flg=0;
		if(n==-1) break;
		for(i=9;i>=0;i--) {
			if(n==0&&flg==0) {
				cout<<"0";
				break;
			}
			if(n/fo[i]>0&&n!=0) {
				cout<<n/fo[i];
				n=n%fo[i];
				flg=1;
			}
			else if(flg==1) cout<<"0";
		}
		cout<<endl;
	}
	return 0;
}