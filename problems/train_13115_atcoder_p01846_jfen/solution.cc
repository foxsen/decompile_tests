#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
typedef long long ll;

int main() {
	while (1) {
		int H = 0, W = 0;
		bool table[9][9] = {};
		string S;
		int a, b, c, d;
		cin >> S;
		if (S == "#")break;
		cin >> a >> b >> c >> d;
		a--, b--, c--, d--;
		
		//create map
		int x = 0, y = 0;
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == 'b') {
				table[x][y] = true;
				y++;
			}
			else if(S[i] >= '1' && S[i] <= '9'){
				y += S[i] - '0';
			}
			else {
				if (W == 0)W = y;
				x++;
				y = 0;
			}
		}
		H = x + 1;
		//move
		table[a][b] = false;
		table[c][d] = true;

		//create jfen
		int conti = 0;
		string ans;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (table[i][j]) {
					if (conti != 0)ans += conti + '0';
					conti = 0;
					ans += 'b';
				}
				else {
					conti++;
				}
			}
			if (conti != 0) ans += '0' + conti;
			conti = 0;
			if(i != H - 1)ans += '/';
		}
		cout << ans << endl;
	}
	return 0;
}
