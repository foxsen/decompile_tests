#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int t=0;
	char p[3]={'A','B','C'};
	string s[3];
	for(int i=0;i<3;i++)
	{
		cin>>s[i];
	}
	while(1)
	{
		if(s[t]=="")
		{
			cout<<p[t]<<endl;
			return 0;
		}
		int r=t;
		t=s[t][0]-'a';
		s[r].erase(0,1);

	}
}