#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,y,x;
	cin>>n;
	x=n/100;
	y=x*105;
	if (n<=y)
	{
		cout<<1<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
}