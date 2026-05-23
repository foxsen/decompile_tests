#include <bits/stdc++.h>

using namespace std;

int n;
string str;

int main()
{
	cin>>n>>str;
	int ans=0,l=0,r=str.size()-1;
	while(l<r)
	{
		if(str[l]=='R')
		{
			l++;
			continue;
		}
		if(str[r]=='W')
		{
			r--;
			continue;
		}
		ans++,l++,r--;
	}
	cout<<ans;
	return 0;
}