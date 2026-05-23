#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<b;++i)
#define allof(a) a.begin(),a.end()
#define minit(a,b) memset(a,b,sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;

char trump;
string NESW[5][15];

int encode(char a) {
	switch (a) {
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'T':
		return 10;
	case 'J':
		return 11;
	case 'Q':
		return 12;
	case 'K':
		return 13;
	case 'A':
		return 14;
	}
	return -1;
}

bool wins(char a, char b) {
	return encode(a) > encode(b);
}

void solve() {
	int score[4] = {0,0,0,0};
	int start = 0;
	
	for_(i,0,13) {
		int t = start;
		
		char rank = NESW[t][i][0];
		char base = NESW[t][i][1];
		bool tflag = false;
		if (base == trump) tflag = true;
		int win = t;
		
		for_(j,0,4) {
			int tt = (t + j) % 4;
			char rankj = NESW[tt][i][0];
			char basej = NESW[tt][i][1];
			
			if (tflag) {
				// trump flag
				if (basej == trump && wins(rankj, rank)) {
					rank = rankj;
					win = tt;
				}
			} else {
				// no torump flag
				if (basej == trump) {
					tflag = true;
					rank = rankj;
					win = tt;
				} else if (basej == base && wins(rankj, rank)){
					rank = rankj;
					win = tt;
				}
			}
		}
		
		start = win;
		score[win]++;
	}
	
	if (score[0] + score[2] >= 7) {
		cout << "NS " << score[0] + score[2] - 6 << endl;
	} else {
		cout << "EW " << score[1] + score[3] - 6 << endl;
	}
}

int main() {
	while (cin >> trump) {
		if (trump == '#') break;
		for_(i,0,4) for_(j,0,13) cin >> NESW[i][j];
		solve();
	}
	return 0;
}