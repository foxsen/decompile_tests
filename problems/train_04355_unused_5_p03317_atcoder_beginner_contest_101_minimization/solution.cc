#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  double n,k;
  cin >> n >> k;
  cout << (int)ceil((n-1)/(k-1)) << endl;
  return 0;
}