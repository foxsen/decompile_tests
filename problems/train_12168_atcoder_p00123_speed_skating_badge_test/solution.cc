#include<iostream>

using namespace std;

int main(){

  double ina, inb;

  while(cin >> ina >>inb){

    if(ina < 35.5 && inb < 71) cout << "AAA" << endl;
    else if(ina < 37.5 && inb < 77) cout << "AA" << endl;
    else if(ina < 40 && inb < 83) cout << "A" << endl;
    else if(ina < 43 && inb < 89) cout << "B" << endl;
    else if(ina < 50 && inb < 105) cout << "C" << endl;
    else if(ina < 55 && inb < 116) cout << "D" << endl;
    else if(ina < 70 && inb < 148) cout << "E" << endl;
    else  cout << "NA" << endl;

  }
  return 0;

}