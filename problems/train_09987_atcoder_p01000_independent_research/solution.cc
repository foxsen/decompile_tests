#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"


int main() {
	int id = 0;
	while (1) {
		int N; cin >> N;
		if (!N)break;
		if (id)cout << endl;
		id++;
		vector<vector<vector<int>>>field(5, vector<vector<int>>(5, vector<int>(5)));
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				string st; cin >> st;

				for (int k = 0; k < 5; ++k) {
					field[i][j][k] = st[k] == '1';
				}
			}
		}
		int A; cin >> A;
		vector<int>as, bs;
		for (int i = 0; i < A; ++i) {
			int a; cin >> a;
			as.push_back(a);
		}
		int B; cin >> B;
		for (int i = 0; i < B; ++i) {
			int b; cin >> b;
			bs.push_back(b);
		}
		vector<vector<vector<int>>>nfield(field);
		while (N--) {
			for (int i = 0; i < 5; ++i) {
				for (int j = 0; j < 5; ++j) {
					for (int k = 0; k < 5; ++k) {
						int num = 0;
						for (int a = i-1; a <= i+1; ++a) {
							for (int b = j-1; b <= j+1; ++b) {
								for (int c = k-1; c <= k+1; ++c) {
									if (a >= 0 && a < 5 && b >= 0 && b < 5 && c >= 0 && c < 5) {
										if(a!=i||b!=j||c!=k)num += field[a][b][c];
									}
								}
							}
						}
						if (!field[i][j][k]) {
							nfield[i][j][k] = (find(as.begin(), as.end(), num) != as.end());
						}
						else {
							nfield[i][j][k] = (find(bs.begin(), bs.end(), num) != bs.end());
						}
					}
				}
			}
			field = nfield;
		}
		cout << "Case " << id << ":" << endl;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				for (int k = 0; k < 5; ++k) {
					cout << field[i][j][k];
				}
				cout << endl;
			}
			if(i!=4)cout << endl;
		}
	}
	return 0;
}