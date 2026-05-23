#include "bits/stdc++.h"
using namespace std;
string a;
int n,ans;
int main()
{
	cin>>n>>a;
	for(int i=1;i<a.size();i++)
		if(a[i]!=a[i-1]) ans++;
	cout<<ans+1;
}