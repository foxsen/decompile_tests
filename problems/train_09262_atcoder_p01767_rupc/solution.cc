#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <ctime>
 
using namespace std;
 
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
#define mp make_pair
#define all(r) r.begin(),r.end()
#define fi first
#define se second
#define println(X) cout<<X<<endl;
#define DBG(X) cout<<#X<<" : "<<X<<endl;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-3;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

int main(){
	int n, m;
	cin>>n;
	vl a(n); 
	rep(i, n) cin>>a[i];
	cin>>m;
	vl b(m), c (m);
	rep(i, m) cin>>b[i];
	rep(i, m) cin>>c[i];

	sort(all(a));
	vl s(n+1);
	rep(i, n) s[i+1] = s[i]+a[i];

	for(int i = 0; i < m; i++){
		auto it = upper_bound(all(a), b[i]) - a.begin();
		//cout<<s[it]<<" ";
		if(s[it] >= c[i]) printf("Yes\n");
		else printf("No\n");
	}	
}