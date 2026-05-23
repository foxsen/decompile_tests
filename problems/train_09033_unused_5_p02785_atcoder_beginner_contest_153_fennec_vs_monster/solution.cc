#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	long long power[n],sum=0;
	for(int i=0;i<n;i++)
		cin>>power[i];
	sort(power,power+n);
	for(int i=0;i<n-k;i++)
		sum+=power[i];
	cout<<sum;
}