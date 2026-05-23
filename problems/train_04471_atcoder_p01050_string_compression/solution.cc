#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

#define unless(c) if (!(c))
#define each(i, c) for (auto& i: c)

using namespace std;

int main(void)
{
  const int N = 300;
  string s;
  while (cin >> s) {
    sort(s.begin(), s.end());
    int cnt[N];
    fill(cnt, cnt + N, 0);
    for (int i = 0; i < s.size(); ++i) {
      ++cnt[s[i]];
    }
    string t;
    while (true) {
      const string u = t;
      for (int i = 0; i < N; ++i) {
	if (cnt[i]) {
	  string add = "";
	  int k = i;
	  for (int j = i; j < N && cnt[j]; ++j) {
	    add += j;
	    k = j;
	  }
	  if (add.size() <= 2) {
	    t += add;
	  } else {
	    t += i;
	    t += '-';
	    t += k;
	  }
	  for (int k = 0; k < add.size(); ++k) {
	    --cnt[add[k]];
	  }
	  break;
	}
      }
      if (u == t) break;
    }
    sort(s.begin(), s.end());
    // cout << s << endl;
    // cout << t << endl;
    cout << t.size() << endl;
  }
  return 0;
}