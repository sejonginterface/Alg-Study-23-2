#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/*

1 x
2 x
3 1
4 4 - 3 1 x << x애 불가능하다. 이걸 어떻게 표현할것인가?
5 1
6 3 + 3 2
7 4+3 2+5 x
8 5+3 3+5 2
N -3, -5 한 단계 중에서 작은걸 고르고 다음단계(+1)을 해주자.!


 */

int dp[5001];
int N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i <= N; i++) {
    dp[i] = 5000;
  }
  dp[3] = 1;
  dp[5] = 1;

  for (int i = 5; i <= N; i++) {
    dp[i] = min(dp[i - 3], dp[i - 5]) + 1;
  }

  /* dp[3] = 1 dp[1] = 5000 */
  if (dp[N] >= 5000) {
    cout << -1;
  } else {
    cout << dp[N];
  }

  return 0;
}