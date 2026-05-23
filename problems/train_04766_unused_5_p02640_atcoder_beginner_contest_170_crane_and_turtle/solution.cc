#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	if(a*4-b<0 || (a*4-b)%2!=0 || b-a*2<0)cout<<"No\n";else cout<<"Yes\n";
	return 0;
}
