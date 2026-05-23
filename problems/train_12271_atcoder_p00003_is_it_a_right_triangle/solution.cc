#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n, a, b, c;
	cin>>n;
	while(n) {
		cin>>a>>b>>c;
		if(a*a==b*b+c*c || b*b==a*a+c*c || c*c==a*a+b*b)
			printf("YES\n");
		else printf("NO\n");
		n--;
	}
	return 0;
} 
