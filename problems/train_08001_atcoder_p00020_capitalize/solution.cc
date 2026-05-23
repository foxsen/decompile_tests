#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string str;
	getline(cin,str);
	for(int i=0;i<str.length();i++)
	{
		if('a'<=str[i]&&str[i]<='z')
		{
			str[i]+='A'-'a';
		}
	}
	cout<<str<<endl;
	cin>>str;
}