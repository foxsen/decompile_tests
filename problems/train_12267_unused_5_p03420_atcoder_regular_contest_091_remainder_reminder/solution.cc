#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n,k,ans=0;
	cin>>n>>k;
	for(long long i=n;i>k;i--){
		int w=0;
		while(w*i+(i-1)<=n) w++;
		int x=0>n-w*i-k+1?0:n-w*i-k+1;
		ans+=(w*(i-k)+x);
		if(k==0) ans--;
	}
	cout<<ans<<endl;
	return 0;
}