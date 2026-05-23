#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
signed main(){
	int a,b,c,d,e,f,g,h,i;
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
	int j=a-b,k=b-c;
	if(j==d-e&&k==e-f&&j==g-h&&k==h-i)puts("Yes");
	else puts("No");
	return 0;
}
