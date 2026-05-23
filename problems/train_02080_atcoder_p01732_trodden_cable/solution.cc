#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};

int W,H,N;
int sx,sy,gx,gy;
int cost[555][555][4];
int dist[555][555];

typedef pair<int,pint>node;

inline void add(int y,int x,int d){
    if(y>=0&&y<=H&&x>=0&&x<=W)cost[y][x][d]++;
}

inline int conv(char c){
    if(c=='U')return 0;
    if(c=='R')return 1;
    if(c=='D')return 2;
    return 3;
}

signed main(){
    cin>>W>>H>>N;
    cin>>sx>>sy>>gx>>gy;

    rep(latte,N){
        int x,y,t;
        string s;
        cin>>x>>y>>t>>s;
        rep(T,t){
            rep(i,s.size()){
                int d=conv(s[i]);
                int ny=y+dy[d],nx=x+dx[d];
                if(ny<0||ny>=H||nx<0||nx>=W)continue;
                if(d==0){
                    add(y,x,1);
                    add(y,x+1,3);
                }
                else if(d==1){
                    add(y,x+1,2);
                    add(y+1,x+1,0);
                }
                else if(d==2){
                    add(y+1,x,1);
                    add(y+1,x+1,3);
                }
                else{
                    add(y,x,2);
                    add(y+1,x,0);
                }
                y=ny;x=nx;
            }
        }
    }
    priority_queue<node,vector<node>,greater<node>>que;
    que.push(node(0,pint(sy,sx)));
    rep(i,H+1)rep(j,W+1)dist[i][j]=1001001001001001001ll;
    dist[sy][sx]=0;
    while(que.size()){
        int y=que.top().se.fi,x=que.top().se.se,c=que.top().fi;
        que.pop();
        if(dist[y][x]<c)continue;
        rep(i,4){
            int ny=y+dy[i],nx=x+dx[i];
            if(ny<0||ny>H||nx<0||nx>W||dist[ny][nx]<=c+cost[y][x][i])continue;
            dist[ny][nx]=c+cost[y][x][i];
            que.push(node(dist[ny][nx],pint(ny,nx)));
        }
    }
    cout<<dist[gy][gx]<<endl;
    return 0;
}