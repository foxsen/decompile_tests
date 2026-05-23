#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef pair<int,int>P;
typedef pair<P,P>P2;

int dp[111][111][1<<5];
int n,m,e,s,t,r;

vector<P>v[100000];

signed main(){
  r(i,111)r(j,1<<5)r(k,111)dp[i][k][j]=1e9;
  cin>>n>>m>>e>>s>>t>>r;

  r(i,m){
    int a,b;
    cin>>a>>b;
    v[a].push_back(P(b,-1));
    v[b].push_back(P(a,-1));
  }

  map<int,int>M;
  int state=0;

  r(i,e){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back(P(b,i));
    v[b].push_back(P(a,i));

    M[c] = i;
    if(c==s)state|=(1<<i);
  }

  priority_queue<P2,vector<P2>,greater<P2> > q;

  q.push(P2(P(0,s),P(r,state))); /// warning

  dp[s][r][state]=0;

  while(!q.empty()){
    P2 PP=q.top();q.pop();

    int now=PP.first.second;
    int cost=PP.first.first;
    int R = PP.second.first;
    int S = PP.second.second;

    // cout<<cost<<' '<<now<<' '<<R<<' '<<S<<endl;

    if(dp[now][R][S] < cost)continue;

    // cout<<cost<<' '<<now<<' '<<R<<' '<<S<<endl;

    if(R){
      r(i,v[now].size()){
	int nex = v[now][i].first;
	int flag = v[now][i].second;

	int f=flag%100;
	int nR=R-1;

	int nS = S;
	if(M.count(nex))nS= (nS|(1<<M[nex]));

	if(flag == -1){

	  if(dp[nex][nR][nS] <= cost+1)continue;
	  dp[nex][nR][nS] = cost+1;
	  q.push(P2(P(cost+1,nex),P(nR,nS)));
	}
	else{
	  if(!(S&(1<<f)))continue;

	  if(dp[nex][nR][nS] <= cost+1)continue;
	  dp[nex][nR][nS] = cost+1;
	  q.push(P2(P(cost+1,nex),P(nR,nS)));
	}
      }
    }

    if(dp[s][r][S] <= cost+1)continue;
    dp[s][r][S] = cost+1;
    q.push(P2(P(cost+1,s),P(r,S)));
  }


  int ans= 1e9;

  r(i,101)r(j,(1<<5)){
    ans=min(ans,dp[t][i][j]);
  }

  if(ans==1e9)cout<<-1<<endl;
  else cout<<ans<<endl;

  
  
  
}



