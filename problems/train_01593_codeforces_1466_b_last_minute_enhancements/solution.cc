#include<bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> arr1(n);
    for (int i=0;i<n;++i){
      cin >> arr[i];
      arr1[i] = arr[i] + 1;
    }
    set<int> st;
    for (int i=0;i<n;++i){
      if (st.find(arr[i]) == st.end()) st.insert(arr[i]);
      else st.insert(arr1[i]);
    }
    cout << st.size() << endl;
  }
}

/*
1 2 2 2 5 6
2 3 3 3 6 7
1 2 3 3 5 6


113445
224556
123456
*/