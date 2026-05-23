#include<bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin >> a;
  set<int> st;
  while(st.count(a) == 0){
    st.insert(a);
    if(a % 2 == 0)
      a /= 2;
    else{
      a = a*3 + 1;
    }
  }
    cout << st.size()+1 << endl;
}