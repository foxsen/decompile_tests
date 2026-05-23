#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define CIN_ONLY if(1)
struct cww{cww(){
    CIN_ONLY{
        ios::sync_with_stdio(false);cin.tie(0);
        cout<<fixed;
    }
}}star;
#define fin "\n"
#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define DEBUG if(0)
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline void chmin(T &l,T r){l=min(l,r);}
template <typename T>inline void chmax(T &l,T r){l=max(l,r);}
template <typename T>
istream& operator>>(istream &is,vector<T> &v){
    for(auto &it:v)is>>it;
    return is;
}
typedef vector<int> V;
typedef vector<V> VV;
VV G;
int a[112345];
int b[112345];
double c[112345];
double f[112345];
double g[112345];
double P;
double dfs1(int v,int p){
    double& res=f[v];
    res=0;
    for(auto &e:G[v]){
            int u=a[e]^b[e]^v;
            if(u==p)continue;
            res+=dfs1(u,v)+c[e];
        }
    res*=P;
    return  res;
}
double dfs2(int v,int p){
    double &res=g[v];
    res=0;
    for(auto &e:G[v]){
            int u=a[e]^b[e]^v;
            if(u==p)continue;
            res+=dfs2(u,v)+c[e];
        }
    res*=P;
    res+=f[1];

    return  res;
}

int main(){
    cin>>P;
    int N;
    cin>>N;
    G.resize(N+1);
    REP(i,N-1){
        cin>>a[i]>>b[i]>>c[i];
        G[a[i]].pb(i);
        G[b[i]].pb(i);
    }
    dfs1(1,1);
    cout<<dfs2(1,1)<<endl;
    return 0;
}