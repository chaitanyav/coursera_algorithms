#include <iostream>
#include <algorithm>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  int nine = std::count(std::rbegin(s), std::rend(s), '9');
  int len = s.length();
  if(nine == len) {
    std::cout << (len + 1) << std::endl;
  } else {
    std::cout << len << std::endl;
  }
  return 0;
}
