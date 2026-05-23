#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/06/20  Problem: AOJ 2703 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2703  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */


using uLL = unsigned long long;

const uLL MOD = 1e9;
//BEGIN CUT HERE
struct Dice {
	int s[6];
	void roll(char c) {
		//the view from above
		// N
		//W E
		// S
		//s[0]:top
		//s[1]:south
		//s[2]:east
		//s[3]:west
		//s[4]:north
		//s[5]:bottom
		int b;
		if (c == 'E') {
			b = s[0];
			s[0] = s[3];
			s[3] = s[5];
			s[5] = s[2];
			s[2] = b;
		}
		if (c == 'W') {
			b = s[0];
			s[0] = s[2];
			s[2] = s[5];
			s[5] = s[3];
			s[3] = b;
		}
		if (c == 'N') {
			b = s[0];
			s[0] = s[1];
			s[1] = s[5];
			s[5] = s[4];
			s[4] = b;
		}
		if (c == 'S') {
			b = s[0];
			s[0] = s[4];
			s[4] = s[5];
			s[5] = s[1];
			s[1] = b;
		}

		// migi neji 
		if (c == 'R') {
			b = s[1];
			s[1] = s[2];
			s[2] = s[4];
			s[4] = s[3];
			s[3] = b;
		}

		if (c == 'L') {
			b = s[1];
			s[1] = s[3];
			s[3] = s[4];
			s[4] = s[2];
			s[2] = b;
		}

	}
	int top() {
		return s[0];
	}
	int bottom() {
		return s[5];
	}
	uLL hash() {
		uLL res = 1;
		for (int i = 0; i < 6; i++) res = res * (MOD)+s[i];
		return res;
	}
	void print() {
		cout << "Dice num: ";
		FOR(i, 0, 6) {
			cout << s[i] << " ";
		}
		cout << "Hash: " << this->hash() << endl;
		cout << endl;
	}
};
vector<Dice> makeDices(Dice d) {
	vector<Dice> res;
	for (int i = 0; i < 6; i++) {
		Dice t(d);
		if (i == 1) t.roll('N');
		if (i == 2) t.roll('S');
		if (i == 3) t.roll('S'), t.roll('S');
		if (i == 4) t.roll('L');
		if (i == 5) t.roll('R');
		for (int k = 0; k < 4; k++) {
			res.push_back(t);
			t.roll('E');
		}
	}
	return res;
}
//END CUT HERE

void solve_AOJ_ITP1_11_A() {
	int N = 6;
	Dice D;
	FOR(i, 0, N) {
		int val; cin >> val;
		D.s[i] = val;
	}
	string s; cin >> s;
	FOR(i, 0, SZ(s)) {
		D.roll(s[i]);
	}
	cout << D.top() << endl;
}

void solve_AOJ_ITP1_11_B() {
	Dice D;
	int N = 6;
	FOR(i, 0, N) {
		int val; cin >> val;
		D.s[i] = val;
	}
	vector<Dice> dices = makeDices(D);
	int Q; cin >> Q;
	FOR(i, 0, Q) {
		int TOP, FRONT;
		cin >> TOP >> FRONT;
		FOR(i, 0, SZ(dices)) { //24個
			if (dices[i].top() == TOP && dices[i].s[1] == FRONT) {
				cout << dices[i].s[2] << endl;
				break;
			}
		}
	}
}

