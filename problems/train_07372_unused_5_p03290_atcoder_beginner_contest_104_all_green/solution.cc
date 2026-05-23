#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1000000007

ll n,g,a[12],c[12],ans=1<<30;
bool s[12];

void cal(){
	ll sum=0,score=0;
	for(int i=0;i<n;i++){
		if(s[i]){
			sum+=a[i];
			score+=a[i]*(i+1)*100+c[i];
		}
	}
	if(score>=g){
		ans=min(ans,sum);
		return ;
	}
	for(int i=n-1;i>=0;i--){
		ll k=(i+1)*100;
		if(s[i]==0&&(g-score+k-1)/k<=a[i]){
			sum+=(g-score+k-1)/k;
			ans=min(ans,sum);
			return ;
		}
	}
}

void dep(ll d){
	if(d==n){
		cal();
		return;
	}
	s[d]=0;dep(d+1);
	s[d]=1;dep(d+1);
}

int main() {
	cin>>n>>g;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	dep(0);
	cout <<ans;
	return 0;
}