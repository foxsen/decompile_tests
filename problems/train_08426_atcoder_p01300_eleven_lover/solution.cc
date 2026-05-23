#include <iostream>
using namespace std;

int main(){
	string str;
	while( cin >> str && str != "0" ){
		int ele[12] = {};
		ele[0] = 1;
		int s=0;
		long long ans = 0;
		for(int i = str.size() - 1 ; i >= 0 ; i--){
			int d = str[i] - '0';
			int c = i % 2 ? 10 : 1;
			s += c * d;
			s %= 11;
			if( d != 0 ){
				ans += ele[s];
			}
			ele[s]++;
		}
		cout << ans << endl;
	}
}