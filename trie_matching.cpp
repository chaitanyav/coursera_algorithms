#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int const Letters = 4;

struct Node {
  Node *children[Letters];
  Node() { fill(children, children + Letters, nullptr); }

  bool isLeaf() const {
    return (children[0] == nullptr && children[1] == nullptr &&
            children[2] == nullptr && children[3] == nullptr);
  }
};

int letterToIndex(char letter) {
  switch (letter) {
  case 'A':
    return 0;
    break;
  case 'C':
    return 1;
    break;
  case 'G':
    return 2;
    break;
  case 'T':
    return 3;
    break;
  default:
    assert(false);
    return -1;
  }
}

vector<int> solve(const string &text, int n, const vector<string> &patterns) {
  Node *root = new Node();
  Node *current_node = nullptr;
  vector<int> result;

  for (const string &pattern : patterns) {
    current_node = root;
    for (const char &c : pattern) {
      int idx = letterToIndex(c);
      if (current_node->children[idx] != nullptr) {
        current_node = current_node->children[idx];
      } else {
        Node *temp = new Node();
        current_node->children[idx] = temp;
        current_node = temp;
      }
    }
  }

  for (int i = 0; i < text.size(); i++) {
    int j = i;
    char c = text[j];
    current_node = root;
    string pat;
    while (true) {
      int idx = letterToIndex(c);
      if (current_node->children[idx] != nullptr) {
        pat.push_back(c);
        current_node = current_node->children[idx];
        j++;
        if (j < text.size()) {
          c = text[j];
        } else {
          break;
        }
      } else {
        break;
      }
    }
    if (!pat.empty() && current_node->isLeaf()) {
      result.push_back(i);
    }
  }

  delete root;
  root = nullptr;

  return result;
}

int main(void) {
  string text;
  cin >> text;

  int n;
  cin >> n;

  vector<string> patterns(n);
  for (int i = 0; i < n; i++) {
    cin >> patterns[i];
  }

  vector<int> ans;
  ans = solve(text, n, patterns);

  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i];
    if (i + 1 < (int)ans.size()) {
      cout << " ";
    } else {
      cout << endl;
    }
  }

  return 0;
}
