#include<cstdio>
using namespace std;

const int _ = 200007;

char s[_];

int main()
{
	fread(s,1,_,stdin);
	
	long long ans=0,cnta=0;
	for(int i=0;s[i];i++)
	{
		if(s[i]=='A')cnta++;
		else if(s[i]=='B' && s[i+1]=='C')ans+=cnta,i++;
		else cnta=0;
	}
	printf("%lld\n",ans);

	return 0;
}
