#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef __int128 INT;
struct cww{cww(){
    ios::sync_with_stdio(false);cin.tie(0);
}}star;
#define fin "\n"
#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define fi first
#define se second
#define pb push_back
#define DEBUG if(0)
template <typename T>inline void chmin(T &l,T r){l=min(l,r);}
template <typename T>inline void chmax(T &l,T r){l=max(l,r);}
template <typename T>
istream& operator>>(istream &is,vector<T> &v){
    for(auto &it:v)is>>it;
    return is;
}
typedef vector<INT> V;
typedef vector<V> VV;

INT comb[1145140][11];
const INT INF=1e15;
struct latte{
    latte(){
        for(int i=0;i<1145140;i++)comb[i][0]=1;
        for(int i=1;i<1145140;i++)
            for(int j=1;j<=min(i,10);j++)
                comb[i][j]=min(INF,comb[i-1][j]+comb[i-1][j-1]);
    }
}malta;

LL f(V a,V b,bool eq){
    int m=b.size();
    LL cnt=0;
    int ub=114514;
    while(a>b){
        cnt++;
        FOR(i,1,m){
            b[i]+=b[i-1];
            chmin(b[i],INF);
            if(b[i]==INF)chmin(ub,i);
        }
        if(ub<10)break;
    }
    if(eq){
        if(a==b)return cnt+1;
        if(a<b)return cnt;
    }
    else{
        if(a==b)return -cnt+1;
        if(a<b)return -cnt+1;
    }
    LL k=(a[1]-b[1]+b[0]-1)/b[0];
    //if(k<0)return 0;
    if(b[0]*k+b[1]>a[1]){
        if(eq)
            return cnt+k;
        else{
            return -cnt-k+1;
        }
    }
    if(k==0){
        if(eq){
            return cnt+k+1;
        }
        else{
            return -cnt-k;
        }
    }
   
    
    if(k>=1000000){
        if(eq)
            return cnt+k;
        else return -cnt-k+1;
    }
    for(int id=2;id<b.size();id++){
        INT sum=b[id];
        if(sum>a[id]){
            if(eq)
                return cnt+k;
            else
                return -cnt-k+1;
        }
        REP(i,id){
            sum+=min(INF,b[i]*comb[k+id-1][id-i]);
        }
        if(sum>a[id]){
            if(eq)
                return cnt+k;
            else
                return -cnt-k+1;
        }
        if(sum<a[id]){
            if(eq)return cnt+k+1;
            else return -cnt-k;
        }
    }
    if(eq){
        return cnt+k+1;
    }
    else{
        return -cnt-k+1;
    }
}


int main(){
    int N,M;
    cin>>N>>M;
    VV A(N,V(M));
    REP(i,N)REP(j,M){
        int a;
        cin>>a;
        A[i][j]=a;
    }
    if(M==1){
        int ans=0;
        REP(i,N-1)if(A[i]>=A[i+1])ans=-1;
        cout<<ans<<endl;
        return 0;
    }
    vector<LL> B(N-1,0);
    REP(i,N-1){
        if(A[i]==A[i+1])B[i]=1;
        else if(A[i]>A[i+1]){
            if(A[i][0]>A[i+1][0]){
                cout<<-1<<endl;
                return 0;
            }
            B[i]=f(A[i],A[i+1],true);
        }
        else {
            if(A[i][0]<A[i+1][0])B[i]=-INF;
            else 
                B[i]=f(A[i+1],A[i],false);
        }
        //cout<<i<<" "<<B[i]<<endl;
    }
    LL res=0,now=0;
    REP(i,N-1){
        now=max(0ll,now+B[i]);
        res+=now;
    }
    cout<<res<<endl;
    return 0;
}
