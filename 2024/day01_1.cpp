#include <algorithm>
#include <iostream>
#include <vector>

int calcTotalDistance(const std::vector<int>& left_list,
                      const std::vector<int>& right_list) {
  int tot_dist = 0;
  for (size_t i = 0; i < left_list.size(); ++i) {
    tot_dist += abs(left_list[i] - right_list[i]);
  }
  return tot_dist;
}

int main() {
  std::vector<int> left_list{};
  std::vector<int> right_list{};

  int left_x, right_x;
  while (std::cin >> left_x) {
    std::cin >> right_x;
    left_list.push_back(left_x);
    right_list.push_back(right_x);
  }

  std::sort(left_list.begin(), left_list.end());
  std::sort(right_list.begin(), right_list.end());

  std::cout << calcTotalDistance(left_list, right_list) << std::endl;
}
