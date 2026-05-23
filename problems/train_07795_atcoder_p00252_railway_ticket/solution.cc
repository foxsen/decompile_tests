#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  string a,b,c;
  string d = "",e = "Close",f = "Open",g;
  cin >> a >> b >> c;
  d += a+b+c;
  if(d == "100"||d == "010" || d == "000")g = e;
  else g = f;
  cout << g << endl;
  return 0;
}