#include<iostream>
#include<string>

using namespace std;

void Run(int&, int&, int&, int&);

int main(){
  int i, n, top, bottom, north, south, west, east;
  string str;

  while(1){
    cin >> n;
    if(n == 0) break;

    top = 1;
    bottom = 6;
    north = 2;
    south = 5;
    west = 3;
    east = 4;

    for(i=0; i<n; ++i){
      cin >> str;

      if(str == "south")
        Run(top, north, bottom, south);
      else if(str == "north")
        Run(top, south, bottom, north);
      else if(str == "east")
        Run(top, west, bottom, east);
      else if(str == "west")
        Run(top, east, bottom, west);
    }

    cout << top << endl;
  }

  return 0;
}

void Run(int& a, int& b, int& c, int& d){
  int e;
  e = a;
  a = b;
  b = c;
  c = d;
  d = e;
}