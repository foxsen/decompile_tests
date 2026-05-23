#include <bits/stdc++.h>
using namespace std;

int main()
{
 	int n; cin >> n;set<int> s;
  for(int i = 0; i < n; ++i) 
  {
    int num; cin >> num; s.insert(num);
  }
  int m = s.size();
  if(m == n) cout << "YES";
  else cout << "NO";
  return 0;
}