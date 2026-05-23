#include<iostream>
#include<string>
using namespace std;
int main() {
	int w; cin >> w;
	string ans;
	while (true) {
		if (w == 0) {
			cout << ans << endl;
			char ch; cin >> ch; return 0;
		}
		else if (w % 3 == 1) {
			ans = '+' + ans;
			w--;
		}
		else if (w % 3 == 2) {
			ans = '-' + ans;
			w++;
		}
		else ans = '0' + ans;
		w /= 3;
	}
}