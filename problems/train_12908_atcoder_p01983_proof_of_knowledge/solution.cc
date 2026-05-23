#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  while (true) {
    string s;
    cin >> s;
    if (s == ".") return 0;
    
    reverse(s.begin(), s.end());
    
    int p;
    cin >> p;
    
    int hash;
    map<int, int> mp;
    for (int num = 0; num < 10000; num++) {
      vector<int> x(4);
      int tmp = num;
      for (int i = 3; i >= 0; i--) {
        x.at(i) = tmp % 10;
        tmp /= 10;
      }
      
      stack<int> st;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '[' || s[i] == ']') continue;
        if ('a' <= s[i] && s[i] <= 'd') st.push(x[s[i] - 'a']);
        
        if (s[i] == '+') {
          int k1 = st.top();
          st.pop();
          int k2 = st.top();
          st.pop();
          int k3 = (k1 | k2);
          st.push(k3);
        }
        if (s[i] == '*') {
          int k1 = st.top();
          st.pop();
          int k2 = st.top();
          st.pop();
          int k3 = (k1 & k2);
          st.push(k3);
        }
        if (s[i] == '^') {
          int k1 = st.top();
          st.pop();
          int k2 = st.top();
          st.pop();
          int k3 = (k1 ^ k2);
          st.push(k3);
        }
      }
      
    mp[st.top()]++;
    if (p == num) hash = st.top();
    }
    
    cout << hash << " " << mp[hash] << '\n';
  }
}
