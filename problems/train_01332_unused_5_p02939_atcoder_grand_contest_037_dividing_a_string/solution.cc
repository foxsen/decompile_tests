#include<bits/stdc++.h>
using namespace std;

string s;
string s1,s2;
int cnt;

int main()
{
	cin >> s;
	for(int i=0;i<s.length();i++)
	{
		s2+=s[i];
		if(s2!=s1)
		{
			cnt++;
			s1=s2; 
			s2.erase(0,s2.length());
		}
	}
	cout << cnt << endl;
	return 0;
}
