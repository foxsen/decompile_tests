#include<set>
#include<iostream>
using namespace std;

int main()
{
	int n;
	set<string> a;
	string cmd, str;
	
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>cmd>>str;
		if(cmd.compare("insert") == 0)
			a.insert(str);
		else
		{
			if(a.find(str) != a.end())
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		}
	}
}
