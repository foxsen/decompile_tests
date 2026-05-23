#include<bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
bool can(int m,int s){
    return s>=0 && s<=9*m;
}
int32_t main(){
    IOS;
	int t;
	cin>>t;
	while(t--){
	   int x,y;
	   cin>>x>>y;
	   if(abs(x-y)>=2){
	      cout<<x+y+abs(x-y)-1<<"\n";
	   }
	   else
	   cout<<x+y<<"\n";
	}
 } 