#include <bits/stdc++.h>
using namespace std;
struct neighbours {
  char face;
  char mas[4];
};
struct answer {
  neighbours mas[6];
};
vector<answer> answers;
answer currentAnswer;
char colors[6];
char faces[6];
bool used[6];
int matrix[6][4];
void mySort(char mas[4]) {
  char var[4];
  for (int i = 0; i < 4; i++) var[i] = mas[i];
  for (int i = 0; i < 4; i++) {
    char tmp = mas[0];
    for (int j = 0; j < 4; j++) mas[j] = mas[j + 1];
    mas[3] = tmp;
    for (int j = 0; j < 4; j++)
      if (mas[j] < var[j]) {
        for (int k = 0; k < 4; k++) var[k] = mas[k];
        break;
      } else if (mas[j] > var[j])
        break;
  }
  for (int i = 0; i < 4; i++) mas[i] = var[i];
}
void createAnswer() {
  for (int i = 0; i < 6; i++) {
    currentAnswer.mas[i].face = faces[i];
    int _count = 0;
    for (int j = 0; j < 4; j++) {
      currentAnswer.mas[i].mas[_count] = faces[matrix[i][j]];
      _count++;
    }
    mySort(currentAnswer.mas[i].mas);
  }
}
bool same(int ind) {
  bool watched[6];
  for (int i = 0; i < 6; i++) watched[i] = 0;
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      if (!watched[j] &&
          answers[ind].mas[i].face == currentAnswer.mas[j].face) {
        bool flag = true;
        for (int k = 0; k < 4; k++)
          if (answers[ind].mas[i].mas[k] != currentAnswer.mas[j].mas[k]) {
            flag = false;
            break;
          }
        if (flag) watched[j] = true;
      }
  for (int i = 0; i < 6; i++)
    if (!watched[i]) return false;
  return true;
}
bool check() {
  for (int i = 0; i < answers.size(); i++)
    if (same(i)) return 0;
  return 1;
}
void addAnswer() { answers.push_back(currentAnswer); }
void solve(int p) {
  if (p == 6) {
    createAnswer();
    if (check()) addAnswer();
    return;
  }
  for (int i = 0; i < 6; i++)
    if (!used[i]) {
      faces[p] = colors[i];
      used[i] = 1;
      solve(p + 1);
      used[i] = 0;
    }
}
int main() {
  matrix[0][0] = 1;
  matrix[0][1] = 2;
  matrix[0][2] = 3;
  matrix[0][3] = 4;
  matrix[1][0] = 0;
  matrix[1][1] = 4;
  matrix[1][2] = 5;
  matrix[1][3] = 2;
  matrix[2][0] = 0;
  matrix[2][1] = 1;
  matrix[2][2] = 5;
  matrix[2][3] = 3;
  matrix[3][0] = 0;
  matrix[3][1] = 2;
  matrix[3][2] = 5;
  matrix[3][3] = 4;
  matrix[4][0] = 1;
  matrix[4][1] = 0;
  matrix[4][2] = 3;
  matrix[4][3] = 5;
  matrix[5][0] = 4;
  matrix[5][1] = 3;
  matrix[5][2] = 2;
  matrix[5][3] = 1;
  for (int i = 0; i < 6; i++) cin >> colors[i];
  solve(0);
  cout << answers.size();
  return 0;
}
