#include <bits/stdc++.h>
using namespace std;
constexpr int kMaxN = 100000;
constexpr int kMaxValue = 7000;
constexpr int kBitSetSize = (kMaxValue + 1) / 64 + 1;
typedef long long BitSet[kBitSetSize];
void Add(BitSet a, BitSet b, BitSet c) {
  for (int i = 0; i < kBitSetSize; ++i) {
    c[i] = a[i] ^ b[i];
  }
}
void Mult(BitSet a, BitSet b, BitSet c) {
  for (int i = 0; i < kBitSetSize; ++i) {
    c[i] = a[i] & b[i];
  }
}
void Copy(BitSet a, BitSet b) {
  for (int i = 0; i < kBitSetSize; ++i) {
    b[i] = a[i];
  }
}
int Parity(BitSet a) {
  long long x = 0;
  for (int i = 0; i < kBitSetSize; ++i) {
    x ^= a[i];
  }
  int ret = 0;
  for (int i = 0; i < 64; ++i) {
    ret ^= (x >> i) & 1;
  }
  return ret;
}
void XorBit(int i, BitSet a) { a[i / 64] ^= 1LL << (i % 64); }
BitSet sum[kMaxN + 1];
BitSet singleton[kMaxValue + 1];
BitSet query[kMaxValue + 1];
int main() {
  for (int i = 1; i <= kMaxValue; ++i) {
    bool is_square_free = true;
    for (int j = 1; j <= i; ++j) {
      if (i % j == 0) {
        XorBit(j, singleton[i]);
      }
      if (j > 1 && i % (j * j) == 0) {
        is_square_free = false;
      }
    }
    if (is_square_free) {
      for (int j = 1; j * i <= kMaxValue; ++j) {
        XorBit(j * i, query[j]);
      }
    }
  }
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < q; ++i) {
    int type = 0, x, y, z, v;
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d%d", &x, &v);
      Copy(singleton[v], sum[x]);
    } else if (type == 2) {
      scanf("%d%d%d", &x, &y, &z);
      Add(sum[y], sum[z], sum[x]);
    } else if (type == 3) {
      scanf("%d%d%d", &x, &y, &z);
      Mult(sum[y], sum[z], sum[x]);
    } else if (type == 4) {
      scanf("%d%d", &x, &v);
      static BitSet tmp;
      Mult(sum[x], query[v], tmp);
      printf("%d", Parity(tmp));
    }
  }
  printf("\n");
  return 0;
}
