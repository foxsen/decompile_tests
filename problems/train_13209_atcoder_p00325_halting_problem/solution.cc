#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

struct sentence {
	int type;
	int a;
	int b;
	int c;
};

map<int, int>line_mp;
map<string, int>name_mp;
bool memo[51][(1 << 20)];
int getid(vector<int>&v) {
	int sum = 0;
	for (int i = 0; i < v.size(); ++i) {
		sum *= 16;
		sum+= v[i];
	}
	assert(sum < (1 << 20));
	return sum;
}
int getnum(const string name_st) {
	static int k = 0;
	if (name_mp.find(name_st) == name_mp.end()) {
		name_mp[name_st] = k++;
	}
	return name_mp[name_st];
}
int ansl;
vector<int>ansv;
void solve(const vector<sentence>&sents,int line, vector<int>&v) {
	
	if (memo[line][getid(v)] == 1) {
		ansl = -3;
		throw(false);
	}
	else {

		memo[line][getid(v)] = 1;
		auto sent(sents[line]);
		int type = sent.type;
		int calc;
		int nextline = -1;
		if (type <= 5) {
			switch (type) {
			case 0:
				calc = v[sent.b] + v[sent.c];
				break;
			case 1:
				calc = v[sent.b] + sent.c;
				break;
			case 2:
				calc = v[sent.b] - v[sent.c];
				break;
			case 3:
				calc = v[sent.b] - sent.c;
				break;

			case 4:
				calc = v[sent.b];
				break;
			case 5:
				calc = sent.b;
				break;
			}
			if (calc < 0 || calc >= 16) {
				ansl = line;
				ansv = v;
				throw(false);
			}
			else {
				v[sent.a] = calc;
			}
			nextline = line + 1;
		}
		else {
			switch (type) {
			case 6:
				if (v[sent.a] == 0) {
					nextline = line + 1;
				}
				else {
					nextline = sent.b;
				}
				break;
			case 7:

				ansl = line;
				ansv = v;
				throw(false);
				break;
			}
		}

		
	
		if (nextline == -1||nextline>=sents.size()) {
			ansl = line;
			ansv = v;
			throw(false);
		}

		solve(sents, nextline, v);
	}

	
	
}
int main() {
	for (int i = 0; i < 51; ++i) {
		for (int j = 0; j < (1 << 20); ++j) {
			memo[i][j] =false;
		}
	}
	int N; cin >> N;
	vector <sentence>aas;
	{
		for (int i = 0; i < N; ++i) {
			int l; cin >> l;
			line_mp[l] = i;
			string st; cin >> st;
			if (st == "ADD" || st == "SUB") {
				string a, b, c; cin >> a >> b >> c;
				if (isdigit(c[0])) {
					int anum(getnum(a));
					int bnum(getnum(b));
					aas.push_back(sentence{ (st == "SUB") * 2 + 1,anum,bnum,stoi(c) });
				}
				else {
					int anum(getnum(a));
					int bnum(getnum(b));
					int cnum(getnum(c));
					aas.push_back(sentence{ (st == "SUB") * 2,anum,bnum,cnum });
				}
			}
			else if (st == "SET") {
				string a, b; cin >> a >> b;
				if (isdigit(b[0])) {
					int anum(getnum(a));
					aas.push_back(sentence{ 5,anum,stoi(b),-1 });
				}
				else {
					int anum(getnum(a));
					int bnum(getnum(b));
					aas.push_back(sentence{ 4,anum,bnum,-1 });
				}
			}
			else if (st == "IF") {
				string a; int bnum; cin >> a >> bnum;
				int anum(getnum(a));
				aas.push_back(sentence{ 6,anum,bnum,-1 });

			}
			else {
				assert(st == "HALT");
				aas.push_back(sentence{ 7,-1,-1,-1 });
			}
		}
		for (auto& a : aas) {
			if (a.type == 6) {
				if (line_mp.find(a.b) == line_mp.end()) {
					a.b = -1;
				}
				else {
					a.b = line_mp[a.b];

				}
			}
		}
		
	}
	try {
		vector<int>v(5,0);
		solve(aas, 0, v);
	}
	catch (...) {
		if (ansl == -3)cout << "inf" << endl;
		else {
			vector<pair<string, int>>vars;
			for (auto nm:name_mp) {
				vars.push_back(make_pair(nm.first, ansv[nm.second]));

			}
			sort(vars.begin(),vars.end());
			for(auto var:vars){
				cout << var.first << "=" << var.second << endl;
			}
		}
	}
	
	return 0;
}