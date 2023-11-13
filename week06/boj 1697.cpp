#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef struct node {
  int num;
  int level;
} Node;

int N, K;
int visited[100000];  // 범위가 100000

deque<Node> dq;

void printDQ() {
  cout << "=========dq============\n";
  for (auto &&i : dq) {
    cout << "node " << i.num << ": " << i.level << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  dq.push_back({N, 0});
  visited[N] = 1;

  while (!dq.empty()) {
    Node curr = dq.front();  // 큐의 가장 앞에 있는 값을 현재 노드로 갱신

    dq.pop_front();  // 큐 가장 앞에 있는 노드 제거
    cout << "!!curr node " << curr.num << ": " << curr.level << "!!\n";

    if (curr.num == K) {
      cout << curr.level;
      return 0;
    }

    Node next;

    next.level = curr.level + 1;

    next.num = curr.num - 1;  // 현재 위치 -1 위치로 X-1
    if (visited[next.num] == 0 && next.num > 0 && next.num <= 100000) {
      dq.push_back(next);     // 큐에 추가
      visited[next.num] = 1;  // 방문표시
    }

    next.num = curr.num + 1;  // 현재위치 + 1위치로 X+1
    if (visited[next.num] == 0 && next.num > 0 && next.num <= 100000) {
      dq.push_back(next);     // 큐에 추가
      visited[next.num] = 1;  // 방문표시
    }

    next.num = curr.num * 2;  // 현재위치 * 2. X*2;
    if (visited[next.num] == 0 && next.num > 0 && next.num <= 100000) {
      dq.push_back(next);     // 큐에 추가
      visited[next.num] = 1;  // 방문표시
    }

    // printDQ();
  }

  return 0;
}