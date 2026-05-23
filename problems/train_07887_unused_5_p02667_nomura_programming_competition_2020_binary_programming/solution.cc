#include<bits/stdc++.h>
using namespace std;
int n,s,i,j,p;
long long ans;
char c[200005];
int main()
{
	scanf("%s",c+1);
	for(i=1;c[i];++i)
		if(c[i]=='0')
			++s;
	for(i=1;c[i];++i)
	{
		if(c[i]=='0')
			break;
		if(i&1)
			ans+=s+1;
	}
	for(++i;c[i];++i)
	{
		++p;
		int s0=0,s1=0;
		for(j=i;c[j]=='1';++j)
		{
			if(j&1)
				++s1;
			else
				++s0;
		}
		if(s0<s1)
			ans+=(p+1)/2*s0+p/2*s1+1ll*s1*(s+1-p);
		else
			ans+=((p+1)/2-1)*s0+(p/2+1)*s1+1ll*s0*(s+1-p);
		i=j;
	}
	s=-1;
	for(i=1;c[i];++i)
		if(c[i]=='1')
			++s;
	while(s>0)
	{
		ans+=(s+1)/2;
		--s;
	}
	cout<<ans;
}
