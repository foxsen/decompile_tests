#include<bits/stdc++.h>
using namespace std;
int n,q,k;
string s;
long long solve()
{
	long long D=0,M=0,DM=0,DMC=0;
	for(int i=0;i<s.size();i++)
	{
		if(i-k>=0&&s[i-k]=='D')
		{
			D--;
			DM-=M;
		}
		if(i-k>=0&&s[i-k]=='M')
			M--;
		if(s[i]=='D')
			D++;
		if(s[i]=='M')
		{
			M++;
			DM+=D;
		}
		if(s[i]=='C')
			DMC+=DM;
	}
	return DMC;
}
int main()
{
	cin>>n>>s>>q;
	while(q--)
	{
		cin>>k;
		cout<<solve()<<endl;
	}
	return 0;
}