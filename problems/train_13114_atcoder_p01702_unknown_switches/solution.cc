#include <bits/stdc++.h>

using namespace std;

int main()
{
  string base36 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
  int N, M, Q;
  while(cin >> N >> M >> Q, N || M || Q){
    long long bulb[1024]; //memset(bulb, -1LL, sizeof(bulb));
    for(int i = 0; i < M; i++) bulb[i] = (1LL << N) - 1LL;
    long long swch = 0LL;
    for(int i = 0; i < Q; i++){
      string S, B;
      cin >> S >> B;
      long long s = 0LL, b = 0LL;
      for(int j = 0; j < N; j++) if(S[j] == '1') s |= (1LL << j);
      for(int j = 0; j < M; j++) if(B[j] == '1') b |= (1LL << j);
      swch ^= s;
      for(int j = 0; j < M; j++){
	//if((b >> j) & 1LL) bulb[j] &= swch;
	if(B[j] == '1') bulb[j] &= swch;
	else bulb[j] &= ~swch;
      }
    }
    for(int i = 0; i < M; i++){
      int ctrl = -1;
      int cnt = 0;
      for(int j = 0; j < N; j++){
	//if((bulb[i] >> j) & 1LL) cnt++, ctrl = j;
	if(bulb[i] == (1LL << j)) cnt++, ctrl = j;
      }
      if(cnt == 1) cout << base36[ctrl];
      else cout << "?";
    }
    cout << endl;
  }
  return 0;
}