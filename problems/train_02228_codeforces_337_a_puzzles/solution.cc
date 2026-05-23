#include <bits/stdc++.h>
using namespace std;
int main() {
  int student, puzzles;
  cin >> student >> puzzles;
  int arr[puzzles], answer[puzzles];
  int i = puzzles;
  while (i--) cin >> arr[i];
  for (int i = 0; i < puzzles; i++) {
    for (int j = i + 1; j < puzzles; j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  int smallest = 0;
  for (int i = 0; i <= puzzles - student; i++) {
    if (i == 0)
      smallest = arr[student + i - 1] - arr[i];
    else if (arr[student + i - 1] - arr[i] < smallest)
      smallest = arr[student + i - 1] - arr[i];
  }
  cout << smallest;
  return 0;
}
