#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define iter(c) __typeof((c).begin())
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
#define mem(a) memset(a,0,sizeof(a))
#define pd(a) printf("%.10f\n",a)
#define pb(a) push_back(a)
#define in(a) insert(a)
#define pi M_PI
#define R cin>>
#define F first
#define S second
#define C class
#define ll long long
#define ln cout<<'\n'
#define _(_1,_2,_3,N,...)N
#define pr(...) _(__VA_ARGS__,pr3,pr2,pr1)(__VA_ARGS__)
template<C T>void pr1(T a){cout<<a;ln;}
template<C T,C T2>void pr2(T a,T2 b){cout<<a<<' '<<b;ln;}
template<C T,C T2,C T3>void pr3(T a,T2 b,T3 c){cout<<a<<' '<<b<<' '<<c;ln;}
template<C T>void PR(T a,int n){rep(i,n){if(i)cout<<' ';cout<<a[i];}ln;}
bool check(int n,int m,int x,int y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1000000007,MAXL=1LL<<60,dx[9]={-2,-1,-1,0,0,0,1,1,2},dy[9]={1,1,2,1,2,3,1,2,1};
typedef pair<int,int> P;
typedef pair<P,P> P2;
typedef pair<P,P2> PP;

int d[2][61][31][61][31];
void Main() {
  int n,m;
  while(cin >> m >> n && n) {
    int a[n][m];
    rep(i,n)rep(j,m) {
      char c;
      R c;
      if(isdigit(c)) a[i][j]=c-'0';
      else if(c=='X') a[i][j]=-1;
      else a[i][j]=0;
    }
    rep(i,2)rep(i2,n)rep(i3,m)rep(i4,n)rep(i5,m)d[i][i2][i3][i4][i5]=MAX;
    priority_queue<PP,vector<PP>,greater<PP> > que;
    rep(i,m) {
      if(!a[n-1][i]) {
        rep(k,2) {
          que.push(PP(P(0,k),P2(P(n-1,i),P(n-1,i))));
          d[k][n-1][i][n-1][i]=0;
        }
      }
    }
    int ans=MAX;
    while(!que.empty()) {
      PP p=que.top();que.pop();
      int nx1=p.S.F.F,ny1=p.S.F.S,nx2=p.S.S.F,ny2=p.S.S.S,c=p.F.F,t=p.F.S;
      if(!nx1&&!a[0][ny1]) ans=min(ans,c);
      if(!nx2&&!a[0][ny2]) ans=min(ans,c);
      if(d[t][nx1][ny1][nx2][ny2]<c) continue;
      int s=t^1;
      rep(i,9) {
        if(!t) {
          int x=nx1+dx[i],y=ny1+dy[i];
          if(!check(n,m,x,y)||a[x][y]==-1||d[s][nx1][ny1][x][y]<=c+a[x][y]) continue;
          d[s][nx1][ny1][x][y]=c+a[x][y];
          que.push(PP(P(c+a[x][y],s),P2(P(nx1,ny1),P(x,y))));
        } else {
          int x=nx2+dx[i],y=ny2-dy[i];
          if(!check(n,m,x,y)||a[x][y]==-1||d[s][x][y][nx2][ny2]<=c+a[x][y]) continue;
          d[s][x][y][nx2][ny2]=c+a[x][y];
          que.push(PP(P(c+a[x][y],s),P2(P(x,y),P(nx2,ny2))));
        }
      }
    }
    if(ans==MAX) ans=-1;
    pr(ans);
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  Main();return 0;
}
