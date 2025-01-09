#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool isSafeReport(const std::vector<int> &report) {
  bool increasing = report[1] > report[0];
  for (size_t i = 0; i < (report.size() - 1); ++i) {
    int diff = report[i + 1] - report[i];
    bool unsafe = ((increasing && (diff < 1 || diff > 3)) ||
                   (!increasing && (diff < -3 || diff > -1)));
    if (unsafe) return false;
  }
  return true;
}

int main() {
  std::vector<std::vector<int>> reports{};

  std::string line{};
  while (std::getline(std::cin, line)) {
    std::stringstream ss{line};

    std::vector<int> report{};
    for (int x; ss >> x;) {
      report.push_back(x);
    }

    reports.emplace_back(std::move(report));
  }

  size_t num_safe_reports = 0;
  for (const auto &report : reports) {
    if (isSafeReport(report)) {
      num_safe_reports++;
    }
  }

  std::cout << num_safe_reports << std::endl;
}