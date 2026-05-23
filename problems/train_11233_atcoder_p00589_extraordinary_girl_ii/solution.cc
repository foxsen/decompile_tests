#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>

using namespace std;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,N) for(long long i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define fi first
#define se second

#define PI acos(-1.0)
#define INF 1000000007
#define EPS 1e-10
#define MAX_M 100100

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> PD;
typedef pair<string, ll> PS;
typedef vector<ll> V;
typedef pair<P, char> PC;

string s;
string table[10] = { "!", "',.!?", "abcABC", "defDEF", "ghiGHI",
"jklJKL", "mnoMNO", "pqrsPQRS", "tuvTUV", "wxyzWXYZ" };

int main(){
	while (cin >> s){
		string ans;
		int num1 = -1, num2 = 0;
		REP(i, s.size()){
			if (num1 == -1){
				num1 = s[i] - '0';
				if (num1 == 0){
					num1 = -1;
					ans += ' ';
				}
			}
			else{
				if (num1 == s[i] - '0'){
					num2++;
					if (num2 >= table[num1].size()){
						num2 = 0;
					}
				}
				else{
					ans += table[num1][num2];
					num2 = 0;
					if (s[i] == '0')num1 = -1;
					else num1 = s[i] - '0';
				}
			}
		}
		//cout << ans << endl;
		if (num1 != 0)ans += table[num1][num2];
		cout << ans << endl;
	}
}