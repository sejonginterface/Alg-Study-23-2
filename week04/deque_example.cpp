#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

deque<int> dq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  string cmd;
  dq.clear();
  while (1) {
    cin >> cmd;

    if (cmd.compare("popf")) {
      dq.pop_front();
      for (auto i : dq) {
        cout << i << ' ';
      }
      cout << '\n';
    }
    if (cmd.compare("popb")) {
      dq.pop_back();
      for (auto i : dq) {
        cout << i << ' ';
      }
      cout << '\n';
    }
    if (cmd.compare("pushf")) {
      cin >> n;
      dq.push_front(n);
      for (auto i : dq) {
        cout << i << ' ';
      }
      cout << '\n';
    }
    if (cmd.compare("pushb")) {
      cin >> n;
      dq.push_back(n);
      for (auto i : dq) {
        cout << i << ' ';
      }
      cout << '\n';
    }
  }

  return 0;
}