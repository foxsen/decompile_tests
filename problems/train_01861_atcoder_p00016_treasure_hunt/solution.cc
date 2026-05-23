#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1);

int main() {
  int len, ang;
  double ax = 0, ay = 0;
  double vis = 90;

  while(scanf("%d,%d", &len, &ang)) {
    if(len+ang == 0) break;

    ax += len * cos(pi*vis/180);
    ay += len * sin(pi*vis/180);
    vis -= ang; 
  }

  cout << (int)ax << endl;
  cout << (int)ay << endl;
}