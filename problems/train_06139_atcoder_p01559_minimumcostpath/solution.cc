#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using pii=pair<int,int>;

const int INF=1e8;
const int SMALL=1000;
const ll MOD=1e9+9;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int n,m;
vector<int> x,y;

const int FACT_SIZE=3*1e6;
vector<ll> fact(FACT_SIZE);
vector<ll> factInv(FACT_SIZE);
ll powm(ll x,ll k){
    ll res=1;
    while(k){
        if(k&1) res=res*x%MOD;
        x=x*x%MOD;
        k>>=1;
    }
    return res;
}
ll inv(ll x){
    return powm(x,MOD-2);
}
void init(){
    fact[0]=1;
    for(int i=1;i<FACT_SIZE;i++) fact[i]=fact[i-1]*i%MOD;
    for(int i=0;i<FACT_SIZE;i++) factInv[i]=inv(fact[i]);
}
ll comb(int n,int k){
    return fact[n]*factInv[k]%MOD*factInv[n-k]%MOD;
}

const int PARTIAL=111;
pair<int,ll> solveSmall(int sx,int sy,int gx,int gy){
    int szx=gx-sx+1+2*PARTIAL,szy=gy-sy+1+2*PARTIAL;
    vector<vector<int>> d(szx,vector<int>(szy,INF));
    vector<vector<ll>> pat(szx,vector<ll>(szy,0));
    vector<vector<int>> obj(szx,vector<int>(szy,false));
    auto isRange=[&](int x,int y){
        int realx=x-PARTIAL+sx;
        int realy=y-PARTIAL+sy;
        return 0<=x && x<szx && 0<=y && y<szy && 0<=realx && realx<n && 0<=realy && realy<n;
    };
    for(int i=0;i<m;i++){
        if(sx-PARTIAL<=x[i] && x[i]<gx+PARTIAL && sy-PARTIAL<=y[i] && y[i]<gy+PARTIAL){
            obj[x[i]-sx+PARTIAL][y[i]-sy+PARTIAL]=true;
        }
    }
    // sx -> PARTIAL sy-> PARTIAL
    queue<pii> que;
    d[PARTIAL][PARTIAL]=0;
    pat[PARTIAL][PARTIAL]=1;
    que.push(pii{PARTIAL,PARTIAL});
    while(!que.empty()){
        auto tmp=que.front(); que.pop();
        int px=tmp.first,py=tmp.second;
        for(int i=0;i<4;i++){
            int tx=px+dx[i],ty=py+dy[i];
            if(isRange(tx,ty) && !obj[tx][ty] && d[tx][ty]>=d[px][py]+1){
                if(d[tx][ty]>d[px][py]+1){
                    pat[tx][ty]=0;
                    que.push(pii{tx,ty});
                }
                d[tx][ty]=d[px][py]+1;
                pat[tx][ty]=(pat[tx][ty]+pat[px][py])%MOD;
            }
        }
    }
    return {d[gx-sx+PARTIAL][gy-sy+PARTIAL],pat[gx-sx+PARTIAL][gy-sy+PARTIAL]};
}


struct S{
    int x,y,d;
    ll pat;
};
ll solveLarge(){
    vector<S> left,right;
    for(int i=0;i<=PARTIAL;i++){
        int px=i,py=PARTIAL-i;
        auto tmp=solveSmall(0,0,px,py);
        left.push_back(S{px,py,tmp.first,tmp.second});
    }
    for(int i=0;i<=PARTIAL;i++){
        int px=n-1-i,py=n-1-(PARTIAL-i);
        auto tmp=solveSmall(px,py,n-1,n-1);
        right.push_back(S{px,py,tmp.first,tmp.second});
    }
    int d=INF;  
    auto calcD=[&](S sl,S sr){
        return sl.d+sr.d+sr.y-sl.y+sr.x-sl.x;
    };
    for(auto sl:left){
        for(auto sr:right){
            d=min(d,calcD(sl,sr));
        }
    }
    ll res=0;
    if(d>=INF) return 0;
    // cerr<<"#"<<d<<endl;
    auto calc=[&](S sl,S sr){
        int sx=sl.x,sy=sl.y,gx=sr.x,gy=sr.y;
        ll res=comb(gx-sx+gy-sy,gx-sx);
        vector<ll> dp(m);
        for(int i=0;i<m;i++){
            if(sx<=x[i] && sy<=y[i]) dp[i]=-comb(x[i]-sx+y[i]-sy,x[i]-sx);
        }
        for(int i=0;i<m;i++){
            if(x[i]<=gx && y[i]<=gy){
                res=(res+comb(gx-x[i]+gy-y[i],gx-x[i])*dp[i])%MOD;
            }
            for(int j=i+1;j<m;j++){
                if(x[i]<=x[j] && y[i]<=y[j]){
                    dp[j]=(dp[j]-comb(x[j]-x[i]+y[j]-y[i],x[j]-x[i])*dp[i])%MOD;
                }
            }
        }
        return (res*sl.pat%MOD*sr.pat+MOD)%MOD;
    };
    for(auto sl:left){
        for(auto sr:right){
            if(calcD(sl,sr)==d){
                res=(res+calc(sl,sr))%MOD;
            }
        }
    }
    return (res%MOD+MOD)%MOD;
}

int main(){
    init();
    cin>>n>>m;
    {
        vector<pair<int,int>> tmp(m);
        for(int i=0;i<m;i++) cin>>tmp[i].first>>tmp[i].second,tmp[i].first--,tmp[i].second--;
        sort(tmp.begin(),tmp.end());
        x.resize(m),y.resize(m);
        for(int i=0;i<m;i++) x[i]=tmp[i].first,y[i]=tmp[i].second;
    }
    
    cout<<(n<SMALL ? solveSmall(0,0,n-1,n-1).second : solveLarge())<<endl;

    return 0;
}
