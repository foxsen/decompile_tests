#include <bits/stdc++.h>
using namespace std;
const int infinito = 1000000000;
void minimiza(int &a, int b) { a = min(a, b); }
const int tope = 1 << 19;
const int primero = 1 << 18;
void reset(int minimo[tope]) {
  for (int i = tope - 1; i >= 0; i--) minimo[i] = infinito;
}
void insertar(int minimo[tope], int pos, int val) {
  pos += primero;
  minimo[pos] = val;
  while (pos > 1) {
    pos /= 2;
    minimo[pos] = min(minimo[2 * pos], minimo[2 * pos + 1]);
  }
}
void borrar(int minimo[tope], int pos) { insertar(minimo, pos, infinito); }
int minimoantes(int minimo[tope], int pos) {
  pos += primero;
  int mini = minimo[pos];
  while (pos > 1) {
    if (pos % 2 == 1) minimiza(mini, minimo[pos - 1]);
    pos /= 2;
  }
  return mini;
}
void borrar(multiset<int> &s, int x) {
  multiset<int>::iterator it = s.find(x);
  s.erase(x);
}
void insertar(multiset<int> &s, int x) { s.insert(x); }
int getmin(multiset<int> &s) {
  if (int(s.size()) == 0) return infinito;
  return *(s.begin());
}
const int limite = 1000000;
int n;
int a[limite];
vector<int> limitele[limite], limiteri[limite];
multiset<int> inside[2], outside[2];
set<int> posinside;
int minimo[2][tope];
int main() {
  ios::sync_with_stdio(false);
  for (int i = 0; i < 2; i++) reset(minimo[i]);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    insertar(minimo[0], i, i + a[i]);
    if (a[i] < i) {
      limitele[a[i] + 1].push_back(i);
      limiteri[i + (i - a[i])].push_back(i);
    }
  }
  int sol = infinito;
  for (int ind = 1; ind <= n; ind++) {
    {
      vector<int> v = limitele[ind];
      for (int iv = 0; iv < int(v.size()); iv++) {
        int i = v[iv];
        borrar(minimo[0], i);
        insertar(inside[0], i + a[i]);
        posinside.insert(i);
      }
    }
    {
      int i = ind;
      if (a[i] < i) {
        borrar(inside[0], i + a[i]);
        insertar(inside[1], -i + a[i]);
      } else {
        borrar(minimo[0], i);
        insertar(minimo[1], i, -i + a[i]);
      }
    }
    {
      vector<int> v = limiteri[ind];
      for (int iv = 0; iv < int(v.size()); iv++) {
        int i = v[iv];
        borrar(inside[1], -i + a[i]);
        posinside.erase(i);
        insertar(minimo[1], i, -i + a[i]);
        posinside.erase(i);
      }
    }
    if (int(posinside.size()) > 0) {
      int pos = *(posinside.begin());
      minimiza(sol, max(min(minimoantes(minimo[0], pos) - ind,
                            minimoantes(minimo[1], pos) + ind),
                        min(getmin(inside[0]) - ind, getmin(inside[1]) + ind)));
    }
  }
  if (infinito / 2 < sol)
    cout << -1 << endl;
  else
    cout << sol << endl;
}
