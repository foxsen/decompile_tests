#include <bits/stdc++.h>
using namespace std;

int b;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	while(1){
		cin >> b;
		if(b == 0) return 0;
		int m = 1e9, n = 0;
		for(int i=1; i*i<=2*b; ++i){
			if(2 * b % i != 0) continue;
			int c = 2 * b / i;
			if(i % 2 != c % 2){
				int s = (i + c - 1) / 2;
				int t = (i - c + 1) / 2;
				if(s > t) swap(s, t);
				if(s > 0 && s < m){
					m = s;
					n = t;
				}
				s = (c + i - 1) / 2;
				t = (c - i + 1) / 2;
				if(s > t) swap(s, t);
				if(s > 0 && s < m){
					m = s;
					n = t;
				}
			}
		}
		cout << m << " " << n - m + 1 << "\n";
	}
}
