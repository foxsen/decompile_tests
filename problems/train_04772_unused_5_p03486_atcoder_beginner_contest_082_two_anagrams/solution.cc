#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	string s,t;
	cin >> s >> t;
	sort(s.begin(),s.end());
	sort(t.rbegin(),t.rend());
	if(s<t)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
