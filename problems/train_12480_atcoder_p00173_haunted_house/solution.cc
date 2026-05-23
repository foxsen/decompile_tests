#include <iostream>
#include <string>
using namespace std;
int main()
{
  int i,j,k;
  string n;
  for(i=0;i<9;i++){
    cin >> n >> j >> k;
    cout << n << " " << j+k << " " << j*200+k*300 << endl;
  }
  return 0;
}