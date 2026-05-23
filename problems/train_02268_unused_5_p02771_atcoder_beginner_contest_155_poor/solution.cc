#include <iostream>
using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  cout << ((a == b) + (b == c) + (c == a) == 1 ? "Yes" : "No") << endl;
}
