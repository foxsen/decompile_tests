#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;

using namespace std;
#define N 100010
ll a[N],b[N],n;
int main(){
    cin>>n;
    lol(i,n)cin>>a[i]>>b[i];
    sort(a,a+n); sort(b,b+n);
    ll j=0,cnt=0,ans=0;
    lol(i,n){
	for(;b[j]<a[i];j++)cnt--;
	cnt++;
	ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}
