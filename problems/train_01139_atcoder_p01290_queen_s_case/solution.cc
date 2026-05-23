#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll

#define INF 1e16
#define mod 1000000007

int W,H;
string s[33];
int ai,aj,qi,qj;
int st[33][33][33][33][2];
int rest[33][33][33][33][2];
int dd[]={-1,0,0,1,0,-1};

struct state{
  int qi,qj,ai,aj,t;
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  while(1){
    cin>>W>>H;
    if(W==0)break;
    rep(i,H){
      cin>>s[i];
      rep(j,W){
        if(s[i][j]=='A'){
          ai=i; aj=j;
        }
        if(s[i][j]=='Q'){
          qi=i; qj=j;
        }
      }
    }
    memset(st,-1,sizeof(st));
    memset(rest,0,sizeof(rest));
    queue<state> que;
    rep(sqi,H)rep(sqj,W)rep(sai,H)rep(saj,W)rep(tt,2){
      if(s[sqi][sqj]=='#'||s[sai][saj]=='#')continue;

      if(s[sqi][sqj]=='E'&&!(sqi==sai&&sqj==saj)&&tt==0){
        que.push((state){sqi,sqj,sai,saj,tt});
        st[sqi][sqj][sai][saj][tt]=1;
      }else if(sqi==sai&&sqj==saj){
        que.push((state){sqi,sqj,sai,saj,tt});
        st[sqi][sqj][sai][saj][tt]=0;
      }else if(tt==0){
        rep(d,5){
          int nqi=sqi+dd[d],nqj=sqj+dd[d+1];
          if(nqi<0||nqi>=H||nqj<0||nqj>=W||s[nqi][nqj]=='#')continue;
          rest[sqi][sqj][sai][saj][tt]++;
        }
      }else if(tt==1){
        rep(d,5){
          int nai=sai+dd[d],naj=saj+dd[d+1];
          if(nai<0||nai>=H||naj<0||naj>=W||s[nai][naj]=='#')continue;
          rest[sqi][sqj][sai][saj][tt]++;
        }
      }
    }

    while(que.size()){
      state c=que.front(); que.pop();
      int crtst=st[c.qi][c.qj][c.ai][c.aj][c.t];
      if(c.t==1){
        rep(d,5){
          int nqi=c.qi+dd[d],nqj=c.qj+dd[d+1];
          if(nqi<0||nqi>=H||nqj<0||nqj>=W||s[nqi][nqj]=='#'||
            st[nqi][nqj][c.ai][c.aj][1-c.t]!=-1)continue;
            if(crtst==1){
              que.push((state){nqi,nqj,c.ai,c.aj,1-c.t});
              st[nqi][nqj][c.ai][c.aj][1-c.t]=1;
              continue;
            }
            rest[nqi][nqj][c.ai][c.aj][1-c.t]--;
            if(rest[nqi][nqj][c.ai][c.aj][1-c.t]==0){
              que.push((state){nqi,nqj,c.ai,c.aj,1-c.t});
              st[nqi][nqj][c.ai][c.aj][1-c.t]=0;
            }
          }
        }else if(c.t==0){
          rep(d,5){
            int nai=c.ai+dd[d],naj=c.aj+dd[d+1];
            if(nai<0||nai>=H||naj<0||naj>=W||s[nai][naj]=='#'||
              st[c.qi][c.qj][nai][naj][1-c.t]!=-1)continue;
              if(crtst==0){
                que.push((state){c.qi,c.qj,nai,naj,1-c.t});
                st[c.qi][c.qj][nai][naj][1-c.t]=0;
                continue;
              }
              rest[c.qi][c.qj][nai][naj][1-c.t]--;
              if(rest[c.qi][c.qj][nai][naj][1-c.t]==0){
                que.push((state){c.qi,c.qj,nai,naj,1-c.t});
                st[c.qi][c.qj][nai][naj][1-c.t]=1;
              }
            }
          }
        }

        if(st[qi][qj][ai][aj][0]==-1)cout<<"Queen can not escape and Army can not catch Queen."<<endl;
        if(st[qi][qj][ai][aj][0]==0) cout<<"Army can catch Queen."<<endl;
        if(st[qi][qj][ai][aj][0]==1) cout<<"Queen can escape."<<endl;
      }
      return 0;
    }

