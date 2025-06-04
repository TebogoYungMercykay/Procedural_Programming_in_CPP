#include <algorithm>
#include <iostream>
#include <vector>

bool isOnSegment(long long studentX, long long studentY, long long laserX,
                 long long laserY);

int main() {
  // put your code here
  int n;
  std::cin >> n;
  std::string output = "";

  std::vector<std::pair<long long, long long>> students(n);
  for (int i = 0; i < n; i += 1) {
    std::cin >> students[i].first >> students[i].second;
  }

  int q;
  std::cin >> q;

  for (int i = 0; i < q; i += 1) {
    long long laserX, laserY;
    std::cin >> laserX >> laserY;

    int count = 0;
    for (const auto &student : students) {
      if (isOnSegment(student.first, student.second, laserX, laserY)) {
        count++;
      }
    }

    output += std::to_string(count) + '\n';
  }

  std::cout << output << std::endl;

  return 0;
}

bool isOnSegment(long long studentX, long long studentY, long long laserX,
                 long long laserY) {
  if (studentX * laserY != studentY * laserX) {
    return false;
  }

  bool inXRange = (laserX >= 0 && studentX >= 0 && studentX <= laserX) ||
                  (laserX <= 0 && studentX <= 0 && studentX >= laserX);
  bool inYRange = (laserY >= 0 && studentY >= 0 && studentY <= laserY) ||
                  (laserY <= 0 && studentY <= 0 && studentY >= laserY);

  return inXRange && inYRange;
}