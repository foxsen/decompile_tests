#include <bits/stdc++.h>
using namespace std;
bool leap_year(int x) {
  if (x % 4 == 0 and x % 100 != 0 or x % 400 == 0) return true;
  return false;
}
int main() {
  int year1, month1, day1;
  int year2, month2, day2;
  scanf("%d:%d:%d", &year1, &month1, &day1);
  scanf("%d:%d:%d", &year2, &month2, &day2);
  int ans = 0;
  bool t = true;
  if (year1 > year2)
    t = false;
  else if (year1 == year2 and month1 > month2)
    t = false;
  else if (year1 == year2 and month1 == month2 and day1 > day2)
    t = false;
  if (!t) {
    int change;
    change = year2;
    year2 = year1;
    year1 = change;
    change = month2;
    month2 = month1;
    month1 = change;
    change = day2;
    day2 = day1;
    day1 = change;
  }
  for (int i = year1; i < year2; i++) {
    if (leap_year(i))
      ans += 366;
    else
      ans += 365;
  }
  int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (leap_year(year2) and month2 > 2) ans++;
  for (int i = 0; i < month2 - 1; i++) ans += month[i];
  ans += day2;
  if (leap_year(year1) and month1 > 2) ans--;
  for (int i = 0; i < month1 - 1; i++) ans -= month[i];
  ans -= day1;
  cout << ans;
  return 0;
}
