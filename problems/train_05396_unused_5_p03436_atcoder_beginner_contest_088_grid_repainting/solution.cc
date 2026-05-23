#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;

const ll dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
char s[100][100];
ll n,m,sum,d[100][100];
struct node{
	ll x,y;
};
queue<node> q;

inline void bfs(){
	q.push(node{1,1}); d[1][1]=1;
	while(!q.empty()){
		ll x=q.front().x,y=q.front().y; q.pop();
		for(ll i=0; i<4; i++){
			ll X=x+dx[i],Y=y+dy[i];
			if(X>=1&&X<=n&&Y>=1&&Y<=m&&!d[X][Y]&&s[X][Y]=='.'){
				q.push(node{X,Y});
				d[X][Y]=d[x][y]+1;
				if(X==n&&Y==m) return;
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(ll i=1; i<=n; i++){
		scanf("%s",s[i]+1);
		for(ll j=1; j<=m; j++){
			if(s[i][j]=='.') sum++;
		}
	}
	bfs();
	if(d[n][m]) cout<<sum-d[n][m]<<endl;
	else cout<<-1<<endl;
	return 0;
}