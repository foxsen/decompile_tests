#include <algorithm>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

struct Tetro {
  int h, w;
  vector<vector<char>> b;
  Tetro(int h, int w, vector<vector<char>> &b) : h(h), w(w), b(b) {}
};

bool is_empty(char ch) { return ch == '.'; }
bool is_filled(char ch) { return ch == '#'; }

bool check(int i, int skip, vector<vector<char>> &b, vector<Tetro> &tetros) {
  if (i == tetros.size()) return true;
  if (i == skip) return check(i + 1, skip, b, tetros);
  int h = b.size(), w = b[0].size();
  auto t = tetros[i];
  rep(y, h) {
    rep(x, w) {
      if (y + t.h <= h and x + t.w <= w) {
        bool can_put = true;
        rep(dy, t.h) {
          rep(dx, t.w) {
            if (is_filled(t.b[dy][dx]) and is_filled(b[y + dy][x + dx])) {
              can_put = false;
            }
          }
        }
        if (can_put) {
          rep(dy, t.h) rep(dx, t.w) {
            if (is_filled(t.b[dy][dx])) b[y + dy][x + dx] = '#';
          }
          auto res = check(i + 1, skip, b, tetros);
          rep(dy, t.h) rep(dx, t.w) {
            if (is_filled(t.b[dy][dx])) b[y + dy][x + dx] = '.';
          }
          if (res) return true;
        }
      }
    }
  }
  return false;
}

bool solve(vector<vector<char>> &b, vector<Tetro> &tetros) {
  rep(i, 4) {
    auto res = check(0, i, b, tetros);
    if (res) return true;
  }
  return false;
}

int main() {

  vector<Tetro> tetros;
  rep(i, 4) {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> b(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> b[y][x];
    tetros.emplace_back(h, w, b);
  }
  const int H = 4, W = 10;
  int n;
  cin >> n;
  while (n--) {
    vector<vector<char>> B(H, vector<char>(W));
    rep(i, H) rep(j, W) cin >> B[i][j];
    auto res = solve(B, tetros);
    cout << (res ? "Yes" : "No") << endl;
  }

  return 0;
}
