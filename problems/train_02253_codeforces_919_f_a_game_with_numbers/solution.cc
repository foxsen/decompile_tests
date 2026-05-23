#include <bits/stdc++.h>
using namespace std;
int codifica(int cuantos[5]) {
  int c = 0;
  int b = 0;
  for (int i = 0; i < 5; i++) {
    b += cuantos[i];
    if (i < 4) {
      c |= 1 << b;
      b++;
    }
  }
  return c;
}
void decodifica(int c, int cuantos[5]) {
  for (int i = 0; i < 5; i++) cuantos[i] = 0;
  int i = 0;
  for (int b = 0; b < 12; b++) {
    if (c & (1 << b))
      i++;
    else
      cuantos[i]++;
  }
}
int cuantos[2][5];
pair<int, int> codifica() {
  return pair<int, int>(codifica(cuantos[0]), codifica(cuantos[1]));
}
void decodifica(pair<int, int> p) {
  decodifica(p.first, cuantos[0]);
  decodifica(p.second, cuantos[1]);
}
int n;
int estado[1 << 12];
int gana[1 << 12][1 << 12];
int pierde[1 << 12][1 << 12];
int aridad[1 << 12][1 << 12];
int vepierde[1 << 12][1 << 12];
queue<pair<int, int> > q;
int main() {
  for (int c = 0; c < 1 << 12; c++)
    if (__builtin_popcount(c) == 4) estado[n++] = c;
  for (int i0 = 0; i0 < n; i0++) {
    for (int i1 = 0; i1 < n; i1++) {
      int c0 = estado[i0];
      int c1 = estado[i1];
      decodifica(pair<int, int>(c0, c1));
      for (int a = 0; a < 25; a++) {
        int pos0 = a % 5;
        int pos1 = a / 5;
        if (pos0 > 0 and cuantos[0][pos0] and pos1 > 0 and cuantos[1][pos1])
          aridad[c0][c1] |= 1 << a;
      }
      if (cuantos[1][0] == 8) {
        pierde[c0][c1] = 1;
        q.push(pair<int, int>(c0, c1));
      }
    }
  }
  while (not q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    decodifica(p);
    for (int pos1 = 0; pos1 < 5; pos1++) {
      for (int pos0 = 0; pos0 < 5; pos0++) {
        if (pos0 > 0 and pos1 > 0 and cuantos[0][pos0] != 0 and
            cuantos[1][(pos0 + pos1) % 5] != 0) {
          int nextpos1 = (pos1 + pos0) % 5;
          int a = 5 * pos0 + pos1;
          cuantos[1][pos1]++;
          cuantos[1][nextpos1]--;
          pair<int, int> nextp = codifica();
          int &c0 = nextp.first;
          int &c1 = nextp.second;
          swap(c0, c1);
          if (not gana[c0][c1] and aridad[c0][c1] & (1 << a)) {
            aridad[c0][c1] ^= 1 << a;
            gana[c0][c1] |= pierde[p.first][p.second];
            if (aridad[c0][c1] == 0 or gana[c0][c1]) {
              pierde[c0][c1] = not gana[c0][c1];
              q.push(nextp);
            }
          }
          cuantos[1][pos1]--;
          cuantos[1][nextpos1]++;
        }
      }
    }
  }
  int casos;
  scanf("%d", &casos);
  for (int cas = 0; cas < casos; cas++) {
    int f;
    scanf("%d", &f);
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 8; j++) cuantos[i][j] = 0;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 8; j++) {
        int x;
        scanf("%d", &x);
        cuantos[i][x]++;
      }
    }
    pair<int, int> p = codifica();
    int c0 = p.first;
    int c1 = p.second;
    if (f) swap(c0, c1);
    if (gana[c0][c1]) {
      if (f)
        printf("Bob\n");
      else
        printf("Alice\n");
    } else if (pierde[c0][c1]) {
      if (f)
        printf("Alice\n");
      else
        printf("Bob\n");
    } else {
      printf("Deal\n");
    }
  }
}
