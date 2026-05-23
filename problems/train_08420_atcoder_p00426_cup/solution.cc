#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int where[15];
int n;

ll calc(int a,int b){
	ll ans=1;
	if(b<=0)	return 0;
	for(int i=0;i<b;i++){
		ans*=a;
	}
	return ans-1;
}

ll check(bool left){
	ll ans=0;
	for(int i=0;i<n;i++){
		int now=left?0:2;
		if(abs(now-where[i])==2){
			ans+=2*calc(3,n-i-1)+2;
		}
		else if(where[i]==1){
			ans+=calc(3,n-i-1)+1;
			left^=1;
		}
	}
	return ans;
}

int main(){
	refrain:;
	int m;	cin>>n>>m;
	if((n|m)==0)	return 0;
	int num,in;
	for(int i=0;i<3;i++){
		cin>>num;
		for(int j=0;j<num;j++){
			cin>>in;
			where[in-1]=i;
		}
	}
	ll ans=min(check(true),check(false));
	if(ans<=m)	cout<<max(0LL,ans)<<endl;
	else 	cout<<-1<<endl;
	goto refrain;
}