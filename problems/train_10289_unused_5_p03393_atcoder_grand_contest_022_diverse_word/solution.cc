
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	string s;
	cin >> s;
	int cnt[26] = {};
	for(auto i:s)cnt[i-'a']++;
	bool is = false;
	for(int i = 0;i<26;i++)
	{
		if(cnt[i]==0&&is==false)
		{
			is = true;
			s.push_back('a'+i);
			
		}
	}
	if(is)cout<<s<<endl;
	else
	{
		string t = s;
		if(next_permutation(s.begin(),s.end()))
		{
			for(int i = 0;i<s.size();i++)
			{
				cout<<s[i];
				if(s[i]!=t[i])break;
			}
			cout<<endl;

		}
		else
		{
			cout<<-1<<endl;
		}
	}
	return 0;
}
