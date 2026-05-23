#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <sstream>

using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
const double EPS=1e-6;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SZ(a) (int)((a).size())
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) a.rbegin(),a.rend()
#define FLL(a,b) memset((a),b,sizeof(a))
#define CLR(a) FLL(a,0)
#define declare(a,it) __typeof(a) it=(a)
#define FOR(it,a) for(declare(a.begin(),it);it!=a.end();++it)
#define FORR(it,a) for(declare(a.rbegin(),it);it!=a.rend();++it)
template<class T,class U> ostream& operator<< (ostream& o, const pair<T,U>& v){return o << "(" << v.F << ", " << v.S << ")";}
template<class T> ostream& operator<< (ostream& o, const vector<T>& v){o << "{";rep(i,SZ(v)) o << (i?", ":"") << v[i];return o << "}";}
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,-1,1,1,-1};
int s2i(string& a){stringstream ss(a);int r;ss>>r;return r;}
int geti(){int n;scanf("%d", &n);return n;}

bool vis[50][50][1<<10];
int d[100],e[100];
int num[1100];
int idx[100];
vector<PI> G[100],rG[100];

int memo[50][50][1<<10];
int n,m;
int rec(int st,int cv1,int cv2){
  if(cv1 == n-1 && cv2 == n-1) return 0;
  assert(st < (1<<10));
  if(memo[cv1][cv2][st] >= 0)
    return memo[cv1][cv2][st];
  int& ret = memo[cv1][cv2][st] = 1<<28;

  int mia = min(e[cv1], e[cv2]);
  if(mia == e[cv1]){
    for(auto ed : G[cv1]){
      int nc = ed.S + d[ed.F];
      if((e[ed.F] == mia && ((st>>idx[ed.F])&1)) || ed.F == cv2)
        nc -= d[ed.F];
      int nst = st;
      int nmia = min(e[ed.F], e[cv2]);
      if(mia != nmia)
        nst = 0;
          
      if(nmia == e[ed.F]) nst |= 1 << idx[ed.F];
      if(nmia == e[cv2]) nst |= 1 << idx[cv2];
      ret = min(ret, nc + rec(nst,ed.F,cv2));
    }
  }

  if(mia == e[cv2]){
    for(auto ed : rG[cv2]){
      int nc = ed.S + d[ed.F];
      if((e[ed.F] == mia && ((st>>idx[ed.F])&1)) || ed.F == cv1)
        nc -= d[ed.F];
      int nst = st;
      int nmia = min(e[ed.F], e[cv1]);
      if(mia != nmia)
        nst = 0;
      
      if(nmia == e[ed.F]) nst |= 1 << idx[ed.F];
      if(nmia == e[cv1]) nst |= 1 << idx[cv1];
      ret = min(ret, nc + rec(nst,cv1,ed.F));
    }
  }
  cout << st << " " << cv1+1 << " " << cv2+1 << " " << ret << endl;
  return ret;
}

int main(int argc, char *argv[])
{
  while(cin >> n >> m && (n|m)){
    e[n-1] = 1000;
    d[n-1] = 0;
    memset(num,0,sizeof(num));
    memset(idx,0,sizeof(idx));
    rep(i,n-2){
      cin >> d[i+1] >> e[i+1];
      idx[i+1] = num[e[i+1]];
      ++num[e[i+1]];
    }
    rep(i,n) G[i].clear();
    rep(i,n) rG[i].clear();
    
    rep(i,m){
      int a,b,c;
      cin >> a >> b >> c;
      --a,--b;
      if(e[a] <= e[b]) G[a].pb(mp(b,c));
      if(e[a] >= e[b]) rG[b].pb(mp(a,c));
    }
    
    memset(memo, -1, sizeof(memo));
    int ans = -1;
    // ans = rec(1,0,0);
    // if(ans == (1<<28)) ans = -1;
    // cout << ans << endl;
    // continue;
    
    memset(vis,0,sizeof(vis));
    rep(i,n)rep(j,n)rep(k,1<<10) memo[i][j][k] = 1<<28;
    set<pair<pair<int,short>,pair<char,char> > > q;
    q.insert(mp(mp(0,1),mp(0,0)));
    //int ans = -1;
    int cnt  = 0;
    while(!q.empty()){
      int cc = q.begin()->F.F;
      int st = q.begin()->F.S;
      int cv1 = q.begin()->S.F;
      int cv2 = q.begin()->S.S;
      q.erase(q.begin());
      if(vis[cv1][cv2][st]) continue;
      vis[cv1][cv2][st] = 1;
      memo[cv1][cv2][st] = cc;
      if(cv1 == n-1 && cv2 == n-1){
        ans = cc;
        break;
      }

      if(++cnt % 5000 == 0){
        vector<pair<pair<int,short>,pair<char,char> > > er;
        for(auto e : q) if(memo[e.S.F][e.S.S][e.F.S] < e.F.F) er.push_back(e);
        for(auto e : er) q.erase(e);
      }
      
      int mia = min(e[cv1], e[cv2]);
      if(mia == e[cv1]){
        for(auto ed : G[cv1]){
          int nc = cc + ed.S + d[ed.F];
          if((e[ed.F] == mia && ((st>>idx[ed.F])&1)) || ed.F == cv2)
            nc -= d[ed.F];
          int nst = st;
          int nmia = min(e[ed.F], e[cv2]);
          if(mia != nmia)
            nst = 0;
          
          if(nmia == e[ed.F]) nst |= 1 << idx[ed.F];
          if(nmia == e[cv2]) nst |= 1 << idx[cv2];
          if(!vis[ed.F][cv2][nst] && nc < memo[ed.F][cv2][nst]){
            memo[ed.F][cv2][nst] = nc;
            q.insert(mp(mp(nc,nst),mp(ed.F,cv2)));
          }
        }
      }
      
      if(mia == e[cv2]){
        for(auto ed : rG[cv2]){
          int nc = cc + ed.S + d[ed.F];
          if((e[ed.F] == mia && ((st>>idx[ed.F])&1)) || ed.F == cv1)
            nc -= d[ed.F];
          int nst = st;
          int nmia = min(e[ed.F], e[cv1]);
          if(mia != nmia)
            nst = 0;
          
          if(nmia == e[ed.F]) nst |= 1 << idx[ed.F];
          if(nmia == e[cv1]) nst |= 1 << idx[cv1];
          if(!vis[cv1][ed.F][nst] && nc < memo[cv1][ed.F][nst]){
            memo[cv1][ed.F][nst] = nc;
            q.insert(mp(mp(nc,nst),mp(cv1,ed.F)));
          }
        }
      }      
    }
    cout << ans << endl;
  }
}