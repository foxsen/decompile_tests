#include <bits/stdc++.h>
using namespace std;
string s[6];
char out[107][107];
vector<int> szs;
const int n = 6;
int f11 = -1, f12 = -1, f13 = -1, f21 = -1, f22 = -1, f23 = -1;
bool cdyx(string a, string b) {
  if (((int)(a).size()) < ((int)(b).size())) return 1;
  if (((int)(a).size()) > ((int)(b).size())) return 0;
  if (a > b) return 1;
  if (a < b) return 0;
  return 0;
}
bool vct___cmp(vector<string> a, vector<string> b) {
  if (!((int)(a).size())) return 0;
  if (!((int)(b).size())) return 1;
  for (int i = 0; i < min(((int)(a).size()), ((int)(b).size())); i++)
    if (a[i] < b[i])
      return 1;
    else if (a[i] > b[i])
      return 0;
  return 0;
}
vector<string> ans, aans;
int main() {
  cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4] >> s[5];
  sort(s, s + 6);
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      for (int k = 0; k < 6; k++)
        for (int l = 0; l < 6; l++)
          for (int a = 0; a < 6; a++)
            for (int b = 0; b < 6; b++)
              if (i != j && i != k && i != l && i != a && i != b && j != k &&
                  j != l && j != a && j != b && k != l && k != a && k != b &&
                  l != a && l != b && a != b) {
                if (((int)(s[i]).size()) + ((int)(s[a]).size()) !=
                    ((int)(s[k]).size()) + 1)
                  continue;
                if (((int)(s[j]).size()) + ((int)(s[b]).size()) !=
                    ((int)(s[l]).size()) + 1)
                  continue;
                if (s[i][0] != s[j][0]) continue;
                if (s[i][((int)(s[i]).size()) - 1] != s[l][0]) continue;
                if (s[j][((int)(s[j]).size()) - 1] != s[k][0]) continue;
                if (s[l][((int)(s[j]).size()) - 1] !=
                    s[k][((int)(s[i]).size()) - 1])
                  continue;
                if (s[l][((int)(s[l]).size()) - 1] != s[a][0]) continue;
                if (s[b][0] != s[k][((int)(s[k]).size()) - 1]) continue;
                if (s[a][((int)(s[a]).size()) - 1] !=
                    s[b][((int)(s[b]).size()) - 1])
                  continue;
                memset((void*)out, 0, sizeof(out));
                aans.clear();
                for (int aa = 0; aa < ((int)(s[i]).size()); aa++)
                  out[aa][0] = s[i][aa];
                for (int aa = 0; aa < ((int)(s[j]).size()); aa++)
                  out[0][aa] = s[j][aa];
                for (int aa = 0; aa < ((int)(s[k]).size()); aa++)
                  out[aa][((int)(s[j]).size()) - 1] = s[k][aa];
                for (int aa = 0; aa < ((int)(s[l]).size()); aa++)
                  out[((int)(s[i]).size()) - 1][aa] = s[l][aa];
                for (int aa = 0; aa < ((int)(s[a]).size()); aa++)
                  out[((int)(s[i]).size()) - 1 + aa][((int)(s[l]).size()) - 1] =
                      s[a][aa];
                for (int aa = 0; aa < ((int)(s[b]).size()); aa++)
                  out[((int)(s[k]).size()) - 1][((int)(s[j]).size()) - 1 + aa] =
                      s[b][aa];
                for (int i = 0; i < ((int)(s[k]).size()); i++)
                  for (int j = 0; j < ((int)(s[l]).size()); j++)
                    if (!out[i][j]) out[i][j] = '.';
                for (int i = 0; i < ((int)(s[k]).size()); i++)
                  aans.push_back(out[i]);
                if (vct___cmp(aans, ans)) ans = aans;
              }
  if (!((int)(ans).size())) return puts("Impossible"), 0;
  for (int i = 0; i < ((int)(ans).size()); i++) cout << ans[i] << endl;
  return 0;
}
