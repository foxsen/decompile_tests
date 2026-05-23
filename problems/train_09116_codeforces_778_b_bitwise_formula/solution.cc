#include <bits/stdc++.h>
using namespace std;
int n, m;
char var[12], def[4], buf[1005];
unordered_map<string, int> varId;
pair<int, int> operand[5005];
int val[5005][1005];
char op[5005][4];
char mx[1005], mn[1005];
int calc(int id, int idx) {
  if (op[id][0] == 'X') {
    return val[operand[id].first][idx] ^ val[operand[id].second][idx];
  } else if (op[id][0] == 'O') {
    return val[operand[id].first][idx] | val[operand[id].second][idx];
  } else if (op[id][0] == 'A') {
    return val[operand[id].first][idx] & val[operand[id].second][idx];
  } else {
    return val[id][idx];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  int tot = 0;
  varId["?"] = ++tot;
  for (int i = 0; i < n; i++) {
    memset(var, 0, sizeof(var));
    memset(buf, 0, sizeof(buf));
    scanf("%s%s%s", var, def, buf);
    varId[var] = ++tot;
    if (buf[0] == '0' || buf[0] == '1') {
      for (int i = 0; i < m; i++) {
        val[tot][i] = buf[i] - '0';
      }
      op[tot][0] = 'N';
    } else {
      memset(var, 0, sizeof(var));
      scanf("%s%s", op[tot], var);
      operand[tot] = make_pair(varId[buf], varId[var]);
    }
  }
  for (int i = 0; i < m; i++) {
    int cnt1 = 0;
    val[1][i] = 0;
    for (int j = 2; j <= tot; j++) {
      val[j][i] = calc(j, i);
      cnt1 += val[j][i];
    }
    int cnt2 = 0;
    val[1][i] = 1;
    for (int j = 2; j <= tot; j++) {
      val[j][i] = calc(j, i);
      cnt2 += val[j][i];
    }
    if (cnt1 > cnt2) {
      mx[i] = '0';
      mn[i] = '1';
    } else if (cnt1 < cnt2) {
      mx[i] = '1';
      mn[i] = '0';
    } else {
      mx[i] = mn[i] = '0';
    }
  }
  printf("%s\n%s\n", mn, mx);
}
