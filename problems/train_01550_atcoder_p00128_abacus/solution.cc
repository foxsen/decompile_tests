#include <iostream>
using namespace std;

int main()
{
	int c=0,n,str[5];
	while(cin >> n)
	{
		if(c) cout << endl; c=1;

		for(int i=0,k=10000; i<5; i++,k/=10)
		{
			str[i] = n/k;
			n %= k;
		}


		for(int j=0; j<2; j++)
		{
			for(int i=0; i<5; i++)
			{
				cout << (str[i]/5==j?'*':' ');
			}
			cout << endl;
		}
	
		for(int i=0; i<5; i++) cout << '='; cout << endl;
		
		for(int j=0; j<5; j++)
		{
			for(int i=0; i<5; i++)
			{
				cout << (str[i]%5==j?' ':'*');
			}
			cout << endl;
		}
	}
}