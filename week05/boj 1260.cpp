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

// 인접 리스트
// vector<int> adj[1001];  // 1000 + 1이유는 인덱스랑 번호를 맞추기 위해서

int adj[1001][1001];  // 해당 배열을 사용하여

// 방문여부 배열
int visited[1001];  // 전역이라서 자동으로 0으로 초기회 false

deque<Node> dq;  // bfs사용될 덱

int N, M, V;  // 입력정보

void bfs(Node curr) {
  // 종료 조건이 따로 없음

  dq.push_back(curr);
  visited[curr.num] = 1;

  while (!dq.empty()) {
    // 2번단계, dq의 가장 앞의 있는 노드를 현재노드로 갱신
    Node curr = dq.front();
    dq.pop_front();  // 갱신후 삭제
    cout << "curr :" << curr.num << " level: " << curr.level << '\n';

    /* 1번단계 수정하기 */

    // 1번단계, 인접한 모든 노드를 dq에 추가
    for (auto it : adj[curr.num]) {  // iter for문 사용법, for range 라고도 함
      if (visited[it] == 0) {        // 유효한
        dq.push_back({it, curr.level + 1});
        visited[it] = 1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> V;

  int from, to;
  for (int i = 0; i < M; i++) {
    cin >> from >> to;
    adj[from][to] = 1;
    adj[to][from] = 1;
  }

  bfs({V, 0});

  return 0;
}