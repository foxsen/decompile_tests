#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
vector<int> input(int n) {
  vector<int> result(n);
  for (int i = 0; i < n; ++i) cin >> result[i];
  return result;
}
double maxVolume(const vector<int>& wanted, const vector<int>& existing,
                 int V) {
  int sum = 0;
  for (int i = 0; i < wanted.size(); ++i) sum += wanted[i];
  double minRelation = 100;
  for (int i = 0; i < wanted.size(); ++i)
    minRelation = std::min(minRelation, (double)existing[i] / wanted[i]);
  double maxSoup = sum * minRelation;
  return (maxSoup <= V) ? maxSoup : V;
}
int main() {
  int n, V;
  cin >> n >> V;
  vector<int> wanted = input(n);
  vector<int> existing = input(n);
  double result = maxVolume(wanted, existing, V);
  printf("%lf\n", result);
  return 0;
}
