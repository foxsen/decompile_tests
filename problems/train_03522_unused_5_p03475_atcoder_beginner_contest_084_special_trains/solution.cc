#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  vector<int> C(510), S(510), F(510);

  cin >> N;
  for(int i=0; i<N-1; i++) cin >> C[i] >> S[i] >> F[i];

  for(int j=0; j<N; j++){
    int t = 0;
    for(int i=j; i<N-1; i++){
      if(t < S[i]){
       t = S[i];
     } else {
       while(t % F[i] != 0) t++;
      }
     t += C[i];
    }

    cout << t << endl;
  }
}
  
  