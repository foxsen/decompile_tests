#include <bits/stdc++.h>
using namespace std;
int s[110];
int main()
{
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=b;i++)
	{
		int x,y;
		cin>>x>>y;
		if(x>y)swap(x,y);
		s[x]++,s[y]++;
	}
	for(int i=1;i<=a;i++)cout<<s[i]<<'\n';
	return 0;
}
