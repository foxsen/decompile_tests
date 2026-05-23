#include<iostream>
#include<string>
using namespace std;
char ch[256];
int main()
{
	ch['b']='d';
	ch['d']='b';
	ch['q']='p';
	ch['p']='q';
	string s;
	cin>>s;
	int i;
	for(i=0;i<s.size();i++)
	{
		if(ch[s[i]]!=s[s.size()-1-i]) goto br;
	}
	printf("Yes\n");
	return 0;
	br:;
	printf("No\n");
	return 0;
}
