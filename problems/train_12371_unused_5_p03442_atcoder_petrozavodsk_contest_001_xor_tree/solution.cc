// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9,maxn=3e5+5,maxs=(1<<16) + 5;

int n,cnt[maxn],w[maxn],ans;
int goodst[maxs], dp[maxs];

int main(){	
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		++x;++y;
		w[x] ^= z;w[y] ^= z;
	}
	
	for(int i=1;i<=n;i++)++cnt[w[i]];
	for(int i=1;i<=15;i++)
		ans += cnt[i]/2, cnt[i]%=2;
	int lim=0;for(int i=1;i<=15;i++)lim |= (cnt[i] == 0?0:(1<<i)), ans += (cnt[i]!=0);
	for(int S=0;S<=(1<<16)-1;S++){
		int x=0;
		for(int i=0;i<=15;i++)
			if(S&(1<<i))x^=i;
		goodst[S] = 0;if(x==0)goodst[S] = 1;
	}
	
	for(int S=0;S<=(1<<16)-1;S++){
		if(S&1)continue;
		for(int T=S;T;T=(T-1)&S){
			if(goodst[T])
				dp[S] = max(dp[S], dp[S^T]+1);
		}
	}
	printf("%d\n",ans-dp[lim]);

	return 0;
}
