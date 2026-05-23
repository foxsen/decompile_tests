#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define len(x) (int)x.length()
#define pii pair<int,int>
#define ppi pair<pii,int>
#define vi vector<int>
#define mp make_pair
#define minheap priority_queue<int,vector<int>,greater<int>>
const int inf = 1e18;
vector<vector<pii> > g;

int dp[200001][2][2];

int32_t main(){
FAST
    int n,m;
    cin >> n>> m;
    g.resize(n);
    while(m--) {
    	int u,v,w;
    	cin>>u>>v>>w;
    	u--; v--;
    	g[u].pb({v,w});
    	g[v].pb({u,w});
    }
    set<pair<int,array<int,3>> > q;
    q.insert({0,{0,0,0}});

    for(int i=0;i<n;i++) {
    	for(int j=0;j<2;j++) {
    		for(int k=0;k<2;k++) {
    			dp[i][j][k] = inf;
    		}
    	}
    }

    dp[0][0][0] = 0;

    while(!q.empty()) {
    	int u  = q.begin()->second[0];
    	int mx = q.begin()->second[1];
    	int mn = q.begin()->second[2];

    	q.erase(q.begin());
    	//cout<<u<<": ";
    	for(pii &p:g[u]) {
    		int v = p.F,w = p.S;
    		//cout<<v<<" "<<w<<'\n';
    		for(int i=mx;i<2;i++) {
    			for(int j=mn;j<2;j++) {
    				int wt = w*(1-i+j+mx-mn);
    				if(dp[v][i][j] > dp[u][mx][mn] + wt) {
    					auto it = q.find({dp[v][i][j],{v,i,j}});
    					if(it != q.end()) {
    						q.erase(it);
    					}
    					dp[v][i][j] = dp[u][mx][mn] + wt;
    					q.insert({dp[v][i][j],{v,i,j}});
    				}
    			}
    		}
    	}
    }

    for(int i=1;i<n;i++) {
    	cout<<dp[i][1][1]<<' ';
    }

}