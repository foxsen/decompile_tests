#include<iostream>
#include<set>
using namespace std;

set<string> res;
string c[10];
bool use[10];
int n,k;
string ans;

void rec(int a){
  string tmp;
  if(!a){
    res.insert(ans);
    return;
  }
  for(int i=0;i<n;i++){
    if(!use[i]){
      use[i] = true;
      tmp = ans;
      ans += c[i];
      rec(a-1);
      ans = tmp;
      use[i] = false;
    }
  }
}

int main(){
  while(1){
    cin >> n;
    cin >> k;
    if(!n && !k)break;

    for(int i=0;i<n;i++)cin >> c[i];
    for(int i=0;i<n;i++)use[i] = false;

    res.clear();
    rec(k);

    cout << res.size() << endl;
  }
}