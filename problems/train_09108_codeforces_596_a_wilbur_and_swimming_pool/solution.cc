#include <bits/stdc++.h>
using namespace std;
int cantidad;
int y[10000];
int x[10000];
int main() {
  cin >> cantidad;
  int area;
  int tempx;
  int tempy;
  for (int i = 0; i < cantidad; i++) {
    cin >> x[i] >> y[i];
  }
  if (cantidad == 1) {
    cout << -1;
  }
  if (cantidad == 2) {
    if (x[0] == x[1] || y[0] == y[1]) {
      cout << -1;
    } else {
      if (x[0] > x[1]) {
        tempx = x[0] - x[1];
      } else {
        tempx = x[1] - x[0];
      }
      if (y[0] > y[1]) {
        tempy = y[0] - y[1];
      } else {
        tempy = y[1] - y[0];
      }
      area = tempx * tempy;
      cout << area;
    }
  }
  if (cantidad == 3) {
    if (x[0] != x[1]) {
      if (x[0] > x[1]) {
        tempx = x[0] - x[1];
      } else {
        tempx = x[1] - x[0];
      }
    } else {
      if (x[0] > x[2]) {
        tempx = x[0] - x[2];
      } else {
        tempx = x[2] - x[0];
      }
    }
    if (y[0] != y[1]) {
      if (y[0] > y[1]) {
        tempy = y[0] - y[1];
      } else {
        tempy = y[1] - y[0];
      }
    } else {
      if (y[0] > y[2]) {
        tempy = y[0] - y[2];
      } else {
        tempy = y[2] - y[0];
      }
    }
    area = tempx * tempy;
    cout << area;
  }
  if (cantidad == 4) {
    if (x[0] != x[1]) {
      if (y[0] != y[1]) {
        if (x[0] > x[1]) {
          tempx = x[0] - x[1];
        } else {
          tempx = x[1] - x[0];
        }
        if (y[0] > y[1]) {
          tempy = y[0] - y[1];
        } else {
          tempy = y[1] - y[0];
        }
      }
    }
    if (x[0] != x[2]) {
      if (y[0] != y[2]) {
        if (x[0] > x[2]) {
          tempx = x[0] - x[2];
        } else {
          tempx = x[2] - x[0];
        }
        if (y[0] > y[2]) {
          tempy = y[0] - y[2];
        } else {
          tempy = y[2] - y[0];
        }
      }
    }
    if (x[0] != x[3]) {
      if (y[0] != y[3]) {
        if (x[0] > x[3]) {
          tempx = x[0] - x[3];
        } else {
          tempx = x[3] - x[0];
        }
        if (y[0] > y[3]) {
          tempy = y[0] - y[3];
        } else {
          tempy = y[3] - y[0];
        }
      }
    }
    area = tempx * tempy;
    cout << area;
  }
}
