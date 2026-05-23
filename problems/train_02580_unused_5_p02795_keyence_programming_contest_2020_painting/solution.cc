#include <iostream>
using namespace std;
int main(){
  int h,w,n;
  cin >> h >> w >> n;
  cout << (n + max(h,w) -1) / max(h,w) << endl;
}
