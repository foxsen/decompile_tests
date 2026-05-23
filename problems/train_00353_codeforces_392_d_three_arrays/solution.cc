#include <bits/stdc++.h>
using namespace std;
struct Tnode {
  int x, y, z;
} doing[1000050];
struct Type {
  int pos, val, size;
  Type *father, *son[2];
  Type() {}
  Type(Type *f, int p, int v, int s) {
    pos = p;
    val = v;
    size = s;
    father = f;
    son[0] = son[1] = 0;
  }
} memory[1000050], *root;
struct Tree {
  int best, add;
} tree[2222222];
int vs, n, m, data[1000050], x[1000050], y[1000050], z[1000050];
int Rand() { return (rand() << 15) | rand(); }
bool Cmp(Tnode a, Tnode b) { return a.x < b.x; }
int Half(int ask) {
  int low, mid, high;
  low = 0;
  high = m + 1;
  while (low + 1 < high) {
    mid = (low + high) >> 1;
    if (data[mid] <= ask) {
      low = mid;
    } else {
      high = mid;
    }
  }
  return low;
}
void Down(int root) {
  if (tree[root].add != 0) {
    tree[root].best += tree[root].add;
    tree[root << 1].add += tree[root].add;
    tree[(root << 1) | 1].add += tree[root].add;
    tree[root].add = 0;
  }
  return;
}
void Add(int root, int nowleft, int nowright, int askleft, int askright,
         int add) {
  int mid = (nowleft + nowright) >> 1;
  Down(root);
  if (nowright < askleft || askright < nowleft) {
    return;
  }
  if (askleft <= nowleft && nowright <= askright) {
    tree[root].add += add;
    Down(root);
    return;
  }
  Add(root << 1, nowleft, mid, askleft, askright, add);
  Add((root << 1) | 1, mid + 1, nowright, askleft, askright, add);
  tree[root].best = min(tree[root << 1].best, tree[(root << 1) | 1].best);
  return;
}
int Ask(int root, int nowleft, int nowright, int askleft, int askright) {
  int mid = (nowleft + nowright) >> 1;
  Down(root);
  if (nowright < askleft || askright < nowleft) {
    return 666666;
  }
  if (askleft <= nowleft && nowright <= askright) {
    return tree[root].best;
  }
  return min(Ask(root << 1, nowleft, mid, askleft, askright),
             Ask((root << 1) | 1, mid + 1, nowright, askleft, askright));
}
void Update(Type *current) {
  if (!current) {
    return;
  }
  current->size = 1;
  if (current->son[0]) {
    current->size += current->son[0]->size;
  }
  if (current->son[1]) {
    current->size += current->son[1]->size;
  }
  return;
}
void Rotate(Type *current, int flag) {
  current->father->son[flag ^ 1] = current->son[flag];
  if (current->son[flag]) {
    current->son[flag]->father = current->father;
  }
  current->son[flag] = current->father;
  if (current->father->father) {
    current->father->father
        ->son[current->father->father->son[0] != current->father] = current;
  }
  current->father = current->father->father;
  current->son[flag]->father = current;
  Update(current->son[flag]);
  return;
}
void Splay(Type *current, Type *target) {
  while (current->father != target) {
    if (current->father->father == target) {
      Rotate(current, current->father->son[1] != current);
    } else if (current->father->father->son[0] == current->father &&
               current->father->son[0] == current) {
      Rotate(current->father, 1);
      Rotate(current, 1);
    } else if (current->father->father->son[1] == current->father &&
               current->father->son[1] == current) {
      Rotate(current->father, 0);
      Rotate(current, 0);
    } else {
      Rotate(current, current->father->son[1] != current);
      Rotate(current, current->father->son[1] != current);
    }
  }
  Update(current);
  if (!target) {
    root = current;
  }
  return;
}
void Bigger(int ask, Type *target) {
  Type *current = root, *best = 0;
  while (current) {
    if (current->pos > ask) {
      best = current;
      current = current->son[0];
    } else {
      current = current->son[1];
    }
  }
  Splay(best, target);
  return;
}
void Smaller(int ask, Type *target) {
  Type *current = root, *best = 0;
  while (current) {
    if (current->pos < ask) {
      best = current;
      current = current->son[1];
    } else {
      current = current->son[0];
    }
  }
  Splay(best, target);
  return;
}
void Find(int ask, Type *target) {
  Type *current = root;
  while (current) {
    if (current->son[0]) {
      if (ask == current->son[0]->size + 1) {
        break;
      }
    } else if (ask == 1) {
      break;
    }
    if (current->son[0] && ask < current->son[0]->size + 1) {
      current = current->son[0];
    } else {
      ask--;
      if (current->son[0]) {
        ask -= current->son[0]->size;
      }
      current = current->son[1];
    }
  }
  Splay(current, target);
  return;
}
void Find_Left(Type *current) {
  while (true) {
    if (!current->son[0]) {
      break;
    }
    current = current->son[0];
  }
  Splay(current, 0);
  return;
}
void Find_Right(Type *current) {
  while (true) {
    if (!current->son[1]) {
      break;
    }
    current = current->son[1];
  }
  Splay(current, 0);
  return;
}
int main() {
  int i, j, temp, best, delta, rank, last, maxi, mx, my, mz;
  bool solved;
  Type *current;
  srand((unsigned)time(0));
  scanf("%d", &n);
  m = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d", &x[i]);
    data[++m] = x[i];
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", &y[i]);
    data[++m] = y[i];
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", &z[i]);
    data[++m] = z[i];
  }
  sort(data + 1, data + m + 1);
  for (i = j = 1; i < m; i++)
    if (data[i + 1] != data[j]) {
      data[++j] = data[i + 1];
    }
  m = j;
  for (i = 1; i <= m; i++) {
    doing[i].x = doing[i].y = doing[i].z = n + 1;
  }
  for (i = 1; i <= n; i++) {
    temp = Half(x[i]);
    doing[temp].x = min(doing[temp].x, i);
  }
  for (i = 1; i <= n; i++) {
    temp = Half(y[i]);
    doing[temp].y = min(doing[temp].y, i);
  }
  for (i = 1; i <= n; i++) {
    temp = Half(z[i]);
    doing[temp].z = min(doing[temp].z, i);
  }
  sort(doing + 1, doing + m + 1, Cmp);
  for (i = 1; i <= n; i++) {
    Add(1, 1, n, i, i, i);
  }
  memory[++vs] = Type(0, n + 1, 0, 3);
  root = &memory[vs];
  memory[++vs] = Type(root, -666666, 0, 1);
  root->son[0] = &memory[vs];
  memory[++vs] = Type(root, 666666, 0, 1);
  root->son[1] = &memory[vs];
  best = 3 * n;
  mx = my = mz = 0;
  for (i = 1; i <= m; i++) {
    mx = max(mx, doing[i].x);
    my = max(my, doing[i].y);
    mz = max(mz, doing[i].z);
  }
  if (mx <= n) {
    best = min(best, mx);
  }
  if (my <= n) {
    best = min(best, my);
  }
  if (mz <= n) {
    best = min(best, mz);
  }
  maxi = 0;
  for (i = m; i >= 1; i--) {
    solved = false;
    Smaller(doing[i].y, 0);
    Bigger(doing[i].y, root);
    if (doing[i].z > root->son[1]->val) {
      if (!root->son[1]->son[0]) {
        memory[++vs] = Type(root->son[1], doing[i].y, doing[i].z, 1);
        current = root->son[1]->son[0] = &memory[vs];
        Update(root->son[1]);
        Update(root);
      } else {
        solved = true;
        if (root->son[1]->son[0]->val < doing[i].z) {
          current = root->son[1]->son[0];
          Splay(current, 0);
          delta = doing[i].z;
          if (doing[i].z == n + 1) {
            delta = 666666;
          }
          delta -= current->val;
          if (current->son[0]->size == 1) {
            Add(1, 1, n, 1, n, delta);
          } else {
            Find_Right(current->son[0]);
            Add(1, 1, n, root->pos, n, delta);
          }
          if (doing[i].z <= n) {
            current->val = doing[i].z;
          } else {
            current->val = 666666;
          }
        }
      }
    } else {
      current = 0;
      solved = true;
    }
    if (current) {
      Splay(current, 0);
      if (current->val == n + 1) {
        current->val = 666666;
      }
      if (!solved) {
        delta = current->val;
        if (current->son[0]->size == 1) {
          Find_Left(current->son[1]);
          delta -= root->val;
          if (root->val < current->val) {
            Add(1, 1, n, 1, current->pos - 1, delta);
          }
        } else {
          Find_Left(current->son[1]);
          delta -= root->val;
          if (root->val < current->val) {
            Splay(current, 0);
            Find_Right(current->son[0]);
            Add(1, 1, n, root->pos, current->pos - 1, delta);
          }
        }
      }
      while (true) {
        Splay(current, 0);
        rank = current->son[0]->size + 1;
        if (rank == 2) {
          break;
        }
        Find(rank - 1, 0);
        if (root->val > current->val) {
          break;
        }
        delta = current->val - root->val;
        last = root->pos - 1;
        if (rank == 3) {
          Add(1, 1, n, 1, last, delta);
        } else {
          Find(rank - 2, 0);
          Add(1, 1, n, root->pos, last, delta);
        }
        Find(rank - 2, 0);
        Find(rank, root);
        root->son[1]->son[0] = 0;
        Update(root->son[1]);
        Update(root);
      }
    }
    maxi = max(maxi, doing[i].z);
    if (doing[i - 1].x <= n) {
      best = min(best, doing[i - 1].x + Ask(1, 1, n, 1, n));
      if (maxi <= n) {
        best = min(best, doing[i - 1].x + maxi);
      }
    }
  }
  printf("%d\n", best);
  return 0;
}
