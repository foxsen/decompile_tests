#include <bits/stdc++.h>
int nums[100000] = {0};
int main() {
  int n = 0;
  std::cin >> n;
  std::unordered_map<int, std::vector<int> > nhz(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> nums[i];
    nhz[nums[i]].push_back(i);
  }
  int index = 0;
  for (int i = 0, next = 0; i < n; i = next) {
    std::unordered_map<int, std::vector<int> >::const_iterator it =
        nhz.find(nums[i]);
    const std::vector<int>& vec = it->second;
    int size = vec.size();
    bool findFlag = false;
    for (int j = 0; j < size; ++j) {
      if (vec[j] <= i) continue;
      int start = i;
      int end = vec[j];
      int subSize = end - start;
      if (subSize > n - end) break;
      bool flag = true;
      for (int z = 1; z < subSize; ++z) {
        if (nums[start + z] != nums[end + z]) {
          flag = false;
          break;
        }
      }
      if (!flag) continue;
      index = end;
      findFlag = true;
      break;
    }
    if (findFlag)
      next = index;
    else
      ++next;
  }
  int retSize = n - index;
  std::cout << retSize << std::endl;
  std::cout << nums[index];
  for (int i = index + 1; i < n; ++i) std::cout << " " << nums[i];
  return 0;
}
