#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,m;cin >> n >> m;
	vector<int> a(m);
	vector<int> b(m);
	vector<ll> c(m);
	rep(i,m){
		cin >> a.at(i) >> b.at(i) >> c.at(i);
		a.at(i)--;
		b.at(i)--;
	}
	ll MIN=-1000000000000000000;
	vector<ll> dist(n,MIN);
	dist.at(0)=0;
	rep(i,n){
		rep(j,m){
			dist[b[j]]=max(dist[b[j]],dist[a[j]]+c[j]);
		}
	}
	ll ans=dist[n-1];
	rep(i,n){
		rep(j,m){
			dist[b[j]]=max(dist[b[j]],dist[a[j]]+c[j]);
		}
	}
	if(ans!=dist[n-1]) cout << "inf" << endl;
	else cout << dist[n-1] << endl;
}