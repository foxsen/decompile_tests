#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (int) (l);i < (int) (r);i++)
#define ALL(x) x.begin(),x.end()
template<typename T> bool chmax(T& a,const T& b){ return a < b ? (a = b,true) : false; }
template<typename T> bool chmin(T& a,const T& b){ return b < a ? (a = b,true) : false; }
typedef long long ll;

int N;
vector<int> edge [100001];
int dp [100001];

int dfs(int curr,int prev)
{
	int res = 0;
	vector<int> v;
	bool leaf = true;
	for(const auto& it : edge [curr]) if(it != prev){
		chmax(res,dfs(it,curr));
		v.push_back(dp [it]);
		leaf = false;
	}
	if(leaf) v.push_back(0);
	sort(v.rbegin(),v.rend());
	if(v.size() >= 2){
		chmax(res,v [0] + v [1] + (edge [curr].size() == 2));
		dp [curr] = v [0] + (edge [curr].size() == 2);
	}
	else if(v.size() == 1){
		chmax(res,v [0] + (edge [curr].size() == 2));
		dp [curr] = v [0] + (edge [curr].size() == 2);
	}
	return res;
}

int main()
{
	scanf("%d",&N);
	FOR(i,0,N - 1){
		int u,v;
		scanf("%d%d",&u,&v);
		edge [u].push_back(v);
		edge [v].push_back(u);
	}
	int ans = 0;
	FOR(i,1,N + 1){
		ans += edge [i].size() == 1;
	}
	ans += dfs(1,-1);

	printf("%d\n",ans);

	return 0;
}
