#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[100010],b[100010];
int n,ans;
map<LL,int>mp;
LL sqr(LL x){return x*x;}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		LL x;
		scanf("%lld",&x);
		for(LL j=2;j*j*j<=x;j++) for(;x%(j*j*j)==0;x/=j*j*j);
		mp[x]++;
		a[i]=x;
		LL y=1;
		for(LL j=2;j*j*j<=x;j++) if(x%j==0){
			y*=(x%(j*j)==0)?j:j*j;
			for(;x%j==0;x/=j);
		}
		if(sqr((LL)sqrt(x))==x) y*=(LL)sqrt(x);
		else y*=x*x;
		b[i]=y;
	}
	if(mp[1]) ans++,mp[1]=0;
	for(int i=1;i<=n;i++){
		ans+=max(mp[a[i]],mp[b[i]]);
		mp[a[i]]=mp[b[i]]=0;
	}
	printf("%d",ans);
	return 0;
}
/*
8
1
2
3
4
5
6
7
8
*/