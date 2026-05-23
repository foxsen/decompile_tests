#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int mod=1000000007;

int power[1000];

int N;
int sum[5],cnt[5];

int table[205][1005];
int table2[205][205];
int C[500][500];
int F[500];

int calc(){
    memset(table,0,sizeof(table));
    rep(i1,cnt[1]+1){
        rep(i2,cnt[2]+1){
            rep(i3,cnt[3]+1){
                rep(i4,cnt[4]+1){
                    int t=C[cnt[1]][i1]*C[cnt[2]][i2]%mod*C[cnt[3]][i3]%mod*C[cnt[4]][i4]%mod;
                    table[i1+i2+i3+i4][i1+i2*2+i3*3+i4*4]=(table[i1+i2+i3+i4][i1+i2*2+i3*3+i4*4]+t)%mod;
                }
            }
        }
    }

    int ret=0;
    for(int z=0;z<=cnt[0];z++){
        for(int c=0;c<N-cnt[0];c++){
            for(int s=0;s<N*4;s++){
                int t=table[c][s]*C[cnt[0]][z]%mod;
                t=t*F[c+z]%mod;
                int lc=N-cnt[0]-1-c;
                int lz=cnt[0]-z;
                t=t*table2[lc][lz]%mod;
                ret=(ret+t*power[s+z])%mod;
            }
        }
    }

    return ret;
}

signed main(){
    power[0]=1;
    for(int i=1;i<1000;i++)power[i]=power[i-1]*10%mod;
    C[0][0]=1;
    for(int i=1;i<500;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    F[0]=1;
    for(int i=1;i<500;i++)F[i]=F[i-1]*i%mod;

    for(int i=0;i<=200;i++){
        for(int j=0;j<=200;j++){
            table2[i][j]=1;
            if(i){
                int s=i+j-1;
                for(int k=0;k<=s;k++){
                    int t=C[s][k]*F[k]%mod;
                    t=t*i%mod;
                    table2[i][j]=(table2[i][j]+t)%mod;
                }
            }
        }
    }

    cin>>N;
    rep(i,N){
        int a;
        cin>>a;
        if(a==0){
            cnt[0]++;
        }
        else{
            stringstream ss;
            ss<<a;
            int d=ss.str().size();
            sum[d]+=a;
            cnt[d]++;
        }
    }

    int ans=0;
    for(int i=1;i<5;i++){
        if(cnt[i]==0)continue;
        cnt[i]--;
        int tmp=calc();
        cnt[i]++;
        ans=(ans+tmp*sum[i])%mod;
    }

    cout<<ans<<endl;
    return 0;
}