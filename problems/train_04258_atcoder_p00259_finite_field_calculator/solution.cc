#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i = s; i < t ; ++i)
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define UNIQ(a) a.erase(unique(ALL(a)),a.end())
#define debug(a) cerr<<#a":="<<a<<endl;
#define SZ(a) (int)a.size()
using LL = long long; template<class T> using V = vector <T>; template <class T> using VV = V<V<T>>;


LL powmod(LL a, LL x, LL mod) {
	LL ret = 1;
	while (x) {
		if (x % 2) {
			ret *= a;
			ret %= mod;
		}
		a *= a;
		a %= mod;
		x >>= 1;
	}
	return ret;
}
string spa(const string &s) {
	string ret = "";
	FOR(i, 0, SZ(s)) {
		if (s[i] != ' ') {
			ret += string(1, s[i]);
		}
	}
	return ret;
}
LL getnum(string & s, int &i) {
	LL ret = 0;
	while (isdigit(s[i])) {
		ret *= 10;
		ret += s[i] - '0';
		i++;
	}

	return ret;
}

int flag;

LL expr0(string&, int&, LL);
LL expr1(string&, int&, LL);
LL expr2(string&, int&, LL);

LL expr0(string& s, int& i, LL mod) {
	LL ret = expr1(s, i, mod);
	while (s[i] == '+' || s[i] == '-') {
		if (s[i] == '+')ret += expr1(s, ++i, mod);
		if(s[i]=='-')ret -= expr1(s, ++i, mod);
		ret += mod;
		ret %= mod;
	}
	return ret;
}
LL expr1(string& s, int& i, LL mod) {
	LL ret = expr2(s, i, mod);
	while (s[i] == '*' || s[i] == '/') {
		if (s[i] == '*')ret *= expr2(s, ++i, mod);
		if (s[i] == '/') {
			LL si = expr2(s, ++i, mod);

			if (si%mod == 0) {
				flag = 1;
			}
			else {
				ret *= powmod(si, mod - 2,mod);
			}
		}
		ret %= mod;
	}
	return ret;
}
LL expr2(string& s, int& i, LL mod) {
	if (s[i] == '(') {
		i++;
		LL num = expr0(s, i, mod);
		i++;
		return num;
	}
	else {
		return getnum(s, i) % mod;
	}

}


int main() {

	string s;
	while (getline(cin,s), s[0] != '0') {
		string t = spa(s);
		int i = 0;
		LL mod = getnum(t, i);
		i++;
		t = t.substr(i);
		string sub = t;
		i = 0;
		flag = 0;
		LL ans = expr0(t, i,mod);
		if (flag) {
			cout << "NG" << endl;
		}
		else {
			cout << sub ;
			cout << " = " << ans << " (mod " << mod << ")" << endl;
		}

	}

	return 0;
}

