#include<bits/stdc++.h>
using namespace std;
const int M=51;
int n,A[M];
double ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	sort(A+1,A+n+1);
	ans=A[1];
	for(int i=2;i<=n;i++)ans=(ans+A[i]*1.0)/2.0;
	printf("%.7lf\n",ans);
}