#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  long k,ans,a=1,b=1;
  ans=0;
  cin >> s >> k;

  for(int i=0;i<s.size()-1;i++) {
    if(s.at(i)==s.at(i+1)) i++,ans++;
  };
  ans*=k;
  if(s.at(0)==s.at(s.size()-1)) {
    for(int i=0;i<s.size()-1;i++) {
      if(s.at(i)==s.at(i+1)) a++;
      else break;
    };
    for(int i=s.size()-1;i>0;i--) {
      if(s.at(i)==s.at(i-1)) b++;
      else break;
    };
    if(a==s.size()) {
      ans=s.size()*k/2;
    } else {
      if(a%2==1&&b%2==1) ans+=k-1;
    };
  };

  cout << ans << endl;
}