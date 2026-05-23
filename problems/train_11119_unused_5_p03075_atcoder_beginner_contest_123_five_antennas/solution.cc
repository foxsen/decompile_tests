#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[5],k;
	for(int i=0;i<5;i++) cin>>a[i];
	cin>>k;
	int x=a[4]-a[0];
	if(x<=k) cout<<"Yay!";
	else cout<<":(";
	return 0;
}