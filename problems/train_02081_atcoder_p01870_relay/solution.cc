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
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

struct segtree{
    static const int SEG=1<<17;
    vint dat;
    segtree():dat(SEG*2){}
    void update(int k,int x){
        k+=SEG-1;
        dat[k]=x;
        while(k){
            k=(k-1)/2;
            dat[k]=max(dat[k*2+1],dat[k*2+2]);
        }
    }
    int get(int a,int b,int k=0,int l=0,int r=SEG){
        if(r<=a||b<=l)return 0;
        if(a<=l&&r<=b)return dat[k];
        return max(get(a,b,k*2+1,l,(l+r)/2),get(a,b,k*2+2,(l+r)/2,r));
    }
};

struct edge{
    int to,cost;
    edge(int to,int cost):to(to),cost(cost){}
};

const int SIZE=100000;
int N;
vector<edge>G[SIZE];

int tt,tin[SIZE],tout[SIZE];
segtree seg;
int ans;

struct data{
    int len,cost,id;
    data(int len,int cost,int id):len(len),cost(cost),id(id){}
    bool operator<(const data &d)const{
        return len<d.len;
    }
};

int maxlen[SIZE],maxcost[SIZE];
pint maxpair[SIZE];

inline bool comp(const pint &a,const pint &b){
    return a.fi+a.se>b.fi+b.se;
}

void solve(int v,int p){
    int hoge=max(seg.get(0,tin[v]+1),seg.get(tout[v],segtree::SEG));
    vector<data>vec(3,data(0,0,-1));
    for(auto &e:G[v]){
        if(e.to==p)continue;
        maxlen[e.to]+=e.cost;
        chmax(maxcost[e.to],e.cost);
        maxpair[e.to].fi+=e.cost;
        vec.pb(data(maxlen[e.to],maxcost[e.to],e.to));
    }

    sort(all(vec));reverse(all(vec));
    chmax(ans,vec[0].len+vec[1].len+hoge);
    chmax(ans,vec[1].len+vec[2].len+vec[0].cost);
    chmax(ans,vec[0].len+vec[2].len+vec[1].cost);
    for(int i=2;i<vec.size();i++)chmax(ans,vec[0].len+vec[1].len+vec[i].cost);
    for(auto &e:G[v]){
        if(e.to==p)continue;
        int tmp=vec[0].len;
        if(e.to==vec[0].id)tmp=vec[1].len;
        chmax(ans,tmp+maxpair[e.to].fi+maxpair[e.to].se);

        chmax(maxcost[v],maxcost[e.to]);
        if(comp(maxpair[e.to],maxpair[v]))maxpair[v]=maxpair[e.to];
    }

    vint maxl(vec.size(),0),maxr(vec.size(),0);
    for(int i=0;i<vec.size()-1;i++){
        chmax(maxl[i+1],max(maxl[i],vec[i].cost));
    }
    for(int i=vec.size()-1;i>0;i--){
        chmax(maxr[i-1],max(maxr[i],vec[i].cost));
    }
    rep(i,vec.size()){
        int tmp=max(maxl[i],maxr[i]);
        pint p(vec[i].len,tmp);
        if(comp(p,maxpair[v]))maxpair[v]=p;
    }
    maxlen[v]=vec[0].len;
}

void dfs(){
    stack<int>v,p;
    vint sz(N,1);
    v.push(0);p.push(-1);
    while(v.size()){
        int vv=v.top();v.pop();
        int pp=p.top();p.pop();
        tin[vv]=tt++;
        for(auto &e:G[vv]){
            if(e.to==pp)continue;
            seg.update(tt,e.cost);
            v.push(e.to);
            p.push(vv);
        }
    }

    vint vec,par;
    vec.pb(0);par.pb(-1);
    rep(i,N){
        for(auto &e:G[vec[i]]){
            if(e.to==par[i])continue;
            vec.pb(e.to);
            par.pb(vec[i]);
        }
    }
    for(int i=N-1;i>0;i--){
        sz[par[i]]+=sz[vec[i]];
    }

    rep(i,N)tout[i]=tin[i]+sz[i];

    for(int i=N-1;i>=0;i--){
        solve(vec[i],par[i]);
    }
}



signed main(){
    scanf("%lld",&N);
    reps(i,1,N){
        int a,b;
        scanf("%lld%lld",&a,&b);
        G[i].pb(edge(a,b));
        G[a].pb(edge(i,b));
    }

    dfs();
    printf("%lld\n",ans);
    return 0;
}