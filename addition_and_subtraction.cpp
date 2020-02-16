#include <iostream>
#include <vector>

int main() {
  int x, y, z;
  std::cin >> x >> y >> z;
  int result = -1;
  // std::cout << "Input was " << x << " " << y << " " << z << std::endl;

  int t, count;
  int p, q;
  count = 0;
  t = 0;
  if (z == t) {
    std::cout << 0 << std::endl;
    return 0;
  }
  while (true) {
    p = t + x;
    ++count;
    if (p == z) {
      result = count;
      break;
    }
    q = p - y;
    ++count;
    if (q == z) {
      result = count;
      break;
    }
    // std::cout << p << " " << q << " " << count << std::endl;
    t = q;
    if ((p == 0 || q == 0) || (p > z && q > z) || (p < 0 && q < 0)) {
      break;
    }
  }

  std::cout << result << std::endl;
  return 0;
}
