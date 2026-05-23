#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string s,shape[7];
	string tmp;
	shape[0]="1100000011";
	shape[1]="1000000010000000100000001";
	shape[2]="1111";
	shape[3]="1000000110000001";
	shape[4]="11000000011";
	shape[5]="100000001100000001";
	shape[6]="110000011";
	while(cin>>s)
	{
		for(int i=0;i<7;i++)
		{
			cin>>tmp;
			s+=tmp;
		}
		for(int i=0;i<7;i++)
		{
			if(s.find(shape[i])!=string::npos)
			{
				cout<<(char)('A'+i)<<endl;
			}
		}
	}
}