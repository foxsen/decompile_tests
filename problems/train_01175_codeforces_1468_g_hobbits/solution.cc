#include<bits/stdc++.h>
using namespace std;
#define debug printf("%d %s\n",__LINE__,__FUNCTION__);fflush(stdout)
using ll=long long;using i64=long long;using db=double;
using u32=unsigned int;using u64=unsigned long long;using db=double;
using pii=pair<db,db>;using vi=vector<int>;
using qi=queue<int>;using pqi=priority_queue<int>;using si=set<int>;
#define pb push_back
#define mk make_pair
#define ins insert
#define era erase
#define fi first
#define se second
#define lowbit(x) x&-x
#define ALL(a) a.begin(),a.end()
const int INF=0x3f3f3f3f;
const ll INFLL=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
template<class T>inline bool chkmin(T&a,T b){return b<a?a=b,true:false;}
template<class T>inline bool chkmax(T&a,T b){return a<b?a=b,true:false;}
int _w,_t;FILE* _f;

db slo(pii na,pii nb){
    if(na.fi==nb.fi){
        return (db)INF;
    }
    else{
        return (db)(nb.se-na.se)/(nb.fi-na.fi);
    }
}

db sq(db u){
    return u*u;
}

db dis(pii na,pii nb){
    return sqrt(sq(nb.fi-na.fi)+sq(nb.se-na.se));
}

pii its(pii naa,pii nab,pii nba,pii nbb){
    db l=naa.fi,r=nab.fi;
    while(r-l>1e-10){
        db mid=(l+r)/2;
        if(slo(mk(mid,naa.se+(mid-naa.fi)*slo(naa,nab)),nba)>slo(nba,nbb)){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    return mk(l,naa.se+(l-naa.fi)*slo(naa,nab));
}

const int N=2e5+5;

int n,h;

pii nd[N];

db ans;

void solve(){
    scanf("%d%d",&n,&h);
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&nd[i].fi,&nd[i].se);
    }
    for(int i=1;i<n;i++){
        ans+=dis(nd[i],nd[i+1]);
    }
    nd[n+1]=mk(nd[n].fi,nd[n].se+h);
    int pos=n,ite=n;
    while(pos>1){
        while(pos>1&&slo(nd[pos-1],nd[pos])<=slo(nd[pos],nd[n+1])){
            --pos;
        }
        ite=pos-1;
        while(ite>0&&slo(nd[ite],nd[pos])>slo(nd[pos],nd[n+1])){
            ans-=dis(nd[ite],nd[ite+1]);
            --ite;
        }
        if(!ite){
            break;
        }
        ans-=dis(its(nd[ite],nd[ite+1],nd[pos],nd[n+1]),nd[ite+1]);
        pos=ite;
    }
    printf("%.10lf\n",ans);
}

int main(){
    #ifdef MULTI_CASES
    _w=scanf("%d",&_t);while(_t--)
    #endif
    solve();
    return 0;
}