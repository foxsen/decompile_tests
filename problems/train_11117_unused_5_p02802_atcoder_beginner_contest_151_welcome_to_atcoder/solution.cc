#include <iostream>
using namespace std;

int main() {
	int n, m, p, ac[1000000] = { 0 }, ac_num = 0, wa_num = 0, wa[1000000] = { 0 };
	string s;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> p >> s;
		if (ac[p - 1] == 0) {
			if (s == "AC") {
				ac_num++;
				ac[p - 1] = 1;
				wa_num += wa[p - 1];
			}
			else {
				wa[p - 1]++;
			}
		}
	}
	
	cout << ac_num << " " << wa_num << endl;
}