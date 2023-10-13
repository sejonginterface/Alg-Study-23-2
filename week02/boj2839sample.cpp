#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/**
 * N키로 배달, 배수는 아니다
 * N 개수
 * 3 1
 * 4 -1
 * 5 1
 * 6 2(1 + 1) <- 3 + 3
 * 7 -1
 * 8 2(1 + 1) <- 3 + 5
 * 9 3(2 + 1) <- 6 + 3
 * 10 2 <- 5 + 5
 * 11 3 <- 6 + 5
 *
 * N키로 짜리에 -3, -5 를 하는걸 반복해서 3, 5를 만들수 있는 N은 포장이
 * 가능하다. 개수는 몇번 뺴는가?
 *
 *
 * N = 15
 * 12 + 3, 10 + 5 두 경우중 최소값을 선택을 해야한다.
 * 12 : 4, 5
 * 10 : 2, 3
 */

int dp[5001]; // 인덱스값이랑 N값을 동일하게 사용가능 // 전역변수이므로
              // heap영역이서 기본값으로 0이 초기화가 됨.

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  for (int i = 0; i <= N; i++)
  {               // 배열값이 0으로 초기화되어서 이후에 min을
                  // 선택할떄 항상 0이 선택되니까
    dp[i] = 1700; // 그냥 큰값으로 처음부터 초기화
  }
  dp[3] = 1;
  dp[5] = 1;

  for (int i = 6; i <= N; i++)
  {
    // 완성 못시키는 배열 같은 경우에는 dp배열값이 0으로 되어있것
    dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
    // dp배열에 값을 기록, 저장, 메모이제이션
  }

  if (dp[N] >= 2000)
  { // 절대 제대로 포장될수 없는 값 위에 초기화한값이랑
    // 같아도 됨 대력 1700쯤
    cout << -1;
  }
  else
  {
    cout << dp[N];
  }

  return 0;
}