#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/**
 * 1칸짜리 까지 재귀함수로 내려간다
 *
 * 내려가는 과정에서 2 ^n * 2^n 사이즈가 전부 같은 색인지 확인
 * 전부 같은색이면 해당 색상 종이 개수 1증가
 * 다른 색이색이면 더 작은 종이로 확인하기
 */

/*


 /0/ 0. 0. 1!! 아래 4개 탐색이 호출
 1 1 1 1
1  1 1 1
1 1 1 1

---------
 r , c , 2
 0/ 0.
 1!! 1

0 bcnt++

0

1 wcnt ++

1


r , c + len/2 -> 시작위치
 0~ 1!
 1 1

0

1

1

1


==
r + len/2, c -> 시작위치
 1/ 1.
 1. 1.

 r + len/2, c 의 값이 1이네 ?

r + len/2 , c + len / 2 -> 시작위치
 1 1
 1 1


checkColor(0, 0, 4);

 */

int N;
int board[128][128];
int cntBlue = 0;
int cntWithe = 0;

void checkColor(int r, int c, int len) {
  /* 재귀 가장 작은 단계 도달했으때 탈출시키는 구문 */
  if (len == 1) {
    /* 보드색에 따라 개수증가 */
    if (board[r][c] == 1) cntBlue++;
    if (board[r][c] == 0) cntWithe++;
    return;
  }
  /* 반복위치 */
  for (int i = r; i < r + len; i++) {
    for (int j = c; j < c + len; j++) {
      if (board[r][c] != board[i][j]) {
        /* 더 작은 종이 탐색 */
        /* 시작위치를 4등분한 좌측상단 좌표 */
        /* 길이는 4등분 시켰을 때 한 변의 길이 */
        checkColor(r, c, len / 2);
        checkColor(r, c + len / 2, len / 2);
        checkColor(r + len / 2, c, len / 2);
        checkColor(r + len / 2, c + len / 2, len / 2);
        return;
      }
    }
  }
  /// 전부 패스를 해야 return 안 만 나서 아래도달
  if (board[r][c] == 1) cntBlue++;
  if (board[r][c] == 0) cntWithe++;
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
  checkColor(0, 0, N);

  cout << cntWithe << '\n' << cntBlue;

  return 0;
}