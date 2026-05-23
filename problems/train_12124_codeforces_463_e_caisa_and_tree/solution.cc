#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
struct par {
  int x, y;
  par(int _x = 0, int _y = 0) {
    x = _x;
    y = _y;
  }
};
int n, q;
vector<int> graf[MAXN];
map<int, int>::iterator it, it2;
map<int, int> moji[MAXN], rj[MAXN], trenutna;
int niz[MAXN], dubina[MAXN];
void ispis() {
  for (it = trenutna.begin(); it != trenutna.end(); ++it)
    cout << "(" << it->first << " " << it->second << ") ";
  cout << endl;
}
void rek(int roditelj, int cvor) {
  rj[cvor].clear();
  for (it = moji[cvor].begin(); it != moji[cvor].end(); ++it) {
    int prvi = it->first, drugi = it->second;
    if (drugi == 0) continue;
    it2 = trenutna.find(prvi);
    if (it2 == trenutna.end()) continue;
    int t = trenutna[prvi];
    if (dubina[t] > dubina[rj[cvor][prvi]]) rj[cvor][prvi] = t;
  }
  vector<par> umetnuti;
  for (it = moji[cvor].begin(); it != moji[cvor].end(); ++it) {
    int prvi = it->first, drugi = it->second;
    if (drugi == 0) continue;
    umetnuti.push_back(par(prvi, trenutna[prvi]));
  }
  for (int i = 0; i < graf[cvor].size(); i++) {
    int dalje = graf[cvor][i];
    if (dalje == roditelj) continue;
    for (it = moji[cvor].begin(); it != moji[cvor].end(); ++it) {
      int prvi = it->first, drugi = it->second;
      if (drugi == 0) continue;
      trenutna[prvi] = cvor;
    }
    rek(cvor, dalje);
    for (int i = 0; i < umetnuti.size(); i++)
      trenutna[umetnuti[i].x] = umetnuti[i].y;
  }
  for (int i = 0; i < umetnuti.size(); i++)
    trenutna[umetnuti[i].x] = umetnuti[i].y;
}
void postavi() {
  trenutna.clear();
  rek(-1, 1);
}
void update(int indeks, int x) {
  moji[indeks].clear();
  int korijen = (int)sqrt(x);
  for (int i = 2; i <= korijen; i++) {
    if (x % i == 0) {
      moji[indeks][i] = 1;
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) moji[indeks][x] = 1;
}
void postavi_dubine(int roditelj, int cvor) {
  dubina[cvor] = dubina[roditelj] + 1;
  for (int i = 0; i < graf[cvor].size(); i++) {
    int sad = graf[cvor][i];
    if (sad == roditelj) continue;
    postavi_dubine(cvor, sad);
  }
}
int upit(int x) {
  int ret = -1;
  for (it = rj[x].begin(); it != rj[x].end(); ++it) {
    int drugi = it->second;
    if (drugi > 0)
      if (ret == -1 || ret != -1 && dubina[drugi] > dubina[ret]) ret = drugi;
  }
  return ret;
}
void prosti(int x) {
  cout << x << ": " << niz[x] << ": ";
  for (it = moji[x].begin(); it != moji[x].end(); ++it)
    cout << it->first << " ";
  cout << endl;
  for (it = rj[x].begin(); it != rj[x].end(); ++it)
    cout << "(" << it->first << ", " << it->second << ") ";
  cout << endl;
  cout << "-------------" << endl;
}
void dbg() {
  for (int i = 1; i <= n; i++) prosti(i);
  cout << "------------" << endl;
}
int main() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &niz[i]);
    update(i, niz[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    graf[a].push_back(b);
    graf[b].push_back(a);
  }
  postavi_dubine(0, 1);
  postavi();
  for (int i = 0; i < q; i++) {
    int tip;
    scanf("%d", &tip);
    if (tip == 1) {
      int x;
      scanf("%d", &x);
      printf("%d\n", upit(x));
    } else if (tip == 2) {
      int x, y;
      scanf("%d %d", &x, &y);
      niz[x] = y;
      update(x, y);
      postavi();
    }
  }
  return 0;
}
