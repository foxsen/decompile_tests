#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<int,int> P;

int dp[15][1<<15];
P prv[15][1<<15];
bool g[15][15];
int n,m,s,t,k[15],l;
vector<int> r[15];
int INF = (1<<10);

string itos(int a){
  if(!a)return "0";
  string res;
  while(a){
    res += a%10+'0';
    a/=10;
  }
  for(int i=0;i<(int)res.size()/2;i++)swap(res[i],res[(int)res.size()-1-i]);
  return res;
}

int main(){
  while(cin >> n >> m && (n || m)){
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)g[i][j] = false;

    for(int i=0;i<m;i++){
      cin >> s >> t;
      s--;t--;
      g[s][t] = g[t][s] = true;
    }

    l = 0;
    for(int i=0;i<n;i++){
      int tmp;
      cin >> tmp;
      l += (tmp<<i);
    }

    for(int i=0;i<n;i++){
      cin >> k[i];
      r[i].clear();
      r[i].resize(k[i]);
      for(int j=0;j<k[i];j++){
	cin >> r[i][j];
	r[i][j]--;
      }
      sort(r[i].begin(),r[i].end());
    }

    for(int i=0;i<n;i++)
      for(int j=0;j<(1<<n);j++){
	dp[i][j] = INF;
	prv[i][j] = make_pair(-1,-1);
      }
    dp[0][l] = 0;

    queue<P> q;
    q.push(make_pair(0,l));
     
    if(!(l&1)){
      cout << "Help me!\n";
      continue;
    }
    
    while(q.size()){
      P p = q.front();q.pop();
      int room = p.first, state = p.second;

      for(int i=0;i<k[room];i++){
	if(r[room][i]==room)continue;
	int tmp = 1<<r[room][i];
	int hoge = state;
	if(state & tmp)hoge -= tmp;
	else hoge += tmp;
	if(dp[room][hoge] > dp[room][state]+1){
	  dp[room][hoge] = dp[room][state]+1;
	  prv[room][hoge] = P(room,state);
	  q.push(P(room,hoge));
	}
      }

      for(int j=0;j<n;j++){
	if(g[room][j] && (state & (1<<j))){
	  if(dp[j][state] > dp[room][state]+1){
	    dp[j][state] = dp[room][state]+1;
	    prv[j][state] = P(room,state);
	    q.push(P(j,state));
	  }
	}
      }
    }
    
    int m = INF;
    for(int i=0;i<(1<<n);i++)m = min(m,dp[n-1][i]);
    if(m==INF)cout << "Help me!\n";
    else if(dp[n-1][1<<(n-1)]==INF)cout << "You can not switch off all lights.\n";
    else{
      cout << "You can go home in " << dp[n-1][1<<(n-1)] << " steps.\n";

      vector<string> ans;
      int room = n-1,state = 1<<(n-1);
      for(;;){
	int prvr = prv[room][state].first;
	int prvs = prv[room][state].second;
	if(prvr<0 && prvs<0)break; 
	if(prvr != room)ans.push_back("Move to room " + itos(room+1) + ".\n");
	else{
	  for(int i=0;i<n;i++){
	    if( (prvs & (1<<i)) && !(state & (1<<i)) ){
	      ans.push_back("Switch off room " + itos(i+1) + ".\n");
	      break;
	    }else if( !(prvs & (1<<i)) && (state & (1<<i)) ){
	      ans.push_back("Switch on room " + itos(i+1) + ".\n");
	      break;
	    }
	  }
	}
	room = prvr;
	state = prvs;
      }
      for(int i=(int)ans.size()-1;i>=0;i--)cout << ans[i];
    }
  }
}