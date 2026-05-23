#include <bits/stdc++.h>
std::ifstream fin("input.txt");
std::ofstream fout("output.txt");
int n, value;
int x[200005], a[200005], freq[105];
bool foundSolution;
void readInput() {
  std::cin >> n;
  for (int i = 0; i < n; i++) std::cin >> x[i];
}
bool sortCond(std::pair<int, int> a, std::pair<int, int> b) {
  return a.first > b.first;
}
void findMostFrequent() {
  for (int i = 0; i < n; i++) freq[x[i]]++;
  std::vector<std::pair<int, int>> v;
  for (int i = 1; i <= 100; i++) {
    if (freq[i] > 0) v.push_back({freq[i], i});
  }
  std::sort(v.begin(), v.end(), sortCond);
  if (v.size() >= 2 and v[0].first == v[1].first) {
    std::cout << n << '\n';
    foundSolution = true;
    return;
  } else
    value = v[0].second;
}
int findLenght(int val1, int val2) {
  for (int i = 0; i < n; i++) {
    if (x[i] == val1)
      a[i] = 1;
    else if (x[i] == val2)
      a[i] = -1;
    else
      a[i] = 0;
  }
  std::unordered_map<int, int> first;
  first[0] = -1;
  if (a[0] != 0) first[a[0]] = 0;
  int max = 0;
  for (int i = 1; i < n; i++) {
    a[i] += a[i - 1];
    if (first.find(a[i]) != first.end())
      max = std::max(max, i - first[a[i]]);
    else
      first[a[i]] = i;
  }
  return max;
}
bool ok[105];
void solve() {
  int answer = 0;
  for (int i = 0; i < n; i++) {
    if (x[i] == value or ok[x[i]] == true) continue;
    ok[x[i]] = true;
    answer = std::max(answer, findLenght(value, x[i]));
  }
  std::cout << answer << '\n';
}
int main() {
  readInput();
  findMostFrequent();
  if (foundSolution == false) {
    solve();
  }
  return 0;
}
