#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k, x, dis=0;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin>>x;
		dis+=min(x, k-x);
	}
	cout << 2*dis << endl;
}