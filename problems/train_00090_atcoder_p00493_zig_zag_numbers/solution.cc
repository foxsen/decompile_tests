#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

 int mod=10000;
struct Mod {
public:
	int num;
	Mod() : Mod(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) {
		//static_assert(mod<INT_MAX / 2, "mod is too big, please make num 'long long int' from 'int'");
	}
	Mod(int n) : Mod(static_cast<long long int>(n)) { ; }
	operator int() { return num; }
};

Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int  b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod mod_pow(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = mod_pow((a * a), (n / 2));
	if (n % 2) res = res * a;
	return res;
}
Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) {
	assert(b.num != 0);
	return a * inv(b);
}
Mod operator/(const long long int a, const Mod b) {
	return Mod(a) / b;
}
Mod operator/=(Mod &a, const Mod b) {
	return a = a / b;
}

#define MAX_MOD_N 1024000

Mod fact[MAX_MOD_N], factinv[MAX_MOD_N];
void init() {
	fact[0] = Mod(1); factinv[0] = 1;
	for (int i = 0; i < MAX_MOD_N - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(const int a, const int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}
//keta prenum,upping,aless,bmore,bai
Mod dp[502][10][2][2][2][500][2];
long long int powmod(long long int a, long long int b, const int mod) {
	assert(b >= 0);
	if (b == 0)return 1;
	if (b == 1)return a;
	long long int ans = 1;
	long long int aa = powmod(a, b / 2, mod);
	ans *= aa*aa;
	ans %= mod;
	if (b % 2)ans *= a;
	ans %= mod;
	return ans;
}
int main() {
	string A, B; int M; cin >> A >> B >> M;
	int asize = A.size(); int bsize = B.size();
	for (int i = asize; i <= 501; ++i) {
		A = '0' + A;
	}
	for (int i = bsize; i <= 501; ++i) {
		B= '0' + B;
	}
	Mod ans = 0;
	for (int i = 0; i < 10; ++i) {
		bool  amore = i >= (A[501] - '0');
		bool bless = i <= (B[501] - '0');
		dp[0][i][0][amore][bless][i%M][0]+=1;
		dp[0][i][1][amore][bless][i%M][0]+=1;
		dp[0][i][0][amore][bless][i%M][1] += 1;
	}
	for (int keta = 1; keta <= 501; ++keta) {
		for (int prenum = 0; prenum < 10; ++prenum) {
			for (int upping = 0; upping < 2; ++upping) {
				for (int amore = 0; amore < 2; ++amore) {
					for (int bless = 0; bless< 2; ++bless) {
						for (int bai = 0; bai < M; ++bai) {
							for (int death = 0; death < 2; ++death) {
								if (dp[keta - 1][prenum][upping][amore][bless][bai][death]) {
									
									for (int nextnum = 0; nextnum < 10; ++nextnum) {
										if (death){
											if (nextnum) {
												continue;
											}
										}
										else {
											if (upping) {
												if (nextnum <= prenum)continue;
											}
											else {
												if (nextnum >= prenum)continue;
											}
										}
										 
										bool nextamore, nextbless;
										if (nextnum >(A[501 - keta] - '0')) {
											nextamore = true;
										}
										else if (nextnum == (A[501 - keta] - '0')) {
											nextamore = amore;
										}
										else {
											nextamore = false;
										}
										if (nextnum > (B[501 - keta] - '0')) {
											nextbless = false;
										}
										else if (nextnum == (B[501 - keta] - '0')) {
											nextbless = bless;
										}
										else {
											nextbless = true;
										}
										int nextbai = bai +powmod(10, keta,M)*nextnum;
										nextbai %= M;
										assert(nextbai < mod); 
										if (keta == 1 && nextnum == 1 && (!upping) == 1 && nextamore == 1 && nextbless == 1 && nextbai == 0) {
											int c = 0; c++;
										}
										
										dp[keta][nextnum][!upping][nextamore][nextbless][nextbai][death] += dp[keta - 1][prenum][upping][amore][bless][bai][death];
										
										/*if (nextnum == 0 && keta == 3 && !nextbai&&death) {
											cout << nextnum << " " << prenum << endl;
											cout << dp[keta - 1][prenum][upping][amore][bless][bai][death] << endl;;
										}*/
										
										if (!death&&nextnum) {
											
											dp[keta][nextnum][!upping][nextamore][nextbless][nextbai][1] += dp[keta - 1][prenum][upping][amore][bless][bai][death];
										}
										
										
										
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (int prenum = 0; prenum < 10; ++prenum) {
		for (int upping = 0; upping < 2; ++upping) {
			for (int death = 1; death < 2; ++death) {
				if (dp[501][prenum][upping][1][1][0][death]) {

					ans += dp[501][prenum][upping][1][1][0][death];
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}