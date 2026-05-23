#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() 
{
  int count=0;

  string w,t;
  cin >> w;

  while( cin >> t ) 
  {
    if( t == "END_OF_TEXT" ) break;  
    transform( t.begin(), t.end(), t.begin(), ::tolower );
    if( t == w ) count++;
  }

  cout << count << endl;
  
  return 0;
}

