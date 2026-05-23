#include <iostream>
using namespace std;

int main() 
{
	string s, a="Sunny", b="Cloudy", c="Rainy";
	cin>>s;
	if(s==a)s=b;
	else if(s==b)s=c;
	else if(s==c)s=a;
	cout<<s<<endl;
	
	return 0;
}