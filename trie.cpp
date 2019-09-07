#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> &patterns) {
  trie t(1);
  int current_node;
  for (const auto &pattern : patterns) {
    current_node = 0;
    for (const auto &current_symbol : pattern) {
      if (t[current_node].find(current_symbol) != t[current_node].end()) {
        current_node = t[current_node][current_symbol];
      } else {
        t.resize(t.size() + 1);
        int temp = (int)t.size() - 1;
        t[current_node][current_symbol] = temp;
        current_node = temp;
      }
    }
  }
  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto &j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}
