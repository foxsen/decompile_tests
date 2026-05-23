#include<iostream>
#include<tuple>
#include<algorithm>
using namespace std;

int main(){
  
  int n, v, w;
  char t;
  long long d;
  string s;
  
  cin >> n;
  tuple<int, int, char, long long, string> goods[n];
  for(int i = 0;i < n;i++){
    cin >> v >> w >> t >> d >> s;
    goods[i] = make_tuple(v, w, t, d, s);
  }
  
  sort(goods, goods + n);
  
  for(int i = 0;i < n;i++){
    tie(v, w, t, d, s) = goods[i];
    cout << v << " " << w << " " << t << " " << d << " " << s << endl;
  }
  
  return 0;
}
