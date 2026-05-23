#include <iostream>
#include <string>
using namespace std;

int main() {
	double d;
	while(cin >> d, d >= 0) {
		int a = 0;
		string b = "";
		a = d;
		d -= a;
		for(int i = 0; i < 4; i++) {
			b += (char)((d * 2) + '0');
			d *= 2;
			if(d >= 1) d -= 1;
		}
		if(d > 1e-9 || a >= (1 << 8))
			cout << "NA" << endl;
		else {
			for(int i = 0; i < 8; i++) {
				cout << !!(a & (1 << (7-i)));
			}
			cout << "." << b;
			cout << endl;
		}
	}
}