#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int count_a = 0;
  int l = s.length();
  bool contains_a = false;
  vector<int> v;
  if (s[0] == 'a') {
    for (int i = 0; i < l; i++) {
      if (s[i] == 'a') {
        count_a++;
        contains_a = true;
        v.push_back(i);
      }
    }
  } else {
    for (int i = 0; i < l; i++) {
      if (s[i] == 'a') break;
      s[i]--;
    }
    cout << s;
    return 0;
  }
  if (count_a == l) {
    for (int i = 0; i < l - 1; i++) cout << s[i];
    cout << 'z';
    return 0;
  }
  if (contains_a == false) {
    for (int i = 0; i < l; i++) {
      s[i]--;
    }
    cout << s;
    return 0;
  } else {
    int index = -1;
    for (int i = 0; i < v.size() - 1; i++) {
      if (v[i + 1] - v[i] != 1) {
        index = i;
        break;
      }
    }
    if (index == -1) {
      if (s[0] == 'a') {
        for (int i = l - 1; i >= 0; i--) {
          if (s[i] == 'a') break;
          s[i]--;
        }
        cout << s;
        return 0;
      }
      for (int i = 0; i < l; i++) {
        if (s[i] == 'a') break;
        s[i]--;
      }
      cout << s;
      return 0;
    } else {
      for (int i = v[index] + 1; i < v[index + 1]; i++) s[i]--;
      cout << s;
      return 0;
    }
  }
}
