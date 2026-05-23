#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll L;
string s;

int nxt[200050][2],cnt;

ll lowbit(ll x){return x&-x;}
void insert(string t){
	int p=0; 
	for(int i=0;i<t.size();++i){
		int x=t[i]-'0';
		if(nxt[p][x]==0){
			nxt[p][x]=++cnt;
		}
		p=nxt[p][x];
	}
}
ll query(int p,int d){
	if(!p&&d){return lowbit(L-d+1);}
	return query(nxt[p][0],d+1)^query(nxt[p][1],d+1);
}
void solve(){
	cin>>N>>L;
	//cerr<<N<<" "<<L<<endl; 
	for(int i=1;i<=N;++i){
		cin>>s;
		insert(s);
	}
	//cerr<<cnt<<endl;
	//cerr<<query(0,0)<<endl;
	if(query(0,0)==0)puts("Bob");
	else puts("Alice");
}
int main(){
	solve();
	return 0;
}