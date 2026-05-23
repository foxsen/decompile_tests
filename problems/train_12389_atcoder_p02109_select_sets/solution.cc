#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define CIN_ONLY if(1)
struct cww{cww(){
    CIN_ONLY{
        ios::sync_with_stdio(false);cin.tie(0);
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
template <typename T>inline bool chmin(T &l,T r)
{bool a=l>r;if(a)l=r;return a;}
template <typename T>inline bool chmax(T &l,T r)
{bool a=l<r;if(a)l=r;return a;}
template <typename T>
istream& operator>>(istream &is,vector<T> &v){
    for(auto &it:v)is>>it;
    return is;
}
#define CNT __builtin_popcount
const int M=1<<22;
int s[M];
int id[M][3];
int main(){
    int N;
    cin>>N;
    REP(i,M)REP(j,3)id[i][j]=-1;
    REP(i,N){
        int k;cin>>k;
        int a=0;
        REP(j,k){
            int b;cin>>b;
            a|=(1<<(b-1));
        }
        s[a]=a;
        k=0;
        for(;k<2&&id[a][k]!=-1;k++);
        id[a][k]=i;
    }
    int res=0;
    FOR(i,1,M+1){
        int bit=M-i;
        int cnt=0;
        for(;cnt<3&&id[bit][cnt]!=-1;cnt++);
        REP(j,22){
            int nxt=bit|(1<<j);
            s[bit]|=s[nxt];
            REP(k,3){
                if(cnt==3||id[nxt][k]==-1)break;
                if(id[nxt][k]!=id[bit][0]&&id[nxt][k]!=id[bit][1]&&id[nxt][k]!=id[bit][2])
                    id[bit][cnt++]=id[nxt][k];
            }
        }
        if(id[bit][2]!=-1)
            chmax(res,CNT(bit)*CNT(s[bit]));
    }
    cout<<res<<endl;
    return 0;
}