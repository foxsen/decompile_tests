#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL gor[200005][20];
LL valr[200005][20];
LL gol[200005][20];
LL vall[2000005][20];
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    int x[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&x[i]);
    }
    for(int i = 0;i<20;i++){
        gor[n+1][i]=n+1;
        gol[0][i]=0;
    }
    int now=0;
    for(int i = 1;i<=n;i++){
        while(now!=n+1&&x[now]-x[i]<k){
            now++;
        }
        gor[i][0]=now;
        valr[i][0]=i;
    }
    now=n;
    for(int i =n;i>=1;i--){
        while(now!=0&&x[i]-x[now]<k){
            now--;
        }
        gol[i][0]=now;
        vall[i][0]=i;
    }
    for(int i = 1;i<20;i++){
        for(int j = 1;j<=n;j++){
            gol[j][i]=gol[gol[j][i-1]][i-1];
            vall[j][i]=vall[j][i-1]+vall[gol[j][i-1]][i-1];
            gor[j][i]=gor[gor[j][i-1]][i-1];
            valr[j][i]=valr[j][i-1]+valr[gor[j][i-1]][i-1];
         //   printf("%d %d %lld %lld %lld %lld\n",i,j,gol[j][i],vall[j][i],gor[j][i],valr[j][i]);
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        LL ans=0;
        int now=r;
        for(int i = 19;i>=0;i--){
            if(gol[now][i]>=l){
                ans+=vall[now][i]+(1<<i);
                now=gol[now][i];
                 //printf("%lld %d %d\n",now,ans,i);
            }
        }
        ans+=now+1;
      //  printf("%lld\n",ans);
        now=l;
        for(int i = 19;i>=0;i--){
            if(gor[now][i]<=r){
                ans-=valr[now][i];
               // printf("%d %d\n",i,valr[now][i]);
                now=gor[now][i];
            }
        }
        ans-=now;
        printf("%lld\n",ans);
    }
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/
