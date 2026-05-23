#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
int main(){
int n,m;
	while(cin>>n>>m,n!=0||m!=0){
	int a[1000]={0},ans=0;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n,greater<int>());
		if(n>=m){
			for(int i=0;i<n;i++){
				if((i+1)%m==0){
				a[i]=0;
				}
				}
			}
		for(int i=0;i<n;i++)ans+=a[i];
		cout<<ans<<endl;
	}
	return 0;
}