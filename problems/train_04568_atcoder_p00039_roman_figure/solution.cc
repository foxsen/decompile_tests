#include <iostream>
using namespace std;

int c2i[128];

void init(){
  c2i['I'] = 1;
  c2i['V'] = 5;
  c2i['X'] = 10;
  c2i['L'] = 50;
  c2i['C'] = 100;
  c2i['D'] = 500;
  c2i['M'] = 1000;
}

int main() {
  string str;

  init();
  
  while(cin >> str) {
    int n = str.size();
    int sum = 0;
    for(int i = 0; i < n-1; i++) {
      sum += c2i[str[i]] * ( (c2i[str[i]] < c2i[str[i+1]]) ? -1 : 1);
    }
    sum += c2i[str[n-1]];
    
    cout << sum << endl;
  }

  return 0;
}