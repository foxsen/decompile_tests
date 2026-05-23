#include <bits/stdc++.h>
using namespace std;
bool find(vector<long long int> A, long long int B) {
  int start = 0, end = A.size() - 1, mid = (start + end) / 2;
  while (start <= end) {
    mid = (start + end) / 2;
    if (A[mid] > B) {
      end = mid - 1;
    } else if (A[mid] < B) {
      start = mid + 1;
    } else if (A[mid] == B) {
      return 1;
    }
  }
  return 0;
}
int ways(vector<long long int> A) {
  int i = A.size() - 1;
  long long int count = 0;
  while (i > 0) {
    long long int temp = A[i] / A[i - 1];
    count++;
    if (temp % 2 == 1 || find(A, temp)) {
      A.pop_back();
      i--;
    } else
      A[i] = temp;
  }
  return count;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    long long int val = 0;
    vector<long long int> A;
    map<long long int, vector<long long int>> B;
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      if (a % 2 == 0) {
        A.push_back(a);
        long long int temp = 0;
        while (a % 2 == 0) {
          a /= 2;
          temp++;
        }
        if (B.find(a) == B.end())
          B[a] = {temp};
        else
          B[a].push_back(temp);
      }
    }
    for (auto it = B.begin(); it != B.end(); it++) {
      vector<long long int> temp = it->second;
      sort(temp.begin(), temp.end());
      int j = 0;
      while (j < temp.size() - 1) {
        if (temp[j + 1] != temp[j]) val += (temp[j + 1] - temp[j]);
        j++;
      }
      val += temp[0];
    }
    cout << val << endl;
  }
  return 0;
}
