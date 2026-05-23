#include<iostream>
using namespace std;

int main()
{
	while(1){
		int a, j=0;
		cin >> a;
		if (a == 0)break;
		j = a;
		string s="";
		int b = 0;
		for (b = 1; b * 8 <= a; b *= 8) {}
		for (int c = b; c != 1; c /= 8) {
			int o =a/c;
			switch (a / c) {
			case 0:case 1:case 2:case 3:cout << a / c;  break;
			case 4:cout << 5; break;
			default:cout << a / c + 2; break;
			}
			
			a -= c*o;
		}
			switch (j % 8) {
			case 0:case 1:case 2:case 3:cout << j % 8; break;
			case 4:cout << 5; break;
			default:cout << j % 8 + 2;
			}
		
		cout << endl;
			}
}