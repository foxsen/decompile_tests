#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string S;
vector<long long> vals[100]; // 深さ d のところに一時格納する値たち

long long solve() {
  for (int i = 0; i < 100; ++i) vals[i].clear();
  int depth = 0;
  int val = 0;
  for (int i = 0; i < S.size(); ++i) {
	if (S[i] == '[') ++depth;
	else if (S[i] == ']') {
	  if (val) vals[depth].push_back((val+1)/2);
	  val = 0;
	  sort(vals[depth].begin(), vals[depth].end());
	  long long sum = 0;
	  for (int j = 0; j*2 < vals[depth].size(); ++j) sum += vals[depth][j];
	  vals[depth-1].push_back(sum);
	  vals[depth].clear();
	  --depth;
	}
	else {
	  val *= 10;
	  int c = (int)(S[i] - '0');
	  val += c;
	}
  }
  return vals[0][0];
}

int main() {
  int N; cin >> N;
  for (int i = 0; i < N; ++i) {
	cin >> S;
	cout << solve() << endl;
  }
}
