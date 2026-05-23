#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		b=max(b,-b),c=max(c,-c);
		if((b+c)%2!=a%2)
		{
			cout<<"No\n";
			return 0;
		}
		if(b+c>a)
		{
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
	return 0;
}