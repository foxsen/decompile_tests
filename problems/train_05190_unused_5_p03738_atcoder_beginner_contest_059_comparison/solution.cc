#include <iostream>
#include <string>
using namespace std;

int main() {
  string A, B;
  cin >> A >> B;

  if (A.size()==B.size()) {
    cout << (A>B ? "GREATER": A==B ? "EQUAL": "LESS");
  } else {
    cout << (A.size()>B.size() ? "GREATER": "LESS");
  }
}