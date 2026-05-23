#include<bits/stdc++.h>
using namespace std;
#define N 200005
long long n,O[N],X[N],Pow[N],mo=998244353,ans;
struct V {
	long long x,y;
	bool operator <(const V a)const {
		return y<a.y;
	}
} A[N];
long long _1[N],_2[N],_3[N],_4[N];
void ADD(int o) {
	while(o<=n)O[o]++,o+=o&-o;
}
int SUM(int o) {
	int sum=0;
	while(o)sum+=O[o],o-=o&-o;
	return sum;
}
int main() {
	scanf("%lld",&n);
	for(int i=1; i<=n; i++)scanf("%lld %lld",&A[i].x,&A[i].y),X[i]=A[i].x;
	sort(A+1,A+n+1);
	sort(X+1,X+n+1);
	for(int i=1; i<=n; i++) {
		A[i].x=lower_bound(X+1,X+n+1,A[i].x)-X;
		_3[i]=SUM(A[i].x),_4[i]=i-1-_3[i];
		ADD(A[i].x);
	}
	memset(O,0,sizeof(O));
	for(int i=n; i; i--) {
		_2[i]=SUM(A[i].x),_1[i]=n-i-_2[i];
		ADD(A[i].x);
	}
	Pow[0]=1;
	for(int i=1; i<=n; i++) Pow[i]=Pow[i-1]*2%mo;
	for(int i=1; i<=n; i++) {
		ans+=((Pow[_1[i]]-1)*(Pow[_3[i]]-1)%mo)*(Pow[_2[i]]+Pow[_4[i]]-1)%mo;
		ans+=((Pow[_2[i]]-1)*(Pow[_4[i]]-1)%mo)*(Pow[_3[i]]+Pow[_1[i]]-1)%mo;
		ans+=((((Pow[_2[i]]-1)*(Pow[_4[i]]-1)%mo)*(Pow[_3[i]]-1)%mo)*(Pow[_1[i]]-1))%mo;
		ans+=Pow[n-1];//1
		ans%=mo;
	}
	printf("%lld\n",ans);
	return 0;
}