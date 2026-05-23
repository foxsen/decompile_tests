#include<bits/stdc++.h>
#define ll long long
#define test while(t--)
#define mod 1e9
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define f(a,n) for(ll i=a;i<n;i++)
#define fj(a,n) for(ll j=a;j<n;j++) 
#define fe(a,n) for(ll i=a;i<=n;i++)
typedef std::vector<ll> vec;  
using namespace std;


void solve(){
    int n;
    cin>>n;
    int a[n],ans=0;
    f(0,n)cin>>a[i];
    // if(n==3){
    // 	if(is_sorted(a,a+n)) {cout<<0<<endl;return;}
    // 	else if(a[0]==3 && a[2]==1) {cout<<2<<endl;return;}
    // 	else {cout<<1<<endl;return;}
    // } 
    // else{
    	if(is_sorted(a,a+n))cout<<0<<endl;
    	else if(a[0]==n && a[n-1]==1){
    		cout<<3<<endl;
    	} 
    	else if(a[0]==1 || a[n-1]==n) cout<<1<<endl;
    	else cout<<2<<endl;
    // }
    // for(int i=0;i<n;i++){
    // 	int c=0;
    // 	for(int j=i+1;j < (i==0 ? n-1 : n);j++){
    // 		// cout<<j<<" ";
    // 		if(a[i]>a[j])
    // 		c++;
    // 		// else break;
    // 	    // cout<<"Afabkf ";
    // 	}
    // 	cout<<i<<" "<<c<<" ";
    // 	sort(a+i,a+i+c+1);
    // 	// cout<<"Apppqpqpqq ";
    // 	for (int k = 0; k < n; ++k)
    // 	{
    // 		/* code */cout<<a[k]<<" ";
    // 	}
    // 	cout<<endl;
    // 	if(is_sorted(a,a+n)) {cout<<"quqq ";break;}
    // 	else ans++;
    // }
    // for (int i = 0; i < n; ++i)
    // 	{
    // 		/* code */cout<<a[i]<<" ";
    // 	}
    // cout<<ans<<endl;
}
int main(){

int t;
cin>>t;
test{
    solve();
}
    return 0;
}


