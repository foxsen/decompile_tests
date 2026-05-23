#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <climits>
#include <cassert>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

const long double EPS = 1e-9;

int main()
{
	int N;
	const int M = 256;
	while (cin >> N, N) {
		int ansS, ansA, ansC;
		long double min_H = INT_MAX;
		vi I(N+1);
		REP(i, N) {
			cin >> I[i+1];
		}
		REP(S, 16) {
			REP(A, 16) {
				REP(C, 16) {
					vi R(N+1);
					R[0] = S;
					FOR(i, 1, N+1) {
						R[i] = (A * R[i-1] + C) % M;
					}

					vi O(N+1);
					map<int, int> X;
					FOR(i, 1, N+1) {
						O[i] = (I[i] + R[i]) % M;
						if(EXIST(X, O[i])) {
							X[O[i]]++;
						} else {
							X[O[i]] = 1;
						}
					}

					long double H = 0;
					for (map<int, int>::iterator itr = X.begin(); itr != X.end(); ++itr) {
						long double t = (itr->second / (long double)N);
						H -= t * log(t);
					}

					if(H < min_H - EPS) {
						min_H = H;
						ansS = S, ansA = A, ansC = C;
					}
				}
			}
		}
		cout << ansS << " " << ansA << " " << ansC << endl;
	}
}