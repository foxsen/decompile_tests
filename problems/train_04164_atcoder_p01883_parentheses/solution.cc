#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A;
int c[200010];
int n,now;


int main()
{
	scanf("%d",&A);
	n=1;
	while ((ll)n*(n+1)/2<(ll)A) n++;
	int p=A-(ll)n*(n-1)/2;
	c[1]=1;	c[1+p]=2;now=1;
	for(int i=1;i<=2*n;i++) if(c[i]==0) if(now<n) c[i]=1,now++;else c[i]=2;
	for(int i=1;i<=2*n;i++) if(c[i]==1) printf(")");else printf("(");
	printf("\n");
	return 0;
}