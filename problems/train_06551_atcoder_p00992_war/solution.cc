#include<bits/stdc++.h>
using namespace std;
int main(){
	long int s=1;
	int a[500],n,i,c=0;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	sort(a,a+n-1);
    for(i=n-1;i>=0;i--,c++){
    	if((a[i]-c/4)<0)continue;
    	else s+=a[i]-c/4;
    }
    cout<<s<<endl;
	return 0;
}