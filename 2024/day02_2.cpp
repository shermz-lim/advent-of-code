#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::pair<bool,size_t> isSafeReport(const std::vector<int>& report) {
  bool increasing = report[1] > report[0];
  for (size_t i = 0; i < (report.size() - 1); ++i) {
    int diff = report[i + 1] - report[i];
    bool unsafe = (
      (increasing && (diff < 1 || diff > 3)) ||
      (!increasing && (diff < -3 || diff > -1))
    );
    if (unsafe) return {false, i};
  }
  return {true, 0};
}

bool isSafeReportWithDampen(const std::vector<int>& report) {
  auto [safe, idx] = isSafeReport(report);
  if (safe) return true;

  std::vector<int> report_alt1{};
  std::vector<int> report_alt2{};
  for (size_t i = 0; i < report.size(); ++i) {
    if (i != idx) {
      report_alt1.push_back(report[i]);
    }
    if (i != (idx + 1)) {
      report_alt2.push_back(report[i]);
    }
  }

  if (isSafeReport(report_alt1).first) return true;
  if (isSafeReport(report_alt2).first) return true;

  if (idx == 1) {
    std::vector<int> report_alt3{};
    for (size_t i = 1; i < report.size(); ++i)
      report_alt3.push_back(report[i]);
    if (isSafeReport(report_alt3).first) return true;
  }  

  return false;
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
  for (const auto& report : reports) {
    if (isSafeReportWithDampen(report)) {
      num_safe_reports++;
    }
  }

  std::cout << num_safe_reports << std::endl;
}