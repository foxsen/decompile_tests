#include<bits/stdc++.h>
using namespace std;
string a;
int ans=0;
int main()
{
	cin>>a;
	for(int i=1;i<a.size();++i)
		if(a[i]!=a[i-1])
			ans++;
	cout<<ans<<endl;
	return 0;
}