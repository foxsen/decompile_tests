#include<iostream>
#include<algorithm>
using namespace std;
int n,q,r,l;
long long s,t,a[200010],d[200010],x;

int main(){

	cin>>n>>q>>s>>t;
	for(int i=0;i<=n;i++)cin>>a[i];
	long long cnt=0;
	for(int i=0;i<n;i++){
		d[i]=a[i+1]-a[i];
		if(d[i]<0)cnt-=t*d[i];
		if(d[i]>0)cnt-=s*d[i];
	}
	while(q--){
		cin>>l>>r>>x;l--;
		if(d[l]<0)cnt+=t*d[l];
		if(d[l]>0)cnt+=s*d[l];
		d[l]+=x;
		if(d[l]<0)cnt-=t*d[l];
		if(d[l]>0)cnt-=s*d[l];

		if(r<n){
		if(d[r]<0)cnt+=t*d[r];
		if(d[r]>0)cnt+=s*d[r];
		d[r]-=x;
		if(d[r]<0)cnt-=t*d[r];
		if(d[r]>0)cnt-=s*d[r];
		}

		cout<<cnt<<endl;
	}
	return 0;
}