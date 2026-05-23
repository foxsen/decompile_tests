#include <cstdio>
#include <iostream>
using namespace std;
using ui = unsigned int;
using ul = unsigned long;
#pragma GCC optimize("Ofast")
#define loop(i, n) for (ui i = 0; i < n; i++)
ul bit[550010];ui N;inline ul sum(ui x){ul ret = 0;while (x > 0){ret += bit[x];x -= x & -x;}return ret;}inline void add(ui i, ul x){i++;while (i <= N){bit[i] += x;i += i & -i;}}int main(){cin.tie(0);ios::sync_with_stdio(false);ui Q;cin >> N >> Q;loop(i, N){ul A;cin >> A;bit[i + 1] = A;}for (ui i = 1; i < N; i++)bit[i + (i & -i)] += bit[i];loop(i, Q){ui a, b, c;cin >> a >> b >> c;if (a == 0)add(b, c);else cout << sum(c) - sum(b) << "\n";}return 0;}
