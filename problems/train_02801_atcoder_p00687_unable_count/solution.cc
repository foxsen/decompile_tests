#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<string>
#include<vector>
#include<queue>
#define MAX_N 1000010
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 100000005
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;
typedef long long int ll;
typedef pair<int,int> PI;

int gcm(int a,int b){
    if(a<b){swap(a,b);}
    while(b>0){
        a%=b;
        swap(a,b);
    }
    return a;
}

int lcm(int a,int b){
    return a/gcm(a,b)*b;
}

int main(){
    int n,a,b;
    int LCM,GCM;
    bool flag[MAX_N];
    int count[MAX_N];
    while(1){
        cin>>n>>a>>b;
        if(n==0)
            break;
        rep(i,MAX_N){
            flag[i]=0;
        }
        LCM=lcm(a,b);
        GCM=gcm(a,b);
        int ans;
        int irange = min(MAX_N-1,LCM)/a+1;
        rep(i,irange){
            int jrange =(min(MAX_N-1,LCM)-a*i)/b+1;
            rep(j,jrange){flag[a*i+b*j]=true;}
        }
        count[0]=0;
        rep(i,MAX_N-1){
            count[i+1]=count[i]+flag[i+1];
        }
        if(n<LCM){
            ans=count[n];
        }
        else{
            ans=count[LCM]+(n-LCM)/GCM;
        }
        cout<<n-ans<<endl;
    }
}