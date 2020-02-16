#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  int n, max, max_count;
  max = -1;
  max_count = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] > max) {
      max = a[i];
    }
  }

  int count = 0;
  int idx;
  int first = -1;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == max) {
      ++count;
      if (count == 1 || count == 3) {
        idx = i;
      }
    }
  }

  for (int i = 0; i < a.size(); ++i) {
    if (i == idx) {
      continue;
    }
    if (i != 0 && first != -1) {
      cout << " ";
    }
    cout << a[i];
    if (first == -1) {
      first = 1;
    }
    if (i == n - 1) {
      cout << endl;
    }
  }

  return 0;
}
