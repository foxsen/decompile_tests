#include <iostream>
using namespace std;

int main()
{
  int a, b, k;
  cin >> a >> b >> k;

  for(int i = a; i <= b; i++)
  {
    if(i < (a+k) || i > (b-k))
    {
      cout << i << endl;
    }
  }
  return 0;
}
