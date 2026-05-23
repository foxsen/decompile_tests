#include <bits/stdc++.h>
using namespace std;
pair<int, int> mirror(pair<int, int> &p) { return {p.second, p.first}; }
void move_from_first_two_sets_to_other_two(set<pair<int, int>> &set1_1,
                                           set<pair<int, int>> &set1_2,
                                           set<pair<int, int>> &set2_1,
                                           set<pair<int, int>> &set2_2,
                                           pair<int, int> item) {
  set1_1.erase(item);
  set1_2.erase(mirror(item));
  set2_1.insert(item);
  set2_2.insert(mirror(item));
}
int split(set<pair<int, int>> &byX, set<pair<int, int>> &byY) {
  if (byX.size() == 1) return 1;
  auto x_forward = byX.begin();
  auto x_backward = byX.rbegin();
  auto y_forward = byY.begin();
  auto y_backward = byY.rbegin();
  set<pair<int, int>> byX2, byY2;
  do {
    int x_prev = x_forward->first;
    x_forward++;
    if (abs(x_forward->first - x_prev) > 1) {
      while (byX.begin()->first <= x_prev) {
        move_from_first_two_sets_to_other_two(byX, byY, byX2, byY2,
                                              *byX.begin());
      }
      return split(byX, byY) + split(byX2, byY2);
    }
    x_prev = x_backward->first;
    x_backward++;
    if (abs(x_backward->first - x_prev) > 1) {
      while (byX.rbegin()->first >= x_prev) {
        move_from_first_two_sets_to_other_two(byX, byY, byX2, byY2,
                                              *byX.rbegin());
      }
      return split(byX, byY) + split(byX2, byY2);
    }
    int y_prev = y_forward->first;
    y_forward++;
    if (abs(y_forward->first - y_prev) > 1) {
      while (byY.begin()->first <= y_prev) {
        move_from_first_two_sets_to_other_two(byY, byX, byY2, byX2,
                                              *byY.begin());
      }
      return split(byX, byY) + split(byX2, byY2);
    }
    y_prev = y_backward->first;
    y_backward++;
    if (abs(y_backward->first - y_prev) > 1) {
      while (byY.rbegin()->first >= y_prev) {
        move_from_first_two_sets_to_other_two(byY, byX, byY2, byX2,
                                              *byY.rbegin());
      }
      return split(byX, byY) + split(byX2, byY2);
    }
  } while (*x_forward < *x_backward);
  return 1;
}
int main() {
  int n;
  cin >> n;
  set<pair<int, int>> byX, byY;
  while (n-- > 0) {
    int x;
    cin >> x;
    int y;
    cin >> y;
    byX.insert({x, y});
    byY.insert({y, x});
  }
  cout << split(byX, byY);
}
