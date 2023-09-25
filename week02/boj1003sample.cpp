#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/**
 * f0 = 1
 * f1 = 1
 * f2 = f0 + f1 = 1 + 1 = 2
 * f3 + f2 + f1 = (f1 + f0) + f1
 * f4 = f3 + f2 = (f1 + f0) + f1 + f0 + f1
 */

// dp[0][i], f(i)호출했을때 0의 개수
// dp[1][i], f(i)호출했을때 1의 개수
int dp[2][41];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  dp[0][0] = 1;
  dp[0][1] = 0;
  dp[1][0] = 0;
  dp[1][1] = 1;

  int N;
  cin >> N;
  for (int i = 2; i <= N; i++) {
    dp[0][i] = dp[0][i - 1] +
               dp[0][i - 2];  // 값을 함수로 처음 계산하느 ㄴ것이 아니라, 함수의
                              // 리턴값을 배열에 저장하고, 그냥 알고 쓰자
    dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
  }
  cout << dp[0][N] << ' ' << dp[1][N];

  return 0;
}