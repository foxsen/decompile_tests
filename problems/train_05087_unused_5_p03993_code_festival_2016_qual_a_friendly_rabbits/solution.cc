#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[100000];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ans=0;
	for(int i=0;i<n;i++)
		ans+=a[a[i]-1]-1==i;
	cout<<ans/2<<endl;
}
