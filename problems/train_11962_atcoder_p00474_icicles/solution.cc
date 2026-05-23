#include "bits/stdc++.h"

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back

int n,l;
int data[200000];
int memo[200000];

int solve(int num){
    if(memo[num]!=-1)return memo[num];
    
    if( data[num-1]<data[num] && data[num+1]<data[num] )return l-data[num];
    if( data[num-1]<data[num] && num==n-1 )  return l-data[num];
    if( data[num+1]<data[num] && num==0  )   return l-data[num];
    
    int left=0,right=0;
    if( data[num-1]>data[num] )left = solve(num-1);
    if( data[num+1]>data[num] )right= solve(num+1);
    
    memo[num] = l-data[num] + max(left,right);
    return memo[num];
}


int main(){
    rep(i,200000)memo[i]=-1;
    cin>>n>>l;
    rep(i,n) cin>>data[i];
    
    int ans = 0;
    rep(i,n){
        ans = max(ans,solve(i));
    }
    cout<<ans<<endl;
}