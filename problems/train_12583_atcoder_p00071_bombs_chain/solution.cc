#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define rep2(x,from,to) for(int x = (from); x < (to); ++(x))
#define rep(x,to) rep2(x,0,to)

void clear(int r, int c, string &b) {
	if(b[r * 8 + c] == '0') return;
	else {
		b[r * 8 + c] = '0';
		rep2(i,1,4) {
			if(r+i < 8) clear(r+i,c,b);
			if(r-i >= 0) clear(r-i,c,b);
			if(c+i < 8) clear(r,c+i,b);
			if(c-i >= 0) clear(r,c-i,b);
		}
	}
}
int main() {
	int n;
	cin >> n;
	rep(i,n) {
		string s, t;
		rep(j,8) {
			cin >> t;
			s += t;
		}
		int r, c;
		cin >> c >> r;
		c--,r--;
		clear(r,c,s);
		cout << "Data " << i+1 << ":" << endl;
		rep(j,8) {
			rep(k,8) {
				cout << s[j * 8 + k];
			}
			cout << endl;
		}
	}
	return 0;
}