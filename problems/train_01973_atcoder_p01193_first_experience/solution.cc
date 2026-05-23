#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

int main()
{
  int r1, r2;
  char r3;
  string str, fm;
  bool f;

  while(cin>>fm){
    r1 = r2 = 0;
    r3 = ' ';
    f = true;
    str = "";
    for(int i = 0; f && i < fm.size(); ++i){
      if(isdigit(fm[i])){
	str += fm[i];
      } else {
	r2 = atoi(str.c_str());
	str = "";

	if(r3 == ' ') r1 = r2;
	else if(r3 == '+') r1 += r2;
	else if(r3 == '-') r1 -= r2;
	else if(r3 == '*') r1 *= r2;
	else if(r3 == '=') break;
	
	if(r1 < 0 || r2 < 0 || r2 >= 10000 || r1 >= 10000) f = false;
	r3 = fm[i];
      }
    }

      if(!f) cout << "E" << endl;
      else cout << r1 << endl;
  }

  return 0;
}