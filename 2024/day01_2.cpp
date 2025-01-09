#include <iostream>
#include <unordered_map>
#include <vector>

int calcSimilarity(const std::vector<int>& left_list,
                   const std::vector<int>& right_list) {
  std::unordered_map<int, int> right_freq{};
  for (int x : right_list) {
    right_freq[x]++;
  }

  int similarity = 0;
  for (int x : left_list) {
    if (!right_freq.contains(x)) {
      continue;
    }
    similarity += (x * right_freq[x]);
  }
  return similarity;
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

  std::cout << calcSimilarity(left_list, right_list) << std::endl;
}
