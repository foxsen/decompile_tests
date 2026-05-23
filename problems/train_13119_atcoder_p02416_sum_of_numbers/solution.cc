#include <bits/stdc++.h>
using namespace std;

int main() {
  while(true){
    string s;
    cin >> s;
    if(s == "0") return 0;
    int sum = 0;
    for(int i = 0;i < s.size();i++){
      sum += s[i]-'0';
    }
    cout << sum << endl;
  }
}
