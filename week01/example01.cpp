#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int N;
char board[64][64];  // 띄어쓰기 없이 들어오는 입력이므로
                     // char형으로 한 글자씩 입력받는 것이 매우 유리함

int main() {
  /* 궁금하신 분들은 찾아 보시면 좋습니다
   * printf, scanf와 같은 c의 stdio와 stream동기화 해제하는 코드
   * cin, cout간의 순서 연결을 해제시키는 코드
   */
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  return 0;
}