void solve_AOJ_ITP1_11_C() {
	Dice d[2];
	FOR(k, 0, 2) {
		FOR(i, 0, 6) {
			int val; cin >> val;
			d[k].s[i] = val;
		}
	}
	uLL hashval = d[0].hash();
	vector<Dice>dices = makeDices(d[1]);
	FOR(i, 0, SZ(dices)) {
		if (hashval == dices[i].hash()) {
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}
void solve_AOJ_ITP1_11_D() {
	int N; cin >> N;
	vector<Dice>d(N);
	FOR(k, 0, N) {
		FOR(i, 0, 6) {
			int val; cin >> val;
			d[k].s[i] = val;
		}
	}
	set<uLL>Se;
	Se.insert(d[0].hash());
	FOR(i, 1, N) {
		vector<Dice>dices = makeDices(d[i]);
		int flag = 0;
		FOR(j, 0, SZ(dices)) {
			flag |= (Se.count(dices[j].hash()));
		}
		if (flag) {
			cout << "No" << endl;
			return;
		}
		Se.insert(dices[i].hash());

	}
	cout << "Yes" << endl;
}

void solve_AOJ_0502() {
	int Q;
	while (cin >> Q, Q) {
		Dice d; FOR(i, 0, 6)d.s[i] = i + 1;
		int ans = 1;
		FOR(kim, 0, Q) {
			string s; cin >> s;
			d.roll(s[0]);
			ans += d.top();
		}
		cout << ans << endl;
	}


}

using PII = pair<int, int>;
map<char, char>changeC;
inline  int  mhash(const PII &a) {
	return (a.first + 1200) * 2400 + a.second + 1200;
}
void solve_AOJ_2703() { // えーサイコロ関係なくないですか？ないですね
	const string ORIG = "EWNS";
	const string TO = "RLBF";
	FOR(i, 0, 4) {
		changeC[TO[i]] = ORIG[i];
	}
	int N;
	while (cin >> N, N) {
		vector<map<PII, int>>Map(N);
		int x, y;
		Dice dice;
		FOR(i, 0, N) {
			cin >> x >> y;
			cin >> dice.s[3] >> dice.s[2] >> dice.s[1] >> dice.s[4] >> dice.s[5] >> dice.s[0];
			string s; cin >> s;
			Map[i][PII(y, x)] = dice.bottom();
			FOR(j, 0, SZ(s)) {
				dice.roll(changeC[s[j]]);
				// R,L,B,F
				if (s[j] == 'R')x++;
				if (s[j] == 'L')x--;
				if (s[j] == 'B')y++;
				if (s[j] == 'F')y--;
				// y x の移動
				Map[i][PII(y, x)] = dice.bottom();
			}
		}

		vector<int>bitdp(1 << N, 0);
		FOR(state, 0, 1 << N) {
			unordered_map<int, bool>used; // orderedだと結構遅かった
			FOR(i, 0, N) {
				if (state & 1 << i) {
					for (auto it : Map[i]) {
						used[mhash(it.first)] = 1;
					}
				}
			}
			// 記録した
			FOR(i, 0, N) {
				if (state & 1 << i)continue;
				int addv = 0;

				for (auto it : Map[i]) {
					if (!used.count(mhash(it.first))) {
						addv += it.second;
					}
				}
				bitdp[state | (1 << i)] = max(bitdp[state | (1 << i)], bitdp[state] + addv);
			}
		}
		cout << bitdp[(1 << N) - 1] << endl;

	}
}

void solve_AOJ_1181() {
	int N;
	Dice BaseDi;
	FOR(i, 0, 6)BaseDi.s[i] = i + 1;
	vector<Dice>dices = makeDices(BaseDi);
	while (cin >> N, N) {
		VVI masu(210, VI(210, 0));
		vector<VVI>valset(210, VVI(210, VI()));
		FOR(okaduki, 0, N) {
			int tp, fr; cin >> tp >> fr;
			int X = 100, Y = 100;
			Dice d;
			FOR(i, 0, SZ(dices)) {
				if (dices[i].top() == tp&&dices[i].s[1] == fr) {
					d = dices[i];
					break;
				}
			}
			while (1) {
				masu[Y][X]++;
				// 落ちる方向を決める
				// 大きな方に転がり落ちる
				int dy[] = { -1, 1, 0, 0, -1, };
				int dx[] = { -1, 0, 1, -1, 0, };
				int dir = -1;
				FOR(num, 4, 6 + 1) {
					if (d.top() != num && d.bottom() != num) { //面があれ
						FOR(i, 1, 4 + 1) {
							if (d.s[i] == num) {
								if (masu[Y][X] > masu[Y + dy[i]][X + dx[i]] + 1) {
									dir = i;
								}
							}
						}
					}
				}
				if (dir == -1) {
					valset[Y][X].push_back(d.top());
					break;
				}
				masu[Y][X]--;
				string TO = "$SEWN";
				Y += dy[dir]; X += dx[dir];
				d.roll(TO[dir]);
			}
		}
		VI a(7, 0);
		FOR(i, 0, 210) {
			FOR(j, 0, 210) {
				if (!SZ(valset[i][j]))continue;
				int val = valset[i][j].back();
				a[val]++;
			}
		}
		FOR(i, 1, 6 + 1) {
			cout << a[i] << " \n"[i == 6];
		}

	}

}

vector<Dice>dices;
int tops[3][3], fronts[3][3];
vector<int> ans;
Dice putdice[3][3][3];
void dfs(int state) {
	if (state == 27) {
		int ret = 0;
		FOR(i, 0, 3) {// 右の右をとる s[2]
			FOR(j, 0, 3) {
				ret += putdice[i][2][j].s[2];
			}
		}

		ans.push_back(ret);
	}
	else {
		int X = (state / 3) % 3;
		int Y = state % 3;
		int Z = state / 9;
		FOR(i, 0, 24) { // put dices to putdice
			// ダメなもの top .front がちゃう
			if (Z == 0 && tops[X][Y] && tops[X][Y] != dices[i].top())continue;
			if (X == 2 && fronts[Z][Y] && fronts[Z][Y] != dices[i].s[1])continue;
			// ダメなもの 7じゃない
			if (X&& putdice[X - 1][Y][Z].s[4] + dices[i].s[1] != 7)continue; // 奥
			if (Y&& putdice[X][Y - 1][Z].s[2] + dices[i].s[3] != 7)continue; // 左
			if (Z&& putdice[X][Y][Z - 1].s[5] + dices[i].s[0] != 7)continue; // 上

			putdice[X][Y][Z] = dices[i];
			dfs(state + 1);
		}


	}

}


// 24^27なきもちになるけど前処理すればだいたい決まるので解析しなくても投げる気持ちが固まる
// パラメータの管理壊れる
void solve_AOJ_1253() {
	// 条件を見たすように配置したときの右面の種類
	Dice Base;
	FOR(i, 0, 6)Base.s[i] = i + 1;
	dices = makeDices(Base);

	int Case; cin >> Case;
	FOR(kyo, 0, Case) {
		FOR(i, 0, 3)FOR(j, 0, 3)cin >> tops[i][j];
		FOR(i, 0, 3)FOR(j, 0, 3)cin >> fronts[i][j];
		dfs(0);
		SORT(ans); UNIQ(ans);
		FOR(i, 0, SZ(ans)) {
			cout << ans[i] << " \n"[i == SZ(ans) - 1];
		}
		if (SZ(ans) == 0)cout << 0 << endl;
		ans.clear();
	}




}
Dice resDice[4];
vector<Dice>diceState[4];

void Dfs(int state, const int N, int& ans) {
	if (N == state) {
		int res = 0;
		// あるおきかたについて
		// 一緒になるように最小の塗り分けをする

		FOR(i, 0, 6) { //ある面について
			map<int, int>cnt;
			FOR(k, 0, N) {
				cnt[resDice[k].s[i]]++;
			}
			int mx = 0;
			for (auto it : cnt) {
				mx = max(mx, it.second); // 重複maxが保存すべきもの
			}
			res += N - mx;
		}




		ans = min(ans, res);
		return;
	}
	FOR(i, 0, 24) {
		resDice[state] = diceState[state][i];
		Dfs(state + 1, N, ans);
	}
}

void solve_AOJ_1259() {
	// N diff checkする 全探索 同じにするための塗り替えを最小にする
	int N;
	while (cin >> N, N) {
		if (N == 1) {
			string s; FOR(i, 0, 6)cin >> s;

			cout << 0 << endl;
		}
		else {

			vector<Dice>baseDice(N);
			FOR(i, 0, 4)diceState[i].clear();
			map<string, int>sHash;
			int hp = 1;
			FOR(i, 0, N) {
				FOR(j, 0, 6) {
					string s;  cin >> s;
					if (sHash.find(s) == sHash.end())sHash[s] = hp++;
					baseDice[i].s[j] = sHash[s];
				}
			}
			// 値をいれたので24^(N-1)全部つくる
			FOR(i, 0, N) {
				diceState[i] = makeDices(baseDice[i]);
			}
			int ans = INF;
			resDice[0] = baseDice[0];
			Dfs(1, N, ans);
			cout << ans << endl;
		}
	}


}
 

// R S Vは解けそう

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	//solve_AOJ_ITP1_11_A();
	//solve_AOJ_ITP1_11_B();
	//solve_AOJ_ITP1_11_C();
	//solve_AOJ_ITP1_11_D();
	//solve_AOJ_0502();

	//solve_AOJ_1181();
	//solve_AOJ_2703();
	//solve_AOJ_1253();
	solve_AOJ_1259();

	return 0;
}
//
