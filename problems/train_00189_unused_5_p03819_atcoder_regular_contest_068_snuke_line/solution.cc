#include <bits/stdc++.h>
#define ll long long
#define INF 999999999
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef pair<int,int>P;

const int MAX_N = 100005;

vector<P> lens[100005];

int bit[MAX_N+1],n,m;
//i番目までの和を計算する
int sum(int i)
{
	int s = 0;
	while(i>0){
		s += bit[i];
		i -= i & -i;
	}
	return s;
}
//i番目の値にxを加える
void add(int i,int x)
{
	while(i <= MAX_N){
		bit[i] += x;
		i += i & -i;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	rep(i,n){
		int l,r;
		scanf("%d%d",&l,&r);
		r++;
		lens[r-l].push_back(P(l,r));	//rはr+1を指すようにする
	}
	printf("%d\n",n);
	int rest = n;
	for(int i=2;i<m+1;i++){	//iは間隔dのこと
		rep(j,lens[i-1].size()){
			add(lens[i-1][j].first,1);
			add(lens[i-1][j].second,-1);
			rest--;
		}
		int ans = rest;	//間隔がm以上の区間
		int it = i;
		while(it<=m){
			ans += sum(it);
			it += i;
		}
		printf("%d\n",ans);
	}
}
