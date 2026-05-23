#include<bits/stdc++.h>
using namespace std;
long long ans,A,B,t,s,p;
long long i;
int main(){
	scanf("%lld%lld",&A,&B);
	ans=B-A+1;
	for(i=0;B>>i;i++)
		if(!(B>>i&1)){
			t=B>>i<<i;
			p=B>>i;
			s=(p-(p&-p)+1)<<i;
			if(t<=A)continue;
			if(s>=A)ans+=1ll<<i;
			else if(A-s<(1ll<<i))ans+=(1ll<<i)-A+s;
		}
	printf("%lld\n",ans);
}