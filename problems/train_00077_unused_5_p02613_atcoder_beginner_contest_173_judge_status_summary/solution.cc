#include <bits/stdc++.h>
using namespace std;
int n,cnt[30];
char S[5];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",S);
		cnt[S[0]-65]++;
	}
	printf("AC x %d\n",cnt[0]);
	printf("WA x %d\n",cnt['W'-65]);
	printf("TLE x %d\n",cnt['T'-65]);
	printf("RE x %d\n",cnt['R'-65]);
	return 0;
}
