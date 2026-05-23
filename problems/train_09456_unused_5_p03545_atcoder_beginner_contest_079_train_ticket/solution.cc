#include<bits/stdc++.h>
using namespace std;
int A,B,C,D;
int main()
{
	scanf("%1d%1d%1d%1d",&A,&B,&C,&D);
	for(int i=1;i>(-2);i-=2)
		for(int j=1;j>(-2);j-=2)
			for(int k=1;k>(-2);k-=2)
				if(i*B+j*C+k*D+A==7)
				{
					printf("%d%c%d%c%d%c%d=7\n",A,(i==1?'+':'-'),B,(j==1?'+':'-'),C,(k==1?'+':'-'),D);
					return 0;
				}
	return 0;
}